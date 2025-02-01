#ifndef TESTSTRINGGEN_H
#define TESTSTRINGGEN_H

#include "cmd/Action.h"

class TestStringGen : public turnip::cmd::Action
{
public:
    TestStringGen();

    turnip::cmd::def::ActionDef actionDef() const override;

private:
    turnip::cmd::Value actImpl(const turnip::cmd::ArgList &args, turnip::cmd::err::Error &error) override;
};

#endif // TESTSTRINGGEN_H
