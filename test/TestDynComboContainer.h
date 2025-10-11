#ifndef TESTDYNCOMBOCONTAINER_H
#define TESTDYNCOMBOCONTAINER_H

#include "cmd/SyncAction.h"

class TestDynComboContainer : public turnip::cmd::SyncAction
{
public:
    TestDynComboContainer();

    turnip::cmd::def::ActionDef actionDef() const override;

private:
    turnip::cmd::Value actImpl(const turnip::cmd::ArgList &args, turnip::cmd::err::Error &error) override;
};

#endif // TESTDYNCOMBOCONTAINER_H
