#include "ThisApp.h"
#include "common/Factory.h"
#include "cmd/PrintAction.h"
#include "cmd/LineTranslator.h"

#include "cmd/rep/RepresentationManager.h"
#include "cmd/rep/HexIntRep.h"

using namespace turnip;
using namespace cmd;
using namespace rep;

ThisApp::ThisApp() {}

void ThisApp::registerActions()
{
    REGISTER_TURNIP_CLASS(Action, PrintAction);
}

void ThisApp::registerMenu(turnip::cmd::Menu &menu)
{
    menu.registerCommand("abc", Value());
    menu.registerCommand("abcdefg", Value());
    menu.registerCommand("copy", Value());
    menu.registerCommand("cmp", Value());
    menu.registerCommand("xyz_abc", Value());
    menu.registerCommand("test3xyz", Value());
    menu.registerCommand("test2defg", Value());
    menu.registerCommand("test1abc", Value());
    menu.registerCommand("quit", Value());
    menu.registerCommand("help", Value());
    menu.registerCommand("exit", Value());
    menu.registerCommand("print", "PrintAction");
}

Translator *ThisApp::createTranslator() const
{
    return new LineTranslator();
}

void ThisApp::registerRepresentaions()
{
    App::registerRepresentaions();

    RepresentationManager::registerRepresentation("hex_int",
                                                  std::make_unique<HexIntRep>());
}

std::string ThisApp::appName() const
{
    return std::string("steamed-turnip");
}
