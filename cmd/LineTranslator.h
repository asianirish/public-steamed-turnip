#ifndef LINETRANSLATOR_H
#define LINETRANSLATOR_H

#include "Translator.h"

namespace turnip {
namespace cmd {

class LineTranslator : public Translator
{
public:
    LineTranslator();

    Info translate(const std::string &in) const override;
};

} // namespace cmd
} // namespace turnip

#endif // LINETRANSLATOR_H
