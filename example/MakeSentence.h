#ifndef MAKESENTENCE_H
#define MAKESENTENCE_H

#include "cmd/Action.h"

namespace turnip {
namespace example {

class MakeSentence : public cmd::Action
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
