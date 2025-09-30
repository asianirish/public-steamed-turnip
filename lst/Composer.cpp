#include "Composer.h"

#include "cmd/CompositeAction.h"
#include "cmd/Const.h"

#include "cmd/ForAction.h"
#include "lst/ArgsToListAction.h"
#include "lst/AtAction.h"
#include "lst/Batch.h"
#include "lst/ConcatListAction.h"
#include "lst/SizeAction.h"

namespace turnip {
namespace cmd {
namespace lst {

ActionPtr Composer::concat()
{
    auto ca = mkDynActionPtr(CompositeAction);

    const auto typeDef = def::TypeDef::createStringTypedef();

    def::ActionDef actionDef;
    actionDef.setDescription("Concat args");

    for (size_t i = 0; i < 12; ++i)
    {
        def::ArgDef argDef;
        argDef.setType(typeDef);
        argDef.setDefaultValue("");
        actionDef.addArgDef(argDef);
    }

    ca->setActionDef(actionDef);

    ca->setAction(mkActionPtr(ConcatListAction));
    ca->addParams(ParamList({Parameter(mkActionPtr(ArgsToListAction), ParamList({0_pos, 1_pos, 2_pos, 3_pos, 4_pos, 5_pos,
                                                                                 6_pos, 7_pos, 8_pos, 9_pos, 10_pos, 11_pos}))}));

    return ca;
}

ActionPtr Composer::argListSize()
{
    auto ca = mkDynActionPtr(CompositeAction);

    const auto typeDef = def::TypeDef::createStringTypedef();

    def::ActionDef actionDef;
    actionDef.setDescription("Arg List Size");

    for (size_t i = 0; i < 12; ++i)
    {
        def::ArgDef argDef;
        argDef.setType(typeDef);
        argDef.setDefaultValue("");
        actionDef.addArgDef(argDef);
    }

    ca->setActionDef(actionDef);

    ca->setAction(mkActionPtr(SizeAction));
    ca->addParams(ParamList({Parameter(mkActionPtr(ArgsToListAction), ParamList({0_pos, 1_pos, 2_pos, 3_pos, 4_pos, 5_pos,
                                                                                 6_pos, 7_pos, 8_pos, 9_pos, 10_pos, 11_pos}))}));

    return ca;
}

ActionPtr Composer::atArgs()
{
    auto ca = mkDynActionPtr(CompositeAction);

    def::ActionDef actionDef;

    {
        const auto typeDef = def::TypeDef::createIntTypedef();
        def::ArgDef argDef;
        argDef.setType(typeDef);
        argDef.setName("index");
        actionDef.addArgDef(argDef);
    }

    for (size_t i = 0; i < 11; ++i)
    {
        const auto typeDef = def::TypeDef::createStringTypedef();
        def::ArgDef argDef;
        argDef.setType(typeDef);
        argDef.setDefaultValue("");
        actionDef.addArgDef(argDef);
    }

    ca->setActionDef(actionDef);

    ca->setAction(mkActionPtr(AtAction));

    auto mkLstParam = Parameter(mkActionPtr(ArgsToListAction), ParamList({1_pos, 2_pos, 3_pos, 4_pos, 5_pos,
                                                                          6_pos, 7_pos, 8_pos, 9_pos, 10_pos, 11_pos}));

    ca->addParams(ParamList({0_pos, mkLstParam}));

    return ca;
}

ActionPtr Composer::argListBatch()
{
    auto ca = mkDynActionPtr(CompositeAction);

    def::ActionDef actionDef;

    actionDef.setDescription("ARG LIST BATCH");

    {
        const auto typeDef = def::TypeDef::createIntTypedef();
        def::ArgDef argDef;
        argDef.setType(typeDef);
        argDef.setName("index");
        actionDef.addArgDef(argDef);
    }

    {
        const auto typeDef = def::TypeDef::createIntTypedef();
        def::ArgDef argDef;
        argDef.setType(typeDef);
        argDef.setName("number");
        actionDef.addArgDef(argDef);
    }


    for (size_t i = 0; i < 12; ++i)
    {
        const auto typeDef = def::TypeDef::createStringTypedef();
        def::ArgDef argDef;
        argDef.setType(typeDef);
        argDef.setDefaultValue("");
        actionDef.addArgDef(argDef);
    }

    ca->setActionDef(actionDef);

    ca->setAction(mkActionPtr(Batch));

    auto mkLstParam = Parameter(mkActionPtr(ArgsToListAction), ParamList({2_pos, 3_pos, 4_pos, 5_pos, 6_pos,
                                                                          7_pos, 8_pos, 9_pos, 10_pos, 11_pos, 12_pos}));

    ca->addParams(ParamList({0_pos, 1_pos, mkLstParam}));

    return ca;
}

ActionPtr Composer::longArgListBatch()
{
    auto ca = mkDynActionPtr(CompositeAction);

    def::ActionDef actionDef;

    {
        const auto typeDef = def::TypeDef::createIntTypedef();
        def::ArgDef argDef;
        argDef.setType(typeDef);
        argDef.setName("index");
        actionDef.addArgDef(argDef);
    }

    {
        const auto typeDef = def::TypeDef::createIntTypedef();
        def::ArgDef argDef;
        argDef.setType(typeDef);
        argDef.setName("number");
        actionDef.addArgDef(argDef);
    }

    for (size_t i = 0; i < Const::ARG_MAX; ++i)
    {
        const auto typeDef = def::TypeDef::createStringTypedef();
        def::ArgDef argDef;
        argDef.setType(typeDef);
        argDef.setDefaultValue("");
        actionDef.addArgDef(argDef);
    }

    ParamList paramList;
    for (size_t i = 2; i < Const::ARG_MAX; ++i)
    {
        paramList.push_back(Position(i));
    }
    ca->setActionDef(actionDef);

    ca->setAction(mkActionPtr(Batch));

    auto mkLstParam = Parameter(mkActionPtr(ArgsToListAction), paramList);

    ca->addParams(ParamList({0_pos, 1_pos, mkLstParam}));

    return ca;
}

ActionPtr Composer::batches()
{
    auto ca = mkDynActionPtr(CompositeAction);

    def::ActionDef actionDef;

    {
        const auto typeDef = def::TypeDef::createIntTypedef();
        def::ArgDef argDef;
        argDef.setType(typeDef);
        argDef.setName("batchSize");
        actionDef.addArgDef(argDef);
    }

    for (size_t i = 0; i < Const::ARG_MAX; ++i)
    {
        const auto typeDef = def::TypeDef::createStringTypedef();
        def::ArgDef argDef;
        argDef.setType(typeDef);
        argDef.setDefaultValue("");
        actionDef.addArgDef(argDef);
    }

    ParamList paramList({0_val, 0_pos, });
    for (size_t i = 1; i < Const::ARG_MAX; ++i)
    {
        paramList.push_back(Position(i));
    }

    actionDef.setDescription("Batches");
    ca->setActionDef(actionDef);

    ca->setAction(mkActionPtr(ForAction));
    auto argListParam =  Parameter(longArgListBatch(), paramList);

    ca->addParams(ParamList({9_val, 0_val, 0_val, argListParam}));

    return ca;
}

Composer::Composer() {}

} // namespace lst
} // namespace cmd
} // namespace turnip
