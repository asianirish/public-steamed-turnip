#include "TestSharedVector.h"
#include "common/SharedVector.h"

using namespace turnip::common;

TestSharedVector::TestSharedVector() {}

turnip::cmd::def::ActionDef TestSharedVector::actionDef() const
{
    return {};
}

turnip::cmd::Value TestSharedVector::actImpl(const turnip::cmd::ArgList &args)
{
    (void)args;
    std::cout << "TEST_SHARED_VECTOR:" << std::endl;

    SharedVector<int> v1(std::vector<int>{1,2,3,4});

    std::cout << "vector #1: {";
    for (const auto &n : v1) {
        std::cout << n << ", ";
    }
    std::cout << "}" << std::endl;
    std::cout << "address of data of v1: ";
    v1.showDataAddress();

    SharedVector<int> v2 = v1;
    std::cout << "vector #2: {";
    for (const auto &n : v2) {
        std::cout << n << ", ";
    }
    std::cout << "}" << std::endl;
    std::cout << "address of data of v2: ";
    v2.showDataAddress();

    std::cout << "\n---------------------\n";
    v2.push_back(777);

    std::cout << "vector #1: {";
    for (const auto &n : v1) {
        std::cout << n << ", ";
    }
    std::cout << "}" << std::endl;
    std::cout << "address of data of v1: ";
    v1.showDataAddress();

    std::cout << "vector #2: {";
    for (const auto &n : v2) {
        std::cout << n << ", ";
    }
    std::cout << "}" << std::endl;
    std::cout << "address of data of v2: ";
    v2.showDataAddress();

    return true;
}