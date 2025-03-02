#ifndef BINARYACTION_H
#define BINARYACTION_H

#include "cmd/SyncAction.h"

namespace turnip {
namespace cmd {

using namespace def;

template<typename T, typename Rep>
class BinaryAction : public SyncAction
{
public:
    BinaryAction() {};

    def::ActionDef actionDef() const final;

private:
    Value actImpl(const ArgList &args, err::Error &error) final;

    virtual T binAct(const T &left, const T &right, err::Error &error) = 0;
    virtual std::string description() const = 0;
};

template<typename T, typename Rep>
def::ActionDef BinaryAction<T, Rep>::actionDef() const
{
    ActionDef actionDef;
    auto rep = std::make_shared<Rep>();

    const auto typeDef = TypeDef::createTypedef(rep);

    {
        ArgDef argDef;
        argDef.setType(typeDef);
        argDef.setName("left");
        actionDef.addArgDef(argDef);
    }

    {
        ArgDef argDef;
        argDef.setType(typeDef);
        argDef.setName("right");
        actionDef.addArgDef(argDef);
    }

    actionDef.setDescription(description());


    if (rep->metaType().type() != def::MetaType::Type::Invalid) {
        actionDef.setResultRepresentation(rep);
    }

    return actionDef;
}

template<typename T, typename Rep>
Value BinaryAction<T, Rep>::actImpl(const ArgList &args, err::Error &error)
{
    return binAct(static_cast<T>(args.at(0)), static_cast<T>(args.at(1)), error);
}

} // namespace cmd
} // namespace turnip

#endif // BINARYACTION_H
