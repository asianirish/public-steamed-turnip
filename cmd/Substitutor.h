#ifndef SUBSTITUTOR_H
#define SUBSTITUTOR_H

#include "cmd/Types.h"
#include "cmd/Parameter.h"

namespace turnip {
namespace cmd {

class Substitutor
{
public:
    Substitutor();

    Substitutor(const ActionPtr &action, const ParamList &paramList);

    Substitutor(const Alias &alias, const ParamList &paramList);

    Parameter actionParam() const;
    void setActionParam(const Parameter &newActionParam);

    ParamList params() const;
    void addParam(const Parameter &param);

    TaskPtr substitute(const ArgList &args);

    VariantMap toMap() const;

private:
    Parameter actionParam_; // TODO: special type for Action, List-Of-Actions params and Alias
    ParamList params_;
};

} // namespace cmd
} // namespace turnip

#endif // SUBSTITUTOR_H
