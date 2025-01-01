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

    Parameter actionParam() const;
    void setActionParam(const Parameter &newActionParam);

    ParamList params() const;
    void addParam(const Parameter &param);

    TaskPtr substitue(const ArgList &args);
private:
    Parameter actionParam_;
    ParamList params_;
};

} // namespace cmd
} // namespace turnip

#endif // SUBSTITUTOR_H
