#include "ThisApp.h"
#include "common/Factory.h"
#include "cmd/PrintAction.h"
#include "cmd/LineTranslator.h"

#include "cmd/rep/RepresentationManager.h"
#include "cmd/rep/HexIntRep.h"

#include "test/TestCmdValue.h"
#include "test/TestSharedVector.h"
#include "test/TestLazyPointer.h"

using namespace turnip;
using namespace cmd;
using namespace rep;

const std::string ThisApp::HEX_INT_REPRESENTATION {"hex_int"};

ThisApp::ThisApp() {}

void ThisApp::registerActions()
{
    REGISTER_TURNIP_CLASS(Action, PrintAction);
    REGISTER_TURNIP_CLASS(Action, TestSharedVector);
    REGISTER_TURNIP_CLASS(Action, TestCmdValue);
    REGISTER_TURNIP_CLASS(Action, TestLazyPointer);
}

void ThisApp::registerMenu(turnip::cmd::Menu &menu)
{
    menu.registerAction("print", "PrintAction");
    menu.registerAction("shv", "TestSharedVector");
    menu.registerAction("cval", "TestCmdValue");
    menu.registerAction("lazy", "TestLazyPointer");
}

Translator *ThisApp::createTranslator() const
{
    return new LineTranslator();
}

void ThisApp::registerRepresentaions()
{
    App::registerRepresentaions();

    RepresentationManager::registerRepresentation<HexIntRep>();
}

std::string ThisApp::appName() const
{
    return std::string("steamed-turnip");
}
