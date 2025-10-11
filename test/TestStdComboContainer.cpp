#include "TestStdComboContainer.h"
#include "common/StdComboContainer.h"

using namespace turnip::cmd;
using namespace turnip::common;

TestStdComboContainer::TestStdComboContainer() {}

turnip::cmd::def::ActionDef TestStdComboContainer::actionDef() const
{
    def::ActionDef actionDef;
    actionDef.setDescription("TestStdComboContainer");

    return actionDef;
}

Value TestStdComboContainer::actImpl(const turnip::cmd::ArgList &args, turnip::cmd::err::Error &error)
{
    (void) args;
    (void) error;
    StdComboContainer container(std::vector<char>{'a', 'b', 'c', 'd'}, 4);

    std::cout << std::endl;
    for (const auto &itemV : container) {
        std::cout << "ITEM: ";
        for (auto item : itemV) {
        std::cout << item;
        }
        std::cout << std::endl;
    }

    return true;
}
