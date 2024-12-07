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

std::string App::DEFAULT_NULL_REPRESENTATION {"default_null"};
std::string App::DEFAULT_BOOL_REPRESENTATION {"default_bool"};
std::string App::DEFAULT_CHAR_REPRESENTATION {"default_char"};
std::string App::DEFAULT_INT_REPRESENTATION {"default_int"};
std::string App::DEFAULT_STRING_REPRESENTATION {"default_string"};

App::App() {}

void App::init()
{
    registerActions();

    std::shared_ptr<cmd::Translator> trnsl(createTranslator());
    mainMenu_.setTranslator(trnsl);
    mainMenu_.registerHelpAction();
    registerMenu(mainMenu_);

    registerRepresentaions();
    // TODO: Add your initialization code here.

}

void App::exec()
{
    console::Reader reader(mainMenu_.commandList());

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
    reader.read();
}

void App::registerRepresentaions()
{
    RepresentationManager::registerRepresentation<NullRep>();

    RepresentationManager::registerRepresentation<BoolRep>();

    RepresentationManager::registerRepresentation<SimpleCharRep>();

    RepresentationManager::registerRepresentation<DecIntRep>();

    RepresentationManager::registerRepresentation<SimpleStringRep>();
}

} // namespace turnip
