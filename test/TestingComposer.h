#ifndef TESTINGCOMPOSER_H
#define TESTINGCOMPOSER_H

#include "cmd/Types.h"

class TestingComposer
{
public:

    static turnip::cmd::ActionPtr concatPrint();

    static turnip::cmd::ActionPtr forConcatPrint();

    static turnip::cmd::ActionPtr countTask();

    static turnip::cmd::ActionPtr whileTask();

private:
    TestingComposer();
};

#endif // TESTINGCOMPOSER_H
