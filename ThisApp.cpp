#include "ThisApp.h"

#include "cmd/AsyncCompositeAction.h"
#include "cmd/AsyncPrintAction.h"
#include "cmd/CommonComposer.h"
#include "cmd/HowLongSince.h"
#include "cmd/MapToArgsAction.h"
#include "cmd/PersonArgToMapAction.h"
#include "cmd/Context.h"
#include "cmd/PrintPersonAction.h"
#include "common/Factory.h"
#include "common/HumanStringGenerator.h"

#include "cmd/ConditionalStringAction.h"
#include "cmd/DoNothing.h"
#include "cmd/ContextualAction.h"
#include "cmd/CountingAction.h"
#include "cmd/IfAction.h"
#include "cmd/MenuAction.h"
#include "cmd/PrintAction.h"
#include "cmd/LineTranslator.h"
#include "cmd/HelpAction.h"
#include "cmd/rep/HexIntRep.h"
#include "cmd/CompositeAction.h"
#include "cmd/TaskIdIncGenerator.h"
#include "cmd/Task.h"

#include "example/MakeSentence.h"

#include "math/Decr.h"
#include "math/DegreesToRadians.h"
#include "math/Eq.h"
#include "math/Greater.h"
#include "math/Inc.h"
#include "math/IsEven.h"
#include "math/Divide.h"
#include "math/Less.h"
#include "math/LogicalAndAction.h"
#include "math/LogicalOrAction.h"
#include "math/LogicalXorAction.h"
#include "math/MultAction.h"
#include "math/AddAction.h"
#include "math/DivAction.h"
#include "math/RemAction.h"
#include "math/SubAction.h"
#include "math/SineOfRadians.h"

#include "test/TestActionMap.h"
#include "test/TestChance.h"
#include "test/TestCmdValue.h"
#include "test/TestSharedVector.h"
#include "test/TestLazyPointer.h"
#include "test/TestStringGen.h"

using namespace turnip;
using namespace cmd;
using namespace rep;
using namespace math;
using namespace example;

using namespace common;

ThisApp::ThisApp() {}

void ThisApp::specificInit()
{
    // do nothing
}

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
    REGISTER_TURNIP_CLASS(Action, DoNothing);
    REGISTER_TURNIP_CLASS(Action, IfAction);
    REGISTER_TURNIP_CLASS(Action, AddInt);
    REGISTER_TURNIP_CLASS(Action, AddFloat);
    REGISTER_TURNIP_CLASS(Action, Concat);
    REGISTER_TURNIP_CLASS(Action, MultInt);
    REGISTER_TURNIP_CLASS(Action, MultFloat);
    REGISTER_TURNIP_CLASS(Action, SubInt);
    REGISTER_TURNIP_CLASS(Action, SubFloat);
    REGISTER_TURNIP_CLASS(Action, DivInt);
    REGISTER_TURNIP_CLASS(Action, DivFloat);
    REGISTER_TURNIP_CLASS(Action, RemAction);
    REGISTER_TURNIP_CLASS(Action, Inc);
    REGISTER_TURNIP_CLASS(Action, Decr);
    REGISTER_TURNIP_CLASS(Action, TestStringGen);
    REGISTER_TURNIP_CLASS(Action, CountingAction);
    REGISTER_TURNIP_CLASS(Action, ContextualAction);

    REGISTER_TURNIP_CLASS(Action, EqInt);
    REGISTER_TURNIP_CLASS(Action, LessInt);
    REGISTER_TURNIP_CLASS(Action, GreaterInt);

    REGISTER_TURNIP_CLASS(Action, LogicalAndAction);
    REGISTER_TURNIP_CLASS(Action, LogicalOrAction);
    REGISTER_TURNIP_CLASS(Action, LogicalXorAction);

    REGISTER_TURNIP_CLASS(Action, PersonArgToMapAction);
    REGISTER_TURNIP_CLASS(Action, PrintPersonAction);
    REGISTER_TURNIP_CLASS(Action, MapToArgsAction);
    REGISTER_TURNIP_CLASS(Action, HowLongSince);
    REGISTER_TURNIP_CLASS(Action, AsyncPrintAction);
    REGISTER_TURNIP_CLASS(Action, AsyncCompositeAction);

    REGISTER_TURNIP_CLASS(Action, TestChance);
}

