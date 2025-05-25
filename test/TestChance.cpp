#include "TestChance.h"
#include "common/RandomUtils.h"

using namespace turnip::cmd;
using namespace turnip::common;


TestChance::TestChance() {}

turnip::cmd::def::ActionDef TestChance::actionDef() const
{
    def::ActionDef actionDef;
    actionDef.setDescription("Test Chance Action");

    {
        const auto typeDef = def::TypeDef::createIntTypedef();
        def::ArgDef argDef;
        argDef.setType(typeDef);
        argDef.setName("numerator");
        argDef.setDefaultValue(1);

        actionDef.addArgDef(argDef);
    }

    {
        const auto typeDef = def::TypeDef::createIntTypedef();
        def::ArgDef argDef;
        argDef.setType(typeDef);
        argDef.setName("denominator");
        argDef.setDefaultValue(2);

        actionDef.addArgDef(argDef);
    }

    return actionDef;
}

Value TestChance::actImpl(const turnip::cmd::ArgList &args, turnip::cmd::err::Error &error)
{
    (void) error;
    auto numerator = args.at(0).toInt();
    auto denominator = args.at(1).toInt();

    {
        int countYes = 0;
        int countNo = 0;

        for (int i = 0; i < 10000000; ++i) {
            if (RandomUtils::chance(numerator, denominator)) {
                countYes++;
            } else {
                countNo++;
            }
        }

        std::cout << std::endl << ".............................." << std::endl;
        std::cout << "YESes: " << countYes << std::endl;
        std::cout << "NOs: " << countNo << std::endl;
        std::cout << "Chance Proportion: " << static_cast<double>(countYes)/static_cast<double>(countYes + countNo);

    }

    {
        int countYes = 0;
        int countNo = 0;

        for (int i = 0; i < 10000000; ++i) {
            if (RandomUtils::chance_bernoulli(static_cast<double>(numerator) / static_cast<double>(denominator))) {
                countYes++;
            } else {
                countNo++;
            }
        }

        std::cout << std::endl << ".............................." << std::endl;
        std::cout << "YESes: " << countYes << std::endl;
        std::cout << "NOs: " << countNo << std::endl;
        std::cout << "Bernoulli Chance Proportion: " << static_cast<double>(countYes)/static_cast<double>(countYes + countNo);

    }

    {
        int countYes = 0;
        int countNo = 0;

        for (int i = 0; i < 10000000; ++i) {
            if (RandomUtils::chance_uniform(static_cast<double>(numerator) / static_cast<double>(denominator))) {
                countYes++;
            } else {
                countNo++;
            }
        }

        std::cout << std::endl << ".............................." << std::endl;
        std::cout << "YESes: " << countYes << std::endl;
        std::cout << "NOs: " << countNo << std::endl;
        std::cout << "Uniform Chance Proportion: " << static_cast<double>(countYes)/static_cast<double>(countYes + countNo);

    }

    std::cout << std::endl << ".............................." << std::endl;
    return true;

}
