#include "MakeSentence.h"

namespace turnip {
namespace example {

using namespace cmd::def;

MakeSentence::MakeSentence() {}

cmd::Value MakeSentence::actImpl(const cmd::ArgList &args, cmd::err::Error &error)
{
    (void)error;

    return "The " + args.at(0).toString() + " " +
            args.at(1).toString() + "s the " +
           args.at(2).toString() + ".";
}

ActionDef MakeSentence::actionDef() const
{
    ActionDef actionDef;

    const auto typeDef = TypeDef::createStringTypedef();

    {
        ArgDef argDef;
        argDef.setType(typeDef);
        argDef.setName("subject");
        actionDef.addArgDef(argDef);
    }

    {
        ArgDef argDef;
        argDef.setType(typeDef);
        argDef.setName("verb");
        actionDef.addArgDef(argDef);
    }

    {
        ArgDef argDef;
        argDef.setType(typeDef);
        argDef.setName("object");
        actionDef.addArgDef(argDef);
    }


    actionDef.setDescription("Makes a sentence");

    return actionDef;
}

} // namespace example
} // namespace turnip
