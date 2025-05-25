#ifndef TESTCHANCE_H
#define TESTCHANCE_H

#include "cmd/SyncAction.h"

class TestChance : public turnip::cmd::SyncAction
{
public:
    TestChance();

    turnip::cmd::def::ActionDef actionDef() const override;

private:
    turnip::cmd::Value actImpl(const turnip::cmd::ArgList &args, turnip::cmd::err::Error &error) override;
};

#endif // TESTCHANCE_H
