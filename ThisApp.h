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

    const std::shared_ptr<turnip::cmd::TaskIdGenerator> createTaskIdGenenerator() const override;

    std::string appName() const override;

    turnip::cmd::LazyAction sineOfDegrees();
    turnip::cmd::LazyAction reverseSentence();
    turnip::cmd::LazyAction doubleReverseSentence();

    turnip::cmd::LazyAction reverseDivide();

    turnip::cmd::LazyAction multiPrint();

    turnip::cmd::LazyAction yesNoPrint();
};

#endif // THISAPP_H
