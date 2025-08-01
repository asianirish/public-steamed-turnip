#include "TestingComposer.h"

#include "lst/ArgsToListAction.h"
#include "lst/ConcatListAction.h"
// TODO: #include "lst/ListToArgsAction.h"

#include "cmd/CommonComposer.h"
#include "cmd/First.h"
#include "cmd/ForAction.h"
#include "cmd/CompositeAction.h"
#include "cmd/HowLongSince.h"
#include "cmd/MapToArgsAction.h"
#include "cmd/PersonArgToMapAction.h"
#include "cmd/PrintAction.h"
#include "cmd/PrintPersonAction.h"
#include "cmd/WhileAction.h"
#include "cmd/def/ActionDef.h"

#include "math/AddAction.h"
#include "math/Inc.h"

using namespace turnip;
using namespace cmd;
using namespace math;
using namespace lst;

turnip::cmd::ActionPtr TestingComposer::concatPrint()
{
    auto ca = mkDynActionPtr(CompositeAction);

    const auto typeDef = def::TypeDef::createStringTypedef();

    def::ActionDef actionDef;
    {
        def::ArgDef argDef;
        argDef.setType(typeDef);
        argDef.setName("left");
        actionDef.addArgDef(argDef);
    }

    {
        def::ArgDef argDef;
        argDef.setType(typeDef);
        argDef.setName("right");
        actionDef.addArgDef(argDef);
    }

    actionDef.setDescription("Concat And Print");
    ca->setActionDef(actionDef);

    ca->setAction(mkActionPtr(PrintAction));
    ca->addParam(mkActionPtr(Concat), ParamList({0, 1}));

    return ca;
}

ActionPtr TestingComposer::map2HowLong()
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

ActionPtr TestingComposer::printPersonMap()
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

ActionPtr TestingComposer::forConcatPrint()
{
    auto ca = mkDynActionPtr(CompositeAction);

    def::ActionDef actionDef;

    {
        const auto typeDef = def::TypeDef::createStringTypedef();
        def::ArgDef argDef;
        argDef.setType(typeDef);
        argDef.setName("right");
        actionDef.addArgDef(argDef);
    }

    {
        const auto typeDef = def::TypeDef::createIntTypedef();
        def::ArgDef argDef;
        argDef.setType(typeDef);
        argDef.setName("upTo");
        actionDef.addArgDef(argDef);
    }

    actionDef.setDescription("Multi Concat And Print");
    ca->setActionDef(actionDef);

    ca->setAction(mkActionPtr(ForAction));
    auto printParam =  Parameter(concatPrint(), ParamList({0_val, 0}));
    auto incParam = Parameter(mkActionPtr(Inc), ParamList({1}));

    ca->addParams(ParamList({incParam, 1_val, 0_val, printParam}));

    return ca;
}


ActionPtr TestingComposer::countTask()
{
    auto ca = mkDynActionPtr(CompositeAction);

    def::ActionDef actionDef;

    {
        const auto typeDef = def::TypeDef::createIntTypedef();
        def::ArgDef argDef;
        argDef.setType(typeDef);
        argDef.setName("counter");
        actionDef.addArgDef(argDef);
    }

    {
        const auto typeDef = def::TypeDef::createStringTypedef();
        def::ArgDef argDef;
        argDef.setType(typeDef);
        argDef.setName("message");
        actionDef.addArgDef(argDef);
    }

    actionDef.setDescription("Count Task");
    ca->setActionDef(actionDef);

    ca->setAction(mkActionPtr(First));

    auto incParam = Parameter(mkActionPtr(Inc), ParamList({0}));
    auto printParam =  Parameter(concatPrint(), ParamList({0, 1}));
    ca->addParams(ParamList({incParam, printParam}));

    return ca;
}

ActionPtr TestingComposer::whileTask()
{
    auto ca = mkDynActionPtr(CompositeAction);

    def::ActionDef actionDef;

    {
        const auto typeDef = def::TypeDef::createTaskTypedef();
        def::ArgDef argDef;
        argDef.setType(typeDef);
        argDef.setName("message");
        actionDef.addArgDef(argDef);
    }

    actionDef.setDescription("While Task Composite Action");
    ca->setActionDef(actionDef);

    ca->setAction(mkActionPtr(WhileAction));

    auto printParam = Parameter(countTask(), ParamList({0_val, 0}));
    auto lessParam = Parameter(CommonComposer::lessOrEqual(), ParamList({0_val, 6_val}));

    ca->addParams(ParamList({printParam, lessParam, 0_val, 0_val}));

    return ca;
}

TestingComposer::TestingComposer() {}
