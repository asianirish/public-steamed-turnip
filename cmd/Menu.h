#ifndef MENU_H
#define MENU_H

#include "cmd/TaskManager.h"
#include "cmd/Types.h"
#include "cmd/Value.h"
#include "cmd/Translator.h"
#include "cmd/def/ActionDef.h"
#include "cmd/err/Error.h"

#include <map>
#include <string>
#include <list>

namespace turnip {
namespace cmd {

class Menu
{
public:
    using ResultCallback = std::function<void(const std::string&)>;
    using ErrorCallback = std::function<void(const std::string&)>;
    using StartCallback = std::function<void(const TaskId &)>;

    Menu();

    LazyAction registerAction(const std::string &commandName, const Value &actionInfo);

    void registerHelpAction();

    const std::list<std::string>  &commandList() const;

    void processString(const std::string &input);

    // Function to execute the action in a separate thread
    void executeAction(const std::string &command, const InputArgList& args);

    std::shared_ptr<Translator> translator() const;
    void setTranslator(const std::shared_ptr<Translator> &newTranslator);

    TaskManager taskManager() const;

    void setResultCallback(const ResultCallback &newResultCallback);

    void setErrorCallback(const ErrorCallback &newErrorCallback);

    def::ActionDef actionDef(const std::string &command) const;

    std::string name() const;
    void setName(const std::string &newMenuName);

    void setStartCallback(const StartCallback &newStartCallback);

private:
    mutable std::list<std::string> commandList_;

    std::map<std::string, LazyAction> actions_;

    TaskManager taskManager_;

    std::shared_ptr<Translator> translator_;

    ResultCallback resultCallback_;
    ErrorCallback errorCallback_;
    StartCallback startCallback_;

    LazyAction helpAction_;

    std::string name_ {"steamed-turnip"};

    void onTaskComplete(const Value &result);

    void onTaskError(const err::Error &error);

    void onTaskStart(const TaskId &taskId);

    ActionPtr action(const std::string &command, bool *ok = nullptr) const;
};

} // namespace cmd
} // namespace turnip

#endif // MENU_H
