#ifndef APP_H
#define APP_H

#include "IApp.h"
#include "cmd/Menu.h"

namespace turnip {

class App : public IApp
{
public:
    App();

    virtual ~App() = default;

    void init();

    void exec();

    cmd::TaskPtr executeCommand(const std::string &command, const cmd::ArgList& args);

protected:
    virtual void registerMenu(cmd::Menu &menu) = 0;

    virtual void registerRepresentaions();

    std::shared_ptr<cmd::Translator> translator();

    std::shared_ptr<cmd::TaskIdGenerator> taskIdGenenerator();

    cmd::Menu *mainMenu();

    cmd::TaskManager *taskManager() const override; // TODO: implement in CmdMenuApp

private:
    cmd::Menu mainMenu_; // TODO: make CmdMenuApp class
    std::shared_ptr<cmd::Translator> trnsl_;
    std::shared_ptr<cmd::TaskIdGenerator> taskIdGen_;
};

} // namespace turnip

#endif // APP_H
