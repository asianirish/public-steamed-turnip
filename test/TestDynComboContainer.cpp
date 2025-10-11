#include "TestDynComboContainer.h"
#include "common/DynComboContainer.h"

using namespace turnip::cmd;
using namespace turnip::common;

TestDynComboContainer::TestDynComboContainer() {}

turnip::cmd::def::ActionDef TestDynComboContainer::actionDef() const
{
    def::ActionDef actionDef;
    actionDef.setDescription("TestDynComboContainer");

    return actionDef;
}

Value TestDynComboContainer::actImpl(const turnip::cmd::ArgList &args, turnip::cmd::err::Error &error)
{
    (void) args;
    (void) error;
    DynComboContainer container(std::vector<std::vector<char>>{std::vector<char>{'a', 'b', 'c', 'd'}, std::vector<char>{'1', '2', '3', '4'}});

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
