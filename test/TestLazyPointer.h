#ifndef TESTLAZYPOINTER_H
#define TESTLAZYPOINTER_H

#include "cmd/Action.h"

class TestLazyPointer : public turnip::cmd::Action
{
public:
    TestLazyPointer();

    turnip::cmd::def::ActionDef actionDef() const override;

private:
    turnip::cmd::Value actImpl(const turnip::cmd::ArgList &args) override;
};

#endif // TESTLAZYPOINTER_H
