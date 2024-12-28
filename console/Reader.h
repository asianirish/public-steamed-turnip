#ifndef READER_H
#define READER_H

#include "cmd/Types.h"
#include "common/LimitedStack.h"

#include <functional>
#include <string>
#include <list>

namespace turnip {
namespace console {

class Reader
{
public:
    // Define the type for subscriber callable objects
    using Callback = std::function<void(const std::string&)>;

    Reader(const std::string &readerName, const std::list<std::string> &command_list);

    void read();

    void setCallback(const Callback &newCallback);

    void onResult(const std::string &resultString);
    void onError(const std::string &errorString);
    void onTaskStart(const cmd::TaskId &taskId);

    std::string historyFileName() const;
    void setHistoryFileName(const std::string &newHistoryFileName);

    bool isMain() const;
    void setIsMain(bool newIsMain);

private:
    void onTabKey(std::size_t &cursor_position, std::string &command) const;
    void onEnterKey(std::size_t &cursor_position, std::string &command, bool &stop) const;
    void onBackspaceKey(std::size_t &cursor_position, std::string &command) const;
    void onInsertCharacter(char character, std::size_t &cursor_position, std::string &command) const;
    void onRightArrowKey(std::size_t &cursor_position) const;
    void onLeftArrowKey(std::size_t &cursor_position) const;
    void onDeleteKey(std::size_t &cursor_position, std::string &command) const;
    void onUpArrowKey(std::size_t &cursor_position, std::string &command);
    void onDownArrowKey(std::size_t &cursor_position, std::string &command);

    // Function to display the terminal prompt
    void displayPrompt() const {
        std::cout << name_ << " > " << std::flush;
    }

    // Method to find a string that starts with the given prefix
    std::string findStringWithPrefix(const std::string& prefix) const;

    void displayMenu() const;

    void writeHistory() const;
    void readHistory();

private:
    mutable common::LimitedStack<std::string> history_;
    mutable size_t historyIndex_;

    const std::list<std::string> &commandList_;

    Callback callback_;

    std::string historyFileName_ {".command_history"};

    std::string name_;

    bool isMain_ {true};
};

} // namespace console
} // namespace turnip

#endif // READER_H
