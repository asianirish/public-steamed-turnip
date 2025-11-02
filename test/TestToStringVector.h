#ifndef TESTTOSTRINGVECTOR_H
#define TESTTOSTRINGVECTOR_H

#include "cmd/SyncAction.h"

class TestToStringVector : public turnip::cmd::SyncAction
{
public:
    TestToStringVector();

    turnip::cmd::def::ActionDef actionDef() const override;

private:
    turnip::cmd::Value actImpl(const turnip::cmd::ArgList &args, turnip::cmd::err::Error &error) override;
};

#endif // TESTTOSTRINGVECTOR_H
