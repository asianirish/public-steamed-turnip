#include "Composer.h"

#include "cmd/CompositeAction.h"

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
    ca->addParams(ParamList({Parameter(mkActionPtr(ArgsToListAction), ParamList({0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}))}));

    return ca;
}

ActionPtr Composer::argListSize()
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

    ca->setAction(mkActionPtr(SizeAction));
    ca->addParams(ParamList({Parameter(mkActionPtr(ArgsToListAction), ParamList({0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}))}));

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

    auto mkLstParam = Parameter(mkActionPtr(ArgsToListAction), ParamList({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}));

    ca->addParams(ParamList({0, mkLstParam}));

    return ca;
}

ActionPtr Composer::argListBatch()
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

    auto mkLstParam = Parameter(mkActionPtr(ArgsToListAction), ParamList({2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}));

    ca->addParams(ParamList({0, 1, mkLstParam}));

    return ca;
}

Composer::Composer() {}

} // namespace lst
} // namespace cmd
} // namespace turnip
