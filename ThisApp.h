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

    turnip::cmd::ActionPtr sineOfDegrees();
    turnip::cmd::ActionPtr reverseSentence();
    turnip::cmd::ActionPtr doubleReverseSentence();

    turnip::cmd::ActionPtr reverseDivide();

    turnip::cmd::ActionPtr multiPrint();

    turnip::cmd::ActionPtr yesNoPrint();
    turnip::cmd::ActionPtr recursiveYesNo();

    turnip::cmd::ActionPtr recursivePrint();
};

#endif // THISAPP_H
