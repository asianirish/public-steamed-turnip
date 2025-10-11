#ifndef TESTSTDCOMBOCONTAINER_H
#define TESTSTDCOMBOCONTAINER_H

#include "cmd/SyncAction.h"

class TestStdComboContainer : public turnip::cmd::SyncAction
{
public:
    TestStdComboContainer();

    turnip::cmd::def::ActionDef actionDef() const override;

private:
    turnip::cmd::Value actImpl(const turnip::cmd::ArgList &args, turnip::cmd::err::Error &error) override;
};

#endif // TESTSTDCOMBOCONTAINER_H
