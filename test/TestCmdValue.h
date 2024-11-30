#ifndef TESTCMDVALUE_H
#define TESTCMDVALUE_H

#include "cmd/Action.h"

class TestCmdValue : public turnip::cmd::Action
{
public:
    TestCmdValue();

    turnip::cmd::def::ActionDef actionDef() const override;

private:
    turnip::cmd::Value actImpl(const turnip::cmd::ArgList &args) override;
};

#endif // TESTCMDVALUE_H
