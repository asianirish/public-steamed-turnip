#ifndef PERSONARGTOMAPACTION_H
#define PERSONARGTOMAPACTION_H

#include "SyncAction.h"

namespace turnip {
namespace cmd {

class PersonArgToMapAction : public SyncAction
{
public:
    PersonArgToMapAction();

    def::ActionDef actionDef() const override;

private:
    Value actImpl(const ArgList &args, err::Error &error) override;
};

} // namespace cmd
} // namespace turnip

#endif // PERSONARGTOMAPACTION_H
