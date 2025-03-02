#ifndef MAKESENTENCE_H
#define MAKESENTENCE_H

#include "cmd/SyncAction.h"

namespace turnip {
namespace example {

class MakeSentence : public cmd::SyncAction
{
public:
    MakeSentence();

    cmd::def::ActionDef actionDef() const override;

private:
    cmd::Value actImpl(const cmd::ArgList &args, cmd::err::Error &error) override;
};

} // namespace example
} // namespace turnip

#endif // MAKESENTENCE_H
