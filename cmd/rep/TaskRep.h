#ifndef TASKREP_H
#define TASKREP_H

#include "Representation.h"

namespace turnip {
namespace cmd {
namespace rep {

class TaskRep : public Representation
{
public:
    TaskRep();

    Value input(const std::string &str) const override;
    std::string output(const Value &value) const override;
    std::string repKey() const override;
    def::MetaType metaType() const override;
};

} // namespace rep
} // namespace cmd
} // namespace turnip

#endif // TASKREP_H
