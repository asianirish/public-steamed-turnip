#include "TestLazyPointer.h"
#include "TestCmdValue.h"
#include "TestSharedVector.h"

#include "common/LazyPointer.h"

using namespace turnip::cmd;

TestLazyPointer::TestLazyPointer() {}

turnip::cmd::def::ActionDef TestLazyPointer::actionDef() const
{
    def::ActionDef actionDef;
    actionDef.setDescription("Lazy Pointer Test");
    return actionDef;
}

Value TestLazyPointer::actImpl(const turnip::cmd::ArgList &args, turnip::cmd::err::Error &error)
{
    (void)args;
    (void)error;
    std::cout << "TEST LAZY POINTER" << std::endl;

    turnip::common::LazyPointer<Action> lptr("TestCmdValue");
    lptr->act({});
    std::cout << "*****************************" << std::endl;
    lptr->act({});

    turnip::common::LazyPointer<Action> lptr1("TestSharedVector");
    lptr1->act({});
    std::cout << "*****************************" << std::endl;
    lptr1->act({});

    return true;
}
