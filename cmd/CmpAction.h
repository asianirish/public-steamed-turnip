#ifndef CMPACTION_H
#define CMPACTION_H

#include "Action.h"

namespace turnip {
namespace cmd {

using namespace def;

template<typename T, typename Rep>
class CmpAction : public Action
{
public:
    CmpAction() {}

    def::ActionDef actionDef() const final;

private:
    Value actImpl(const ArgList &args, err::Error &error) final;

    virtual bool cmpAct(const T &left, const T &right, err::Error &error) = 0;
    virtual std::string description() const = 0;
};

template<typename T, typename Rep>
ActionDef CmpAction<T, Rep>::actionDef() const
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

    auto boolRep = std::make_shared<BoolRep>(BoolRep::Kind::YesNo);
    actionDef.setResultRepresentation(boolRep);
    actionDef.setDescription(description());


    if (rep->metaType().type() != def::MetaType::Type::Invalid) {
        actionDef.setResultRepresentation(rep);
    }

    return actionDef;
}

template<typename T, typename Rep>
Value CmpAction<T, Rep>::actImpl(const ArgList &args, err::Error &error)
{
    return cmpAct(static_cast<T>(args.at(0)), static_cast<T>(args.at(1)), error);
}

} // namespace cmd
} // namespace turnip

#endif // CMPACTION_H
