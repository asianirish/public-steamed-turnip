#ifndef TESTLAZYPOINTER_H
#define TESTLAZYPOINTER_H

#include "cmd/SyncAction.h"

class TestLazyPointer : public turnip::cmd::SyncAction
{
public:
    TestLazyPointer();

    turnip::cmd::def::ActionDef actionDef() const override;

private:
    turnip::cmd::Value actImpl(const turnip::cmd::ArgList &args, turnip::cmd::err::Error &error) override;
};

#endif // TESTLAZYPOINTER_H
