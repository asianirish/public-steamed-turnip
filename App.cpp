#include "App.h"
#include "console/Reader.h"
#include "cmd/rep/RepresentationManager.h"
#include "cmd/rep/NullRep.h"
#include "cmd/rep/BoolRep.h"
#include "cmd/rep/SimpleCharRep.h"
#include "cmd/rep/DecIntRep.h"
#include "cmd/rep/SimpleStringRep.h"

namespace turnip {

using namespace cmd::rep;

App::App() {}

void App::init()
{
    registerActions();

    mainMenu_.setTranslator(translator());
    mainMenu_.registerHelpAction();
    mainMenu_.setName(appName());
    registerMenu(mainMenu_);

    registerRepresentaions();
    // TODO: Add your initialization code here.

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

void App::registerRepresentaions()
{
    RepresentationManager::registerRepresentation<NullRep>();

    RepresentationManager::registerRepresentation<BoolRep>();

    RepresentationManager::registerRepresentation<SimpleCharRep>();

    RepresentationManager::registerRepresentation<DecIntRep>();

    RepresentationManager::registerRepresentation<DoubleRep>();

    RepresentationManager::registerRepresentation<SimpleStringRep>();
}

std::shared_ptr<cmd::Translator> App::translator()
{
    if (!trnsl_) {
        trnsl_ = createTranslator();
    }

    return trnsl_;
}

} // namespace turnip
