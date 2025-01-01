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

    {
        const auto typeDef = def::TypeDef::createCharTypedef();
        def::ArgDef argDef;
        argDef.setType(typeDef);
        argDef.setName("gender");
        argDef.setDefaultValue('f');

        actionDef.addArgDef(argDef);
    }

    {
        const auto typeDef = def::TypeDef::createBoolTypedef();
        def::ArgDef argDef;
        argDef.setType(typeDef);
        argDef.setName("student");
        argDef.setDefaultValue(false);

        actionDef.addArgDef(argDef);
    }

    return actionDef;
}

void TestActionMap::setData(const turnip::cmd::VariantMap &data)
{
    name_ = data.get("name").toString();
    age_ = data.get("age").toInt();
    height_ = data.get("height").toDouble();
    gender_ = data.get("gender").toChar();
    student_ = data.get("student").toBool();

}

VariantMap TestActionMap::data() const
{
    VariantMap mp;
    mp.set("name", name_);
    mp.set("age", age_);
    mp.set("height", height_);
    mp.set("gender", gender_);
    mp.set("student", student_);

    return mp;
}

Value TestActionMap::actImpl(const turnip::cmd::ArgList &args, turnip::cmd::err::Error &error)
{
    (void)error;

    name_ = args.at(0).toString();
    age_ = args.at(1).toInt();
    height_ = args.at(2).toDouble();
    gender_ = args.at(3).toChar();
    student_ = args.at(4).toBool();

    Value mp = this->toMap();

    std::cout << "\nMY MAP: " << mp << std::endl;

    VariantMap newMap ({{"name","Margarita"}, {"age", 19}, {"height", 1.685}, {"gender", 'f'}, {"student", true}});
    setData(newMap);

    std::cout << "NEW MAP: " << newMap << std::endl;

    auto cln = this->clone();

    Value clnMp = cln->toMap();

    std::cout << "CLONE MAP: " << newMap << std::endl;
    return true;
}
