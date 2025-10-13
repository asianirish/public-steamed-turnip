#ifndef TESTEXLISTCOMBOCONTAINER_H
#define TESTEXLISTCOMBOCONTAINER_H

#include "cmd/SyncAction.h"

class TestExListComboContainer : public turnip::cmd::SyncAction
{
public:
    TestExListComboContainer();

    turnip::cmd::def::ActionDef actionDef() const override;

private:
    turnip::cmd::Value actImpl(const turnip::cmd::ArgList &args, turnip::cmd::err::Error &error) override;
};

#endif // TESTEXLISTCOMBOCONTAINER_H
