#ifndef TESTSTRINGGEN_H
#define TESTSTRINGGEN_H

#include "cmd/SyncAction.h"

class TestStringGen : public turnip::cmd::SyncAction
{
public:
    TestStringGen();

    turnip::cmd::def::ActionDef actionDef() const override;

private:
    turnip::cmd::Value actImpl(const turnip::cmd::ArgList &args, turnip::cmd::err::Error &error) override;
};

#endif // TESTSTRINGGEN_H
