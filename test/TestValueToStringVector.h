#ifndef TESTVALUETOSTRINGVECTOR_H
#define TESTVALUETOSTRINGVECTOR_H

#include "cmd/SyncAction.h"

class TestValueToStringVector : public turnip::cmd::SyncAction
{
public:
    TestValueToStringVector();

    turnip::cmd::def::ActionDef actionDef() const override;

private:
    turnip::cmd::Value actImpl(const turnip::cmd::ArgList &args, turnip::cmd::err::Error &error) override;
};

#endif // TESTVALUETOSTRINGVECTOR_H
