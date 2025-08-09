#include "App.h"
#include "console/Reader.h"
#include "cmd/rep/NullRep.h"
#include "cmd/rep/BoolRep.h"
#include "cmd/rep/SimpleCharRep.h"
#include "cmd/rep/DecIntRep.h"
#include "cmd/rep/SimpleStringRep.h"

#include "cmd/Task.h"

namespace turnip {

using namespace cmd::rep;

App::App() {}

void App::init()
{
    registerActions();

    // This approach is fragile because it relies on specific initialization order.
    // TODO: Consider refactoring for greater stability.
    registerRepresentaions();

    mainMenu_.setTranslator(translator());
    mainMenu_.registerHelpAction();
    mainMenu_.setName(appName());
    registerMenu(mainMenu_);

    auto taskIdGen = taskIdGenenerator();
    cmd::Task::setTaskIdGen(taskIdGen);

    // TODO: Add your initialization code here.

    specificInit();
}

void App::exec()
{
    console::Reader reader(mainMenu_.name(), mainMenu_.commandList());

    std::string historyFileName {"." + appName() + ".command-history"};
    reader.setHistoryFileName(historyFileName);

    {
        auto f = std::bind(&cmd::Menu::processString, &mainMenu_, std::placeholders::_1);
        reader.setCallback(f);
    }

    {
        auto f = std::bind(&console::Reader::onResult, &reader, std::placeholders::_1);
        mainMenu_.setResultCallback(f);
    }

    {
        auto f = std::bind(&console::Reader::onError, &reader, std::placeholders::_1);
        mainMenu_.setErrorCallback(f);
    }

    {
        auto f = std::bind(&console::Reader::onTaskStart, &reader, std::placeholders::_1);
        mainMenu_.setStartCallback(f);
    }

    reader.read();
}

cmd::TaskPtr App::executeCommand(const std::string &command, const cmd::ArgList &args)
{
    return mainMenu_.executeAction(command, args);
}

void App::registerRepresentaions()
{
    REGISTER_TURNIP_CLASS(Representation, NullRep);
    REGISTER_TURNIP_CLASS(Representation, BoolRep);
    REGISTER_TURNIP_CLASS(Representation, SimpleCharRep);
    REGISTER_TURNIP_CLASS(Representation, DecIntRep);
    REGISTER_TURNIP_CLASS(Representation, DoubleRep);
    REGISTER_TURNIP_CLASS(Representation, SimpleStringRep);
}

std::shared_ptr<cmd::Translator> App::translator()
{
    if (!trnsl_) {
        trnsl_ = createTranslator();
    }

    return trnsl_;
}

std::shared_ptr<cmd::TaskIdGenerator> App::taskIdGenenerator()
{
    if (!taskIdGen_) {
        taskIdGen_ = createTaskIdGenenerator();
        taskIdGen_->init();
    }

    return taskIdGen_;
}

cmd::Menu *App::mainMenu()
{
    return &mainMenu_;
}

cmd::TaskManager *App::taskManager() const
{
    return mainMenu_.taskManager();
}

} // namespace turnip
