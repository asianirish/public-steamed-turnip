#include "TestStringGen.h"
#include "common/HumanStringGenerator.h"

using namespace turnip::cmd;
using namespace turnip::common;

TestStringGen::TestStringGen() {}

turnip::cmd::def::ActionDef TestStringGen::actionDef() const
{
    def::ActionDef actionDef;
    actionDef.setDescription("String Generator Test");
    return actionDef;
}

Value TestStringGen::actImpl(const turnip::cmd::ArgList &args, turnip::cmd::err::Error &error)
{
    (void)args;
    (void)error;

    HumanStringGenerator gen;

    for (std::uint64_t i = 0; i < 10000000; i++) {
        std::cout << gen.generate() << std::endl;
    }

    return true;
}
