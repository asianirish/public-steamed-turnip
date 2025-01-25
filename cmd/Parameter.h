#ifndef PARAMETER_H
#define PARAMETER_H

#include "cmd/Value.h"

namespace turnip {
namespace cmd {

class Substitutor;
using SubstPtr = std::shared_ptr<Substitutor>;

class Parameter
{
public:
    static const int INVALID_POSITION;
    Parameter();
    Parameter(int position);
    Parameter(const Value &value);

    Parameter(const ActionPtr &action);

    Parameter(const SubstPtr &substPtr);

    int position() const;
    void setPosition(int newPosition);

    Value value() const;
    void setValue(const Value &newValue);

    SubstPtr substitutor() const;
    void setSubstitutor(const SubstPtr &newSubstitutor);

private:
    int position_ {INVALID_POSITION};
    Value value_;
    SubstPtr substitutor_;
};

} // namespace cmd
} // namespace turnip

#endif // PARAMETER_H
