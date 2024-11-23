#ifndef THISAPP_H
#define THISAPP_H

#include "App.h"

class ThisApp : public turnip::App
{
public:
    static std::string HEX_INT_REPRESENTATION;

    ThisApp();

private:
    void registerActions() override;
    void registerMenu(turnip::cmd::Menu &menu) override;
    turnip::cmd::Translator *createTranslator() const override;
    void registerRepresentaions() override;

    std::string appName() const override;
};

#endif // THISAPP_H
