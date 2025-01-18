#ifndef DONOTHING_H
#define DONOTHING_H

#include "Action.h"

namespace turnip {
namespace cmd {

class DoNothing : public Action
{
public:
    static const int MAX_DEFAULT_ARGUMENTS;
    DoNothing();

    // Action interface
public:
    def::ActionDef actionDef() const override;

private:
    Value actImpl(const ArgList &args, err::Error &error) override;
};

} // namespace cmd
} // namespace turnip

#endif // DONOTHING_H
