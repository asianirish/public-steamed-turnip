#include "Reader.h"

#include <csignal>
#include <iostream>
#include <unistd.h>
#include <termios.h>
#include <fstream>

namespace turnip {
namespace console {

// Declare a volatile sig_atomic_t flag to indicate if the read loop should be interrupted
volatile sig_atomic_t stopReading = 0;

// Function to set terminal mode to raw
void setRawMode(bool enable) {
    static struct termios oldt, newt;

    if (enable) {
        tcgetattr(STDIN_FILENO, &oldt); // save old settings
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO); // disable canonical mode and echo
        tcsetattr(STDIN_FILENO, TCSANOW, &newt); // apply new settings
    } else {
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // restore old settings
    }
}

// Signal handler function
void handleSigint(int signal) {
    if (signal == SIGINT) {
        if (stopReading == 0) {
            std::cout << "\ngoodbye\n";
        }
        stopReading = 1; // Set the flag to indicate an interruption request
    }
}

Reader::Reader(const std::string &readerName, const std::list<std::string> &command_list) : history_(1024), // TODO: const or from settings
    historyIndex_(0),
    commandList_(command_list),
    name_(readerName)
{}

void Reader::read()
{
    if (isMain()) {
        // Set the signal handler for SIGINT
        std::signal(SIGINT, handleSigint);
        setRawMode(true);
    }

    readHistory();

    std::string command;
    size_t cursor_position = 0; // Initialize cursor position at the start

    displayPrompt();

    while (!stopReading) {
        char buf[3];
        int n = ::read(STDIN_FILENO, buf, 3);

        if (n == 1) {
            // Single character input
            if (buf[0] == '\t') {
                onTabKey(cursor_position, command);
            } else if (buf[0] == '\n' || buf[0] == '\r') {
                bool stop = false;
                onEnterKey(cursor_position, command, stop);
                if (stop) {
                    break;
                }
            } else if(buf[0] == '\x7f' || buf[0] == '\x08') {
                // Handle backspace key (ASCII 127 or 8)
                if (cursor_position > 0) {
                    onBackspaceKey(cursor_position, command);
                }
            } else {
                onInsertCharacter(buf[0], cursor_position, command);
            }
        } else if (n == 3 && buf[0] == '\x1b' && buf[1] == '[') {
            // Two character escape sequence from arrow keys
            switch (buf[2]) {
            case 'A':
                onUpArrowKey(cursor_position, command);
                break;
            case 'B':
                onDownArrowKey(cursor_position, command);
                break;
            case 'C':
                if (cursor_position < command.size()) {
                    onRightArrowKey(cursor_position);
                }
                break;
            case 'D':
                if (cursor_position > 0) {
                    onLeftArrowKey(cursor_position);
                }
                break;

            case '3': // Potential start of a DEL key sequence
                if (::read(STDIN_FILENO, buf, 1) == 1 && buf[0] == '~') {
                    // Handle DEL key
                    if (cursor_position < command.size()) {
                        onDeleteKey(cursor_position, command);
                    }
                }
            }
        }
    }

    writeHistory();

    if (isMain()) {
        setRawMode(false);
    }
}

void Reader::onTabKey(std::size_t &cursor_position, std::string &command) const
{
    // TODO: obtain a command from a limited stack

    auto command_temp = findStringWithPrefix(command);

    if (!command_temp.empty()) {

        // Clear the current line
        std::cout << "\x1b[2K"; // Clear entire line
        std::cout << "\x1b[1G"; // Move cursor to the beginning of the line

        displayPrompt();

        command = command_temp;
        std::cout << command << std::flush;
        cursor_position = command.size();
    }
}

void Reader::onEnterKey(std::size_t &cursor_position, std::string &command, bool &stop) const
{
    // Move cursor to the end if not already
    if (cursor_position < command.size()) {
        size_t move_forward = command.size() - cursor_position;
        std::cout << "\x1b[" << move_forward << "C" << std::flush;
        cursor_position = command.size();
    }

    std::cout << " " << std::endl;

    if (command.empty()) {
        displayPrompt();
        return;
    }

    if (command == "exit") {
        stop = true;

        writeHistory();

        if (isMain()) {
            setRawMode(false);
        }

        exit(0);
        return;
    } else if (command == "quit") {
        stop = true;
    }else if (command == "menu") {
        std::cout << "Available commands: " << std::endl;
        std::cout << "(For more information, enter: `help <command name>`)" << std::endl << std::endl;

        displayMenu();
        displayPrompt();
    } else {
        if (history_.empty() || history_.back() != command) {
            history_.push(command);
        }

        stop = false;
        callback_(command);
    }
    command.clear();
    cursor_position = 0; // Reset cursor position
    if (history_.size()) {
        historyIndex_ = history_.size();
    } else {
        historyIndex_ = 0;
    }
}

void Reader::onBackspaceKey(std::size_t &cursor_position, std::string &command) const
{
    command.erase(cursor_position - 1, 1);
    cursor_position--;
    // Update the terminal display:
    // 1. Move the cursor back one position
    // 2. Overwrite the character with a space
    // 3. Move the cursor back again
    std::cout << "\x1b[D \x1b[D" << std::flush;

    // If the cursor is not at the end, you need to rewrite the remaining part of the string
    // and reposition the cursor accordingly
    if (cursor_position < command.size()) {
        std::cout << command.substr(cursor_position) << " " << std::flush;
        // Move the cursor back to the correct position
        size_t chars_to_move_back = command.size() - cursor_position + 1;
        if (chars_to_move_back > 0) {
            std::cout << "\x1b[" << chars_to_move_back << "D" << std::flush;
        }
    }
}

void Reader::onInsertCharacter(char character, std::size_t &cursor_position, std::string &command) const
{
    // Insert the character at the current cursor position
    command.insert(cursor_position, 1, character);

    // Print the inserted character
    std::cout << character << std::flush;

    // Print the remaining characters after the inserted character
    if (cursor_position + 1 < command.size()) {
        std::cout << command.substr(cursor_position + 1) << std::flush;

        // Move the cursor back to just after the inserted character
        size_t remaining_chars = command.size() - (cursor_position + 1);
        if (remaining_chars > 0) {
            std::cout << "\x1b[" << remaining_chars << "D" << std::flush;
        }
    }

    // Update the cursor position
    cursor_position++;
}

void Reader::onRightArrowKey(std::size_t &cursor_position) const
{
    std::cout << "\x1b[C" << std::flush; // Move cursor forward
    cursor_position++;
}

void Reader::onLeftArrowKey(std::size_t &cursor_position) const
{
    std::cout << "\x1b[D" << std::flush; // Move cursor back
    cursor_position--;
}

void Reader::onDeleteKey(std::size_t &cursor_position, std::string &command) const
{
    command.erase(cursor_position, 1);
    // Update the terminal display:
    std::cout << command.substr(cursor_position) << " " << std::flush;
    // Move the cursor back to the correct position
    size_t chars_to_move_back = command.size() - cursor_position + 1;
    if (chars_to_move_back > 0) {
        std::cout << "\x1b[" << chars_to_move_back << "D" << std::flush;
    }
}

void Reader::onUpArrowKey(std::size_t &cursor_position, std::string &command)
{
    if (!history_.empty() && historyIndex_ <= history_.size()) {
        // Clear the current line
        std::cout << "\x1b[2K"; // Clear entire line
        std::cout << "\x1b[1G"; // Move cursor to the beginning of the line
        displayPrompt();

        if (historyIndex_) {
            historyIndex_--;
        }

        command = history_.at(historyIndex_);
        cursor_position = command.size();
        std::cout << command << std::flush;
    }
}

void Reader::onDownArrowKey(std::size_t &cursor_position, std::string &command)
{
    // Clear the current line
    std::cout << "\x1b[2K"; // Clear entire line
    std::cout << "\x1b[1G"; // Move cursor to the beginning of the line
    displayPrompt();

    if (!history_.empty() && historyIndex_ < history_.size()) {

        historyIndex_++;

        if (historyIndex_ >= history_.size()) {
            historyIndex_ = history_.size() - 1;
            command.clear();
            std::cout << command << std::flush;
            cursor_position = 0;
            return;
        }

        command = history_.at(historyIndex_);
        cursor_position = command.size();
        std::cout << command << std::flush;
    }
}

void Reader::onResult(const std::string &resultString)
{
    std::cout << "\nResult: " << resultString << std::endl << std::endl;
    displayPrompt();
}

void Reader::onError(const std::string &errorString)
{
    std::cout << "\nError: " << errorString << std::endl;
    displayPrompt();
}

void Reader::onTaskStart(const cmd::TaskId &taskId)
{
    std::cout << "\nStart: " << taskId << std::endl;
    displayPrompt();
}

std::string Reader::findStringWithPrefix(const std::string &prefix) const
{
    if (prefix.empty()) {
        return {};
    }

    for (const auto& cmd : commandList_) {
        if (cmd.find(prefix) == 0) { // Check if 'str' starts with 'prefix'
            return cmd;
        }
    }
    return {}; // Return empty string if no match is found
}

void Reader::displayMenu() const
{
    for (auto &command : commandList_) {
        std::cout << command << std::endl;
    }

    std::cout << std::endl;
    std::cout << "menu" << std::endl;
    std::cout << "quit" << std::endl;
    std::cout << "exit" << std::endl;
    std::cout << std::endl;
}

void Reader::writeHistory() const
{
    // Open the file in write mode
    std::ofstream file(historyFileName_);

    // Check if the file is open
    if (!file.is_open()) {
        return /*false*/;
    }

    // Write each string in the list to the file on a new line
    for (const auto &str : history_) {
        file << str << std::endl;
    }

    // Close the file
    file.close();

    return /*true*/;
}

void Reader::readHistory()
{
    // Open the file in read mode
    std::ifstream file(historyFileName_);

    // Check if the file is open
    if (!file.is_open()) {
        return /*false*/;
    }

    std::string line;
    // Read the file line by line
    while (std::getline(file, line)) {
        history_.push(line); // Add each line to the list
    }

    // Close the file
    file.close();
    historyIndex_ = history_.size(); // the previous one will be size() - 1 (the last one)

    return /*true*/;
}

bool Reader::isMain() const
{
    return isMain_;
}

void Reader::setIsMain(bool newIsMain)
{
    isMain_ = newIsMain;
}

std::string Reader::historyFileName() const
{
    return historyFileName_;
}

void Reader::setHistoryFileName(const std::string &newHistoryFileName)
{
    historyFileName_ = newHistoryFileName;
}

void Reader::setCallback(const Callback &newCallback)
{
    callback_ = newCallback;
}

} // namespace console
} // namespace turnip
