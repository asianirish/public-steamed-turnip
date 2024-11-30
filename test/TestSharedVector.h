#ifndef TESTSHAREDVECTOR_H
#define TESTSHAREDVECTOR_H

#include "cmd/Action.h"

class TestSharedVector : public turnip::cmd::Action
{
public:
    TestSharedVector();

    turnip::cmd::def::ActionDef actionDef() const override;

private:
    turnip::cmd::Value actImpl(const turnip::cmd::ArgList &args) override;
};

#endif // TESTSHAREDVECTOR_H