#ifndef PRINTACTION_H
#define PRINTACTION_H

#include "SyncAction.h"

#include <mutex>

namespace turnip {
namespace cmd {

class PrintAction : public SyncAction
{
public:
    PrintAction();

    def::ActionDef actionDef() const override;

private:
    Value actImpl(const ArgList &args, err::Error &error) override;

    static std::mutex mutex_;
};

} // namespace cmd
} // namespace turnip

#endif // PRINTACTION_H