void ThisApp::registerMenu(turnip::cmd::Menu &menu)
{
    menu.registerAction("print", ACTION_CLASS(PrintAction));
    menu.registerAction("shv", ACTION_CLASS(TestSharedVector));
    menu.registerAction("cval", ACTION_CLASS(TestCmdValue));
    menu.registerAction("lazy", ACTION_CLASS(TestLazyPointer));
    menu.registerAction("conds", ACTION_CLASS(ConditionalStringAction));
    menu.registerAction("concat", ACTION_CLASS(Concat));

    auto mathAction = ActionPtr(Factory<Action>::create(ACTION_CLASS(MenuAction)));
    auto mathMenuAction = std::dynamic_pointer_cast<MenuAction>(mathAction);
    mathMenuAction->setTranslator(translator());
    mathMenuAction->setMenuName("math");

    mathMenuAction->addAction("even", ACTION_CLASS(IsEven));
    mathMenuAction->addAction("d2r", ACTION_CLASS(DegreesToRadians));
    mathMenuAction->addAction("sinr", ACTION_CLASS(SineOfRadians));
    mathMenuAction->addAction("sind", sineOfDegrees());
    mathMenuAction->addAction("div", ACTION_CLASS(Divide));
    mathMenuAction->addAction("rdiv", reverseDivide());

    mathMenuAction->addAction("addi", ACTION_CLASS(AddInt));
    mathMenuAction->addAction("addf", ACTION_CLASS(AddFloat));
    mathMenuAction->addAction("multi", ACTION_CLASS(MultInt));
    mathMenuAction->addAction("multf", ACTION_CLASS(MultFloat));
    mathMenuAction->addAction("subi", ACTION_CLASS(SubInt));
    mathMenuAction->addAction("subf", ACTION_CLASS(SubFloat));
    mathMenuAction->addAction("divi", ACTION_CLASS(DivInt));
    mathMenuAction->addAction("divf", ACTION_CLASS(DivFloat));
    mathMenuAction->addAction("rem", ACTION_CLASS(RemAction));
    mathMenuAction->addAction("++", ACTION_CLASS(Inc));
    mathMenuAction->addAction("--", ACTION_CLASS(Decr));
    mathMenuAction->addAction("eqi", ACTION_CLASS(EqInt));

    mathMenuAction->addAction("lessi", ACTION_CLASS(LessInt));
    mathMenuAction->addAction("greateri", ACTION_CLASS(GreaterInt));
    mathMenuAction->addAction("loei", CommonComposer::lessOrEqual());


    mathMenuAction->addAction("and", ACTION_CLASS(LogicalAndAction));
    mathMenuAction->addAction("or", ACTION_CLASS(LogicalOrAction));
    mathMenuAction->addAction("xor", ACTION_CLASS(LogicalXorAction));

    menu.registerAction("math", mathAction);

    menu.registerAction("amap", ACTION_CLASS(TestActionMap));

    menu.registerAction("snt", ACTION_CLASS(MakeSentence));

    menu.registerAction("rvrs", reverseSentence());
    menu.registerAction("drvrs", doubleReverseSentence());

    menu.registerAction("nothing", ACTION_CLASS(DoNothing));
    menu.registerAction("multiprint", multiPrint());

    menu.registerAction("yesno", yesNoPrint());

    menu.registerAction("strgen", ACTION_CLASS(TestStringGen));

    menu.registerAction("count", ACTION_CLASS(CountingAction));
    menu.registerAction("rprint", recursivePrint());
    menu.registerAction("ryn", recursiveYesNo());

    menu.registerAction("pam", ACTION_CLASS(PersonArgToMapAction));
    menu.registerAction("pp", ACTION_CLASS(PrintPersonAction));
    menu.registerAction("cpp", compositePrintPerson());
    menu.registerAction("hl", ACTION_CLASS(HowLongSince));
    menu.registerAction("chl",compositeHowLong());

    menu.registerAction("aprint", ACTION_CLASS(AsyncPrintAction));

    menu.registerAction("chance", ACTION_CLASS(TestChance));
}

const std::shared_ptr<cmd::Translator> ThisApp::createTranslator() const
{
    return std::shared_ptr<cmd::Translator>(new LineTranslator());
}

