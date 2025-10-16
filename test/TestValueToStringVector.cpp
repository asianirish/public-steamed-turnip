#include "TestValueToStringVector.h"

using namespace turnip::cmd;
using namespace turnip::common;

TestValueToStringVector::TestValueToStringVector() {}

turnip::cmd::def::ActionDef TestValueToStringVector::actionDef() const
{
    def::ActionDef actionDef;
    actionDef.setDescription("TestStdComboContainer");

    return actionDef;
}

Value TestValueToStringVector::actImpl(const turnip::cmd::ArgList &args, turnip::cmd::err::Error &error)
{
    (void) args;
    (void) error;

    Value val(std::vector<Value>{"test", 42, 3.14, std::vector<Value>({0, 1, 1, 2, 3, 5, 8, 13, 21, "Fibonacci", 1.618}), 1337});

    auto lst = val.toStringVector();

    std::cout << std::endl << "LIST:" << std::endl;
    for (const auto &str : lst) {
        std::cout << str << std::endl;
    }

    return true;
}
