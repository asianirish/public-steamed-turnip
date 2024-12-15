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
    const std::shared_ptr<turnip::cmd::Translator> createTranslator() const override;
    void registerRepresentaions() override;

    std::string appName() const override;

    turnip::cmd::LazyAction sineOfDegrees();
};

#endif // THISAPP_H