void ThisApp::registerRepresentaions()
{
    App::registerRepresentaions();
    REGISTER_TURNIP_CLASS(Representation, HexIntRep);
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

ActionPtr ThisApp::recursiveYesNo()
{
    auto caAction = mkDynActionPtr(CompositeAction);

    def::ActionDef actionDef;
    actionDef.setDescription("Recursive Yes-No");
    actionDef.setResultRepresentation(mkRepPtr(SimpleStringRep));

    const auto intDef = def::TypeDef::createIntTypedef();

    def::ArgDef argDef;
    argDef.setType(intDef);
    actionDef.addArgDef(argDef);

    caAction->setActionDef(actionDef);

    //---

    auto context = Context::create();
    context->setStringGen(mkPtr<common::HumanStringGenerator>());
    auto printAlias = context->registerValue(mkActionPtr(CountingAction), "print");
    auto selfAlias = context->registerValue(caAction, "self");
    auto eqAlias = context->registerValue(mkActionPtr(EqInt), "eq");
    auto incAlias = context->registerValue(mkActionPtr(Inc), "inc");

    caAction->setAction(mkActionPtr(IfAction));
    caAction->addParams(ParamList({
        {
            eqAlias, ParamList ({
                Parameter{Value(1337)}, Parameter({incAlias, ParamList({0})})
            })
        },
        {printAlias, {{Value("yes")}}},
        {printAlias, {{Value("no")}}}
    }
    )
    );
    return caAction;
}

ActionPtr ThisApp::recursivePrint()
{
    auto caAction = mkDynActionPtr(CompositeAction);


    def::ActionDef actionDef;
    actionDef.setDescription("Recursive Print");

    auto boolRep = mkDynRepPtr(BoolRep);
    boolRep->setKind(BoolRep::Kind::OnOff);
    actionDef.setResultRepresentation(boolRep);

    def::ArgDef argDef;

    const auto strTypeDef = def::TypeDef::createStringTypedef();
    argDef.setType(strTypeDef);
    actionDef.addArgDef(argDef);

    caAction->setActionDef(actionDef);

    // ---

    auto context = Context::create();
    context->setStringGen(mkPtr<common::HumanStringGenerator>());
    auto selfAlias = context->registerValue(caAction, "self");
    auto printAlias = context->registerValue(mkActionPtr(CountingAction), "print");

    caAction->setAction(selfAlias);
    caAction->addParam(printAlias, ParamList({0}));

    auto cntxAction = mkDynActionPtr(ContextualAction);
    cntxAction->setCompositeAction(caAction);
    cntxAction->setContext(context);

    return cntxAction;
}

ActionPtr ThisApp::yesNoPrint()
{
    auto caAction = mkDynActionPtr(CompositeAction);

    def::ActionDef actionDef;
    actionDef.setDescription("Yes-No Print");
    actionDef.setResultRepresentation(mkRepPtr(SimpleStringRep));

    const auto boolDef = def::TypeDef::createBoolTypedef(BoolRep::Kind::YesNo);

    def::ArgDef argDef;
    argDef.setType(boolDef);
    actionDef.addArgDef(argDef);

    caAction->setActionDef(actionDef);

    //---

    auto context = Context::create();
    context->setStringGen(mkPtr<common::HumanStringGenerator>());
    auto printAlias = context->registerValue(mkActionPtr(CountingAction), "print");

    caAction->setAction(mkActionPtr(IfAction));
    caAction->addParams(ParamList({0,
                                {printAlias, {{Value("yes")}}},
                                {printAlias, {{Value("no")}}}
                                  }
                                 )
                        );
    return caAction;
}

ActionPtr ThisApp::multiPrint()
{
    auto caAction = mkDynActionPtr(CompositeAction);

    def::ActionDef actionDef;

    const auto typeDef = def::TypeDef::createStringTypedef();

    for (int i = 0; i < 4; ++i) {
        def::ArgDef argDef;
        argDef.setType(typeDef);
        argDef.setDefaultValue(std::string());
        actionDef.addArgDef(argDef);
    }

    actionDef.setDescription("Multiple Print");
    // TODO: support constructor arguments in Factory
    auto boolRep = mkDynRepPtr(BoolRep);
    boolRep->setKind(BoolRep::Kind::OnOff);
    actionDef.setResultRepresentation(boolRep);
    caAction->setActionDef(actionDef);

    //---

    auto context = Context::create();
    context->setStringGen(mkPtr<common::HumanStringGenerator>());
    auto doNothingAlias = context->registerValue(mkActionPtr(DoNothing));
    auto printAlias = context->registerValue(mkActionPtr(PrintAction));

    caAction->setAction(doNothingAlias);

    for (int i = 0; i < 4; ++i) {
        caAction->addParam(printAlias, ParamList({i}));
    }

    return caAction;
}

ActionPtr ThisApp::reverseDivide()
{
    auto caRvrs = mkDynActionPtr(CompositeAction);

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
    actionDef.setResultRepresentation(mkRepPtr(DoubleRep));
    caRvrs->setActionDef(actionDef);

    //---

    caRvrs->setAction(mkActionPtr(Divide));
    caRvrs->addParams(ParamList({1, 0}));

    return caRvrs;
}

ActionPtr ThisApp::doubleReverseSentence()
{
    auto caRvrs = mkDynActionPtr(AsyncCompositeAction);

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

    actionDef.setDescription("Double reverses a sentence");
    caRvrs->setActionDef(actionDef);

    //---

    caRvrs->setAction(reverseSentence());
    caRvrs->addParams(ParamList({2, 1, 0}));

    return caRvrs;
}

ActionPtr ThisApp::reverseSentence()
{
    auto caRvrs = mkDynActionPtr(AsyncCompositeAction);

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

    //---

    caRvrs->setAction(mkActionPtr(MakeSentence));
    caRvrs->addParams(ParamList({2, 1, 0}));


    return caRvrs;
}

ActionPtr ThisApp::sineOfDegrees()
{
    auto caSind = mkDynActionPtr(CompositeAction);

    def::ActionDef actionDef;

    const auto typeDef = def::TypeDef::createDoubleTypedef();

    def::ArgDef argDef;
    argDef.setType(typeDef);
    argDef.setName("degrees");
    actionDef.addArgDef(argDef);
    actionDef.setDescription("Calculates the sine of a specified angle measured in degrees");

    actionDef.setResultRepresentation(mkRepPtr(DoubleRep));

    caSind->setActionDef(actionDef);

    //---

    // caSind->setSubstitutor(sbst);
    caSind->setAction(mkActionPtr(SineOfRadians));
    caSind->addParam(mkActionPtr(DegreesToRadians), ParamList({0}));

    return caSind;
}

ActionPtr ThisApp::compositePrintPerson()
{
    auto caSind = mkDynActionPtr(CompositeAction);

    ActionDef actionDef;

    const auto stringTypeDef = TypeDef::createStringTypedef();
    const auto intTypeDef = TypeDef::createIntTypedef();
    const auto charTypeDef = TypeDef::createCharTypedef();

    // defs:
    {
        ArgDef argDef;
        argDef.setType(stringTypeDef);
        argDef.setName("name");
        argDef.setDesc("Person's Name");
        actionDef.addArgDef(argDef);
    }

    {
        ArgDef argDef;
        argDef.setType(intTypeDef);
        argDef.setName("year");
        argDef.setDesc("Year of birth");
        actionDef.addArgDef(argDef);
    }

    {
        ArgDef argDef;
        argDef.setType(charTypeDef); // TODO: constraint: 'm' or 'f'
        argDef.setName("gender");
        argDef.setDesc("Person's Gender");
        actionDef.addArgDef(argDef);
    }


    actionDef.setDescription("Print Person");

    caSind->setActionDef(actionDef);

    // /defs

    caSind->setAction(mkActionPtr(MapToArgsAction));
    caSind->addParams(ParamList({mkActionPtr(PrintPersonAction),
                                Parameter(mkActionPtr(PersonArgToMapAction), ParamList({0, 1, 2}))
                                }));

    return caSind;
}

ActionPtr ThisApp::compositeHowLong()
{
    auto caSind = mkDynActionPtr(CompositeAction);

    ActionDef actionDef;

    const auto stringTypeDef = TypeDef::createStringTypedef();
    const auto intTypeDef = TypeDef::createIntTypedef();
    const auto charTypeDef = TypeDef::createCharTypedef();

    // defs:
    {
        ArgDef argDef;
        argDef.setType(stringTypeDef);
        argDef.setName("name");
        argDef.setDesc("Person's Name");
        actionDef.addArgDef(argDef);
    }

    {
        ArgDef argDef;
        argDef.setType(intTypeDef);
        argDef.setName("year");
        argDef.setDesc("Year of birth");
        actionDef.addArgDef(argDef);
    }

    {
        ArgDef argDef;
        argDef.setType(charTypeDef); // TODO: constraint: 'm' or 'f'
        argDef.setName("gender");
        argDef.setDesc("Person's Gender");
        actionDef.addArgDef(argDef);
    }


    actionDef.setDescription("Composite How Long Since");

    caSind->setActionDef(actionDef);

    // /defs

    caSind->setAction(mkActionPtr(MapToArgsAction));
    caSind->addParams(ParamList({mkActionPtr(HowLongSince),
        Parameter(mkActionPtr(PersonArgToMapAction), ParamList({0, 1, 2}))
    }));

    return caSind;
}
