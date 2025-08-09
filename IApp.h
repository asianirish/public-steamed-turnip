#ifndef IAPP_H
#define IAPP_H

#include "cmd/TaskManager.h"
#include "cmd/Translator.h"
#include "cmd/TaskIdGenerator.h"

namespace turnip {

class IApp
{
public:
    IApp();

    virtual ~IApp() = default;

protected:

    virtual void specificInit() = 0;
    virtual void registerActions() = 0;

    virtual cmd::TaskManager *taskManager() const = 0;

    virtual const std::shared_ptr<cmd::Translator> createTranslator() const = 0;
    virtual const std::shared_ptr<cmd::TaskIdGenerator> createTaskIdGenenerator() const = 0;

    virtual std::string appName() const = 0;

};

} // namespace turnip


#endif // IAPP_H
