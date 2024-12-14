#ifndef APP_H
#define APP_H

#include "cmd/Menu.h"

namespace turnip {

class App
{
public:
    App();

    void init();

    void exec();

protected:
    virtual void registerRepresentaions();

    std::shared_ptr<cmd::Translator> translator();

private:
    virtual void registerActions() = 0;
    virtual void registerMenu(cmd::Menu &menu) = 0;
    virtual const std::shared_ptr<cmd::Translator> createTranslator() const = 0;

    virtual std::string appName() const = 0;
private:
    cmd::Menu mainMenu_;
    std::shared_ptr<cmd::Translator> trnsl_;
};

} // namespace turnip

#endif // APP_H
