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

    Parameter actionParam() const;
    void setActionParam(const Parameter &newActionParam);

    ParamList params() const;
    void addParam(const Parameter &param);

    TaskPtr substitue(const ArgList &args);

    VariantMap toMap() const;

private:
    Parameter actionParam_; // TODO: special type for Action and List-Of-Actions params
    ParamList params_;
};

} // namespace cmd
} // namespace turnip

#endif // SUBSTITUTOR_H
