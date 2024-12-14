#include "ThisApp.h"
#include "cmd/ConditionalStringAction.h"
#include "cmd/MenuAction.h"
#include "common/Factory.h"
#include "cmd/PrintAction.h"
#include "cmd/LineTranslator.h"
#include "cmd/HelpAction.h"

#include "cmd/IsEvenAction.h"

#include "cmd/rep/RepresentationManager.h"
#include "cmd/rep/HexIntRep.h"

#include "test/TestCmdValue.h"
#include "test/TestSharedVector.h"
#include "test/TestLazyPointer.h"

using namespace turnip;
using namespace cmd;
using namespace rep;
using namespace math;

ThisApp::ThisApp() {}

void ThisApp::registerActions()
{
    REGISTER_TURNIP_CLASS(Action, PrintAction);
    REGISTER_TURNIP_CLASS(Action, TestSharedVector);
    REGISTER_TURNIP_CLASS(Action, TestCmdValue);
    REGISTER_TURNIP_CLASS(Action, TestLazyPointer);
    REGISTER_TURNIP_CLASS(Action, HelpAction);
    REGISTER_TURNIP_CLASS(Action, ConditionalStringAction);
    REGISTER_TURNIP_CLASS(Action, IsEvenAction);
    REGISTER_TURNIP_CLASS(Action, MenuAction);
}

void ThisApp::registerMenu(turnip::cmd::Menu &menu)
{
    menu.registerAction("print", "PrintAction");
    menu.registerAction("shv", "TestSharedVector");
    menu.registerAction("cval", "TestCmdValue");
    menu.registerAction("lazy", "TestLazyPointer");
    menu.registerAction("conds", "ConditionalStringAction");
    menu.registerAction("even", LazyAction("IsEvenAction"));

    auto mathAction = LazyAction("MenuAction");
    mathAction.dynamicCast<MenuAction>()->setMenuName("math");
    mathAction.dynamicCast<MenuAction>()->addAction("even", "IsEvenAction");
    menu.registerAction("math", mathAction);
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
    return std::string(TARGET_NAME);
}
