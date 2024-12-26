#ifndef TIRNIP_FACTORY_H
#define TIRNIP_FACTORY_H

#include <vector>
#include <string>
#include <unordered_map>
#include <stdexcept>

namespace turnip {
namespace common {

class ClassNotFoundException : public std::runtime_error {
public:
    explicit ClassNotFoundException(const std::string& className)
        : std::runtime_error("Class not found: " + className), m_className(className) {}

    const std::string& className() const {
        return m_className;
    }

private:
    std::string m_className;
};

template <typename BaseClass>
class AbstractCreator
{
public:
    virtual ~AbstractCreator() = default;

    virtual BaseClass *create() const = 0;


    const std::string *registeredClassName() const {
        return &registeredClassName_;
    }
    void setRegisteredClassName(const std::string &newRegisteredClassName) {
        registeredClassName_ = newRegisteredClassName;
    }

private:
    std::string registeredClassName_;
};

template <typename BaseClass, typename DerClass>
class Creator : public AbstractCreator<BaseClass>
{
public:

    BaseClass *create() const override {
        return new DerClass();
    }
};

template <typename BaseClass>
class Factory
{
public:

    static void clear() {
        for (auto pr : creators_) {
            delete pr.second;
        }

        creators_.clear();
    }

    template<typename T>
    static void registerClass(const std::string &className) {
        if (creators_.count(className)) {
            return;
        }

        AbstractCreator<BaseClass> *creator = new Creator<BaseClass,T>();
        creator->setRegisteredClassName(className);
        creators_.insert({className, creator});
    }

    static BaseClass *create(const std::string &className) {
        if (creators_.count(className) == 0) {
            throw ClassNotFoundException(className);
        }

        AbstractCreator<BaseClass>* creator = creators_.at(className);

        if (creator) {
            auto newObject = creator->create();
            newObject->setRegisteredClassName(creator->registeredClassName());
            return newObject;
        }

        return nullptr;
    }

    static bool isRegistered(const std::string &className) {
        return (creators_.count(className) != 0);
    }

    static std::vector<std::string> registeredClasses() {
        std::vector<std::string> vct;

        for (auto pr : creators_) {
            vct.push_back(pr.first);
        }

        return vct;
    }

private:
    static std::unordered_map<std::string, AbstractCreator<BaseClass>*> creators_;
};

template <typename BaseClass>
std::unordered_map<std::string, AbstractCreator<BaseClass>*> Factory<BaseClass>::creators_;


} // namespace common
} // namespace turnip

#define REGISTER_TURNIP_CLASS(BaseClass, DevClass) turnip::common::Factory<BaseClass>::registerClass<DevClass>(#DevClass);

#endif // FACTORY_H
