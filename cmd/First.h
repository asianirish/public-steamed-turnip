#ifndef FIRST_H
#define FIRST_H

#include "SyncAction.h"

namespace turnip {
namespace cmd {

class First : public SyncAction
{
public:
    First();

    def::ActionDef actionDef() const override;

private:
    Value actImpl(const ArgList &args, err::Error &error) override;
};

} // namespace cmd
} // namespace turnip

#endif // FIRST_H
