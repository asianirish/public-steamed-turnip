#ifndef UNARYACTION_H
#define UNARYACTION_H

#include "cmd/Action.h"

namespace turnip {
namespace cmd {

using namespace def;

template<typename T, typename Rep>
class UnaryAction : public Action
{
public:
    UnaryAction() {};

    def::ActionDef actionDef() const final;

private:
    Value actImpl(const ArgList &args, err::Error &error) final;

    virtual T unAct(const T &arg, err::Error &error) = 0;
    virtual std::string argName() const {return {};}
    virtual std::string description() const = 0;
};

template<typename T, typename Rep>
ActionDef UnaryAction<T, Rep>::actionDef() const
{
    ActionDef actionDef;
    auto rep = std::make_shared<Rep>();

    const auto typeDef = TypeDef::createTypedef(rep);

    {
        ArgDef argDef;
        argDef.setType(typeDef);

        if (!argName().empty()) {
            argDef.setName(argName());
        }
        actionDef.addArgDef(argDef);
    }

    actionDef.setDescription(description());


    if (rep->metaType().type() != def::MetaType::Type::Invalid) {
        actionDef.setResultRepresentation(rep);
    }

    return actionDef;
}

template<typename T, typename Rep>
Value UnaryAction<T, Rep>::actImpl(const ArgList &args, err::Error &error)
{
    return unAct(static_cast<T>(args.at(0)), error);
}

} // namespace cmd
} // namespace turnip


#endif // UNARYACTION_H
