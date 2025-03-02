#ifndef TESTCMDVALUE_H
#define TESTCMDVALUE_H

#include "cmd/SyncAction.h"

class TestCmdValue : public turnip::cmd::SyncAction
{
public:
    TestCmdValue();

    turnip::cmd::def::ActionDef actionDef() const override;

private:
    turnip::cmd::Value actImpl(const turnip::cmd::ArgList &args, turnip::cmd::err::Error &error) override;
};

#endif // TESTCMDVALUE_H
