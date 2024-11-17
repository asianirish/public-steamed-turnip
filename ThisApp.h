#ifndef THISAPP_H
#define THISAPP_H

#include "App.h"

class ThisApp : public turnip::App
{
public:
    ThisApp();

private:
    void registerActions() override;
    void registerMenu(turnip::cmd::Menu &menu) override;
    turnip::cmd::Translator *createTranslator() const override;
    void registerRepresentaions();
};

#endif // THISAPP_H
