#ifndef APP_H
#define APP_H

#include "cmd/Menu.h"
#include "cmd/TaskIdGenerator.h"

namespace turnip {

class App
{
public:
    App();

    virtual ~App() = default;

    void init();

    void exec();

    cmd::TaskPtr executeCommand(const std::string &command, const cmd::ArgList& args);

protected:
    virtual void registerRepresentaions();

    std::shared_ptr<cmd::Translator> translator();

    std::shared_ptr<cmd::TaskIdGenerator> taskIdGenenerator();

    cmd::Menu *mainMenu();

private:
    virtual void specificInit() = 0;
    virtual void registerActions() = 0;
    virtual void registerMenu(cmd::Menu &menu) = 0;
    virtual const std::shared_ptr<cmd::Translator> createTranslator() const = 0;
    virtual const std::shared_ptr<cmd::TaskIdGenerator> createTaskIdGenenerator() const = 0;

    virtual std::string appName() const = 0;
private:
    cmd::Menu mainMenu_;
    std::shared_ptr<cmd::Translator> trnsl_;
    std::shared_ptr<cmd::TaskIdGenerator> taskIdGen_;
};

} // namespace turnip

#endif // APP_H
