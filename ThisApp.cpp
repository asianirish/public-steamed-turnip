#include "ThisApp.h"
#include "cmd/ConditionalStringAction.h"
#include "cmd/MenuAction.h"
#include "common/Factory.h"
#include "cmd/PrintAction.h"
#include "cmd/LineTranslator.h"
#include "cmd/HelpAction.h"

#include "example/MakeSentence.h"
#include "math/DegreesToRadians.h"
#include "math/IsEven.h"
#include "math/Divide.h"

#include "cmd/rep/RepresentationManager.h"
#include "cmd/rep/HexIntRep.h"

#include "cmd/CompositeAction.h"

#include "cmd/TaskIdIncGenerator.h"

#include "math/SineOfRadians.h"

#include "test/TestActionMap.h"
#include "test/TestCmdValue.h"
#include "test/TestSharedVector.h"
#include "test/TestLazyPointer.h"

using namespace turnip;
using namespace cmd;
using namespace rep;
using namespace math;
using namespace example;

ThisApp::ThisApp() {}

void ThisApp::registerActions()
{
    REGISTER_TURNIP_CLASS(Action, PrintAction);
    REGISTER_TURNIP_CLASS(Action, TestSharedVector);
    REGISTER_TURNIP_CLASS(Action, TestCmdValue);
    REGISTER_TURNIP_CLASS(Action, TestLazyPointer);
    REGISTER_TURNIP_CLASS(Action, HelpAction);
    REGISTER_TURNIP_CLASS(Action, ConditionalStringAction);
    REGISTER_TURNIP_CLASS(Action, IsEven);
    REGISTER_TURNIP_CLASS(Action, MenuAction);
    REGISTER_TURNIP_CLASS(Action, DegreesToRadians);
    REGISTER_TURNIP_CLASS(Action, SineOfRadians);
    REGISTER_TURNIP_CLASS(Action, CompositeAction);
    REGISTER_TURNIP_CLASS(Action, TestActionMap);
    REGISTER_TURNIP_CLASS(Action, MakeSentence);
    REGISTER_TURNIP_CLASS(Action, Divide);
}

void ThisApp::registerMenu(turnip::cmd::Menu &menu)
{
    menu.registerAction("print", ACTION_CLASS(PrintAction));
    menu.registerAction("shv", ACTION_CLASS(TestSharedVector));
    menu.registerAction("cval", ACTION_CLASS(TestCmdValue));
    menu.registerAction("lazy", ACTION_CLASS(TestLazyPointer));
    menu.registerAction("conds", ACTION_CLASS(ConditionalStringAction));

    auto mathAction = LazyAction(ACTION_CLASS(MenuAction));
    auto mathMenuAction = mathAction.dynamicCast<MenuAction>();
    mathMenuAction->setTranslator(translator());
    mathMenuAction->setMenuName("math");

    mathMenuAction->addAction("even", ACTION_CLASS(IsEven));
    mathMenuAction->addAction("d2r", ACTION_CLASS(DegreesToRadians));
    mathMenuAction->addAction("sinr", ACTION_CLASS(SineOfRadians));
    mathMenuAction->addAction("sind", sineOfDegrees());
    mathMenuAction->addAction("div", ACTION_CLASS(Divide));
    mathMenuAction->addAction("rdiv", reverseDivide());

    menu.registerAction("math", mathAction);

    menu.registerAction("amap", ACTION_CLASS(TestActionMap));

    menu.registerAction("snt", ACTION_CLASS(MakeSentence));

    menu.registerAction("rvrs", reverseSentence());
    menu.registerAction("drvrs", doubleReverseSentence());


}

const std::shared_ptr<cmd::Translator> ThisApp::createTranslator() const
{
    return std::shared_ptr<cmd::Translator>(new LineTranslator());
}

void ThisApp::registerRepresentaions()
{
    App::registerRepresentaions();

    RepresentationManager::registerRepresentation<HexIntRep>();
}

const std::shared_ptr<TaskIdGenerator> ThisApp::createTaskIdGenenerator() const
{
    auto gen = std::make_shared<TaskIdIncGenerator>();
    return gen;
}

std::string ThisApp::appName() const
{
    return std::string(TARGET_NAME);
}

