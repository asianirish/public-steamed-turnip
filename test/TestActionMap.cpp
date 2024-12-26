#include "TestActionMap.h"

using namespace turnip::cmd;

TestActionMap::TestActionMap() {}

turnip::cmd::def::ActionDef TestActionMap::actionDef() const
{
    def::ActionDef actionDef;
    actionDef.setDescription("Action Map Test");

    {
        const auto typeDef = def::TypeDef::createStringTypedef();
        def::ArgDef argDef;
        argDef.setType(typeDef);
        argDef.setName("name");
        argDef.setDefaultValue("Maria");

        actionDef.addArgDef(argDef);
    }

    {
        const auto typeDef = def::TypeDef::createIntTypedef();
        def::ArgDef argDef;
        argDef.setType(typeDef);
        argDef.setName("age");
        argDef.setDefaultValue(18);

        actionDef.addArgDef(argDef);
    }

    {
        const auto typeDef = def::TypeDef::createDoubleTypedef();
        def::ArgDef argDef;
        argDef.setType(typeDef);
        argDef.setName("height");
        argDef.setDefaultValue(1.58);

        actionDef.addArgDef(argDef);
    }

    return actionDef;
}

VariantMap TestActionMap::data() const
{
    VariantMap mp;
    mp.set("name", name_);
    mp.set("age", age_);
    mp.set("height", height_);
    mp.set("gender", gender_);

    return mp;
}

Value TestActionMap::actImpl(const turnip::cmd::ArgList &args, turnip::cmd::err::Error &error)
{
    (void)error;

    name_ = static_cast<std::string>(args.at(0)); // TODO: .toString()
    age_ = static_cast<int64_t>(args.at(1)); // TODO: .toInt()
    height_ = static_cast<double>(args.at(2)); // TODO: .toDouble()
    // TODO: .toChar()

    Value mp = this->toMap();

    return mp;
}
