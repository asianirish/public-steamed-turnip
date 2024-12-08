#include "TestCmdValue.h"

using namespace turnip::cmd;

TestCmdValue::TestCmdValue() {}

turnip::cmd::def::ActionDef TestCmdValue::actionDef() const
{
    def::ActionDef actionDef;
    actionDef.setDescription("Command Value Test");
    return actionDef;
}

turnip::cmd::Value TestCmdValue::actImpl(const turnip::cmd::ArgList &args, err::Error &error)
{
    (void)args;
    (void)error;
    std::cout << "TEST CMD VALUE" << std::endl;
    std::cout << "...................." << std::endl;

    {
        Value val;
        std::cout << "INVALID VALUE: " << val << std::endl;
    }

    {
        Value val(42);
        std::cout << "INT VALUE: " << val << std::endl;
    }

    {
        Value val(3.14);
        std::cout << "FLOAT VALUE: " << val << std::endl;
    }

    {
        Value val('R');
        std::cout << "CHAR VALUE: " << val << std::endl;
    }

    {
        Value val("¡Hola Mundo!");
        std::cout << "STRING VALUE: " << val << std::endl;
    }

    {
        Value mapVal({{"five", 5}, {"six", 6.6}, {"seven", "siedem"}, {"nine", '9'}});
        Value listVal({5, 6.6, "Siedem", '8'});
        Value val({{"one", 1}, {"two", 2.2}, {"tree", "trzy"}, {"four", '4'}, {"map", mapVal}, {"list", listVal}});
        std::cout << "MAP VALUE: " << val << std::endl;
    }

    {
        Value mapVal({{"one", 1}, {"two", 2.2}, {"tree", "trzy"}, {"four", '4'}});
        Value listVal({5, 6.6, "Siedem", '8'});
        Value val({1, 2.2, "trzy", '4', mapVal, listVal});
        std::cout << "LIST VALUE: " << val << std::endl;
    }

    std::cout << "...................." << std::endl;
    return true;
}
