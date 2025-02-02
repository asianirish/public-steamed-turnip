#include "ContextualAction.h"
#include "cmd/Context.h"

namespace turnip {
namespace cmd {

ContextualAction::ContextualAction() {
    context_ = Context::create();
}

std::shared_ptr<CompositeAction> ContextualAction::compositeAction() const
{
    return compositeAction_;
}

void ContextualAction::setCompositeAction(const std::shared_ptr<CompositeAction> &newCompositeAction)
{
    compositeAction_ = newCompositeAction;
}

void ContextualAction::setStringGen(const std::shared_ptr<common::StringGenerator> &newStringGen)
{
    context_->setStringGen(newStringGen);
}

Alias ContextualAction::registerValue(const Value &value, const std::string &key)
{
    return context_->registerValue(value, key);
}

def::ActionDef ContextualAction::actionDef() const
{
    if (compositeAction_) {
        return compositeAction_->actionDef();
    }

    return {};
}

Value ContextualAction::actImpl(const ArgList &args, err::Error &error)
{
    if (compositeAction_) {
        return compositeAction_->actImpl(args, error);
    }

    return {};
}

VariantMap ContextualAction::data() const
{
    VariantMap mp;

    mp.set("context", context_->values());
    mp.set("action", compositeAction_->data());

    return mp;
}

std::shared_ptr<Context> ContextualAction::context() const
{
    return context_;
}

void ContextualAction::setContext(const std::shared_ptr<Context> &newContext)
{
    context_ = newContext;
}

} // namespace cmd
} // namespace turnip
