#ifndef CONTEXTUALACTION_H
#define CONTEXTUALACTION_H

#include "cmd/CompositeAction.h"
#include "common/StringGenerator.h"

#include <memory>

namespace turnip {
namespace cmd {

class ContextualAction : public SyncAction
{
public:
    ContextualAction();

    std::shared_ptr<CompositeAction> compositeAction() const;
    void setCompositeAction(const std::shared_ptr<CompositeAction> &newCompositeAction);

    void setStringGen(const std::shared_ptr<common::StringGenerator> &newStringGen);

    Alias registerValue(const Value &value, const std::string &key = {});

    def::ActionDef actionDef() const override;

    std::shared_ptr<Context> context() const;
    void setContext(const std::shared_ptr<Context> &newContext);

private:
    Value actImpl(const ArgList &args, err::Error &error) override;

    VariantMap data() const override;

private:
    std::shared_ptr<CompositeAction> compositeAction_;
    std::shared_ptr<Context> context_;
};

} // namespace cmd
} // namespace turnip

#endif // CONTEXTUALACTION_H
