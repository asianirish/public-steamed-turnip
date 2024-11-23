#ifndef APP_H
#define APP_H

#include "cmd/Menu.h"

namespace turnip {

class App
{
public:

    static std::string DEFAULT_NULL_REPRESENTATION;
    static std::string DEFAULT_BOOL_REPRESENTATION;
    static std::string DEFAULT_CHAR_REPRESENTATION;
    static std::string DEFAULT_INT_REPRESENTATION;
    static std::string DEFAULT_STRING_REPRESENTATION;

    App();

    void init();

    void exec();

protected:
    virtual void registerRepresentaions();

private:
    virtual void registerActions() = 0;
    virtual void registerMenu(cmd::Menu &menu) = 0;
    virtual cmd::Translator *createTranslator() const = 0;

    virtual std::string appName() const = 0;
private:
    cmd::Menu mainMenu_;
};

} // namespace turnip

#endif // APP_H
