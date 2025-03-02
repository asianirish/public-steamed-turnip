#ifndef TESTSHAREDVECTOR_H
#define TESTSHAREDVECTOR_H

#include "cmd/SyncAction.h"

class TestSharedVector : public turnip::cmd::SyncAction
{
public:
    TestSharedVector();

    turnip::cmd::def::ActionDef actionDef() const override;

private:
    turnip::cmd::Value actImpl(const turnip::cmd::ArgList &args, turnip::cmd::err::Error &error) override;
};

#endif // TESTSHAREDVECTOR_H
