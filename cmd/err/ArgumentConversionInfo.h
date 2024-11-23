#ifndef ARGUMENTCONVERSIONINFO_H
#define ARGUMENTCONVERSIONINFO_H

#include "ArgumentInfo.h"

namespace turnip {
namespace cmd {
namespace err {

class ArgumentConversionInfo : public ArgumentInfo
{
public:
    ArgumentConversionInfo();

    ArgumentConversionInfo(const std::string &type, const std::string &input,
                           int argIndex, const std::string &argName = {});

    std::string type() const;
    void setType(const std::string &newType);

    std::string input() const;
    void setInput(const std::string &newInput);

    std::string description() const override;

private:
    std::string type_; // TODO: string based type
    std::string input_;
};

} // namespace err
} // namespace cmd
} // namespace turnip

#endif // ARGUMENTCONVERSIONINFO_H
