#include "TestToStringVector.h"
#include "cmd/Helper.h"

TestToStringVector::TestToStringVector() {}

turnip::cmd::def::ActionDef TestToStringVector::actionDef() const
{
    turnip::cmd::def::ActionDef actionDef;
    actionDef.setDescription("To String Vector Test");

    const auto typeDef = turnip::cmd::def::TypeDef::createStringTypedef();

    for (int i = 0; i < 10; ++i) {
        turnip::cmd::def::ArgDef argDef;
        argDef.setType(typeDef);
        argDef.setDefaultValue(std::string());
        actionDef.addArgDef(argDef);
    }

    return actionDef;
}

turnip::cmd::Value TestToStringVector::actImpl(const turnip::cmd::ArgList &args, turnip::cmd::err::Error &error)
{
    (void) error;
    std::vector<std::string> resultVector;

    turnip::cmd::Helper::toStringVector(args, resultVector);

    std::cout << "RESULT STRING VECTOR:" << std::endl;
    for (const auto &str: resultVector) {
        if (str.empty()) {
            break;
        }

        std::cout << str << std::endl;
    }

    return args;
}
