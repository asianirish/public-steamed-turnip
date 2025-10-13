#include "TestExListComboContainer.h"
#include "common/ExComboContainer.h"

#include <list>

using namespace turnip::cmd;
using namespace turnip::common;

TestExListComboContainer::TestExListComboContainer() {}

def::ActionDef TestExListComboContainer::actionDef() const
{
    def::ActionDef actionDef;
    actionDef.setDescription("TestExListComboContainer");

    return actionDef;
}

Value TestExListComboContainer::actImpl(const turnip::cmd::ArgList &args, turnip::cmd::err::Error &error)
{
    (void) args;
    (void) error;
    ExComboContainer<std::list, char> container(std::vector<std::list<char>>{std::list<char>{'x', 'y', 'z', '@'}, std::list<char>{'5', '6', '7', '8'}});

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
