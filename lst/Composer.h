#ifndef LST_COMPOSER_H
#define LST_COMPOSER_H

#include "cmd/Types.h"

namespace turnip {
namespace cmd {
namespace lst {

class Composer
{
public:
    static turnip::cmd::ActionPtr concat();

    static turnip::cmd::ActionPtr argListSize();

    static turnip::cmd::ActionPtr atArgs();

    static turnip::cmd::ActionPtr argListBatch();
private:
    Composer();
};

} // namespace lst
} // namespace cmd
} // namespace turnip

#endif // LST_COMPOSER_H