LazyAction ThisApp::reverseDivide()
{
    auto rvrs = LazyAction(ACTION_CLASS(CompositeAction));
    auto caRvrs = rvrs.dynamicCast<CompositeAction>();

    def::ActionDef actionDef;

    const auto typeDef = def::TypeDef::createDoubleTypedef();

    {
        def::ArgDef argDef;
        argDef.setType(typeDef);
        argDef.setName("left number");
        actionDef.addArgDef(argDef);
    }

    {
        def::ArgDef argDef;
        argDef.setType(typeDef);
        argDef.setName("right number");
        actionDef.addArgDef(argDef);
    }

    actionDef.setDescription("Reverse Divide");
    caRvrs->setActionDef(actionDef);

    Substitutor sbst;
    Parameter actionParam;
    auto sntAction = LazyAction(ACTION_CLASS(Divide));
    actionParam.setValue(sntAction);

    sbst.setActionParam(actionParam);
    sbst.addParam(Parameter(1));
    sbst.addParam(Parameter(0));

    caRvrs->setSubstitutor(sbst);

    return rvrs;
}

LazyAction ThisApp::doubleReverseSentence()
{
    auto rvrs = LazyAction(ACTION_CLASS(CompositeAction));
    auto caRvrs = rvrs.dynamicCast<CompositeAction>();

    def::ActionDef actionDef;

    const auto typeDef = def::TypeDef::createStringTypedef();

    {
        def::ArgDef argDef;
        argDef.setType(typeDef);
        argDef.setName("subject");
        actionDef.addArgDef(argDef);
    }

    {
        def::ArgDef argDef;
        argDef.setType(typeDef);
        argDef.setName("verb");
        actionDef.addArgDef(argDef);
    }

    {
        def::ArgDef argDef;
        argDef.setType(typeDef);
        argDef.setName("object");
        actionDef.addArgDef(argDef);
    }

    actionDef.setDescription("Reverses a sentence");
    caRvrs->setActionDef(actionDef);

    Substitutor sbst;
    Parameter actionParam;
    auto sntAction = reverseSentence();
    actionParam.setValue(sntAction);

    sbst.setActionParam(actionParam);
    sbst.addParam(Parameter(2));
    sbst.addParam(Parameter(1));
    sbst.addParam(Parameter(0));

    caRvrs->setSubstitutor(sbst);

    return rvrs;
}

LazyAction ThisApp::reverseSentence()
{
    auto rvrs = LazyAction(ACTION_CLASS(CompositeAction));
    auto caRvrs = rvrs.dynamicCast<CompositeAction>();

    def::ActionDef actionDef;

    const auto typeDef = def::TypeDef::createStringTypedef();

    {
        def::ArgDef argDef;
        argDef.setType(typeDef);
        argDef.setName("subject");
        actionDef.addArgDef(argDef);
    }

    {
        def::ArgDef argDef;
        argDef.setType(typeDef);
        argDef.setName("verb");
        actionDef.addArgDef(argDef);
    }

    {
        def::ArgDef argDef;
        argDef.setType(typeDef);
        argDef.setName("object");
        actionDef.addArgDef(argDef);
    }

    actionDef.setDescription("Reverses a sentence");
    caRvrs->setActionDef(actionDef);

    Substitutor sbst;
    Parameter actionParam;
    auto sntAction = LazyAction(ACTION_CLASS(MakeSentence));
    actionParam.setValue(sntAction);

    sbst.setActionParam(actionParam);
    sbst.addParam(Parameter(2));
    sbst.addParam(Parameter(1));
    sbst.addParam(Parameter(0));

    caRvrs->setSubstitutor(sbst);

    return rvrs;
}

LazyAction ThisApp::sineOfDegrees()
{
    // auto sind = make_shared<CompositeAction>(new CompositeAction()); // TODO: enable direct creation
    auto sind = LazyAction(ACTION_CLASS(CompositeAction));
    auto caSind = sind.dynamicCast<CompositeAction>();

    def::ActionDef actionDef;

    const auto typeDef = def::TypeDef::createDoubleTypedef();

    def::ArgDef argDef;
    argDef.setType(typeDef);
    argDef.setName("degrees");
    actionDef.addArgDef(argDef);
    actionDef.setDescription("Calculates the sine of a specified angle measured in degrees");

    caSind->setActionDef(actionDef);

    Substitutor sbst;
    Parameter actionParam;
    auto sntAction = LazyAction(ACTION_CLASS(SineOfRadians));
    actionParam.setValue(sntAction);

    auto ssbstPtr = std::make_shared<Substitutor>(ACTION_CLASS(DegreesToRadians), ParamList({Parameter(0)}));

    sbst.setActionParam(actionParam);
    sbst.addParam(Parameter(ssbstPtr));

    caSind->setSubstitutor(sbst);

    return sind;
}
