#ifndef DONOTHING_H
#define DONOTHING_H

#include "SyncAction.h"

namespace turnip {
namespace cmd {

class DoNothing : public SyncAction
{
public:
    static const int MAX_DEFAULT_ARGUMENTS;
    DoNothing();

    def::ActionDef actionDef() const override;

private:
    Value actImpl(const ArgList &args, err::Error &error) override;
};

} // namespace cmd
} // namespace turnip

#endif // DONOTHING_H
