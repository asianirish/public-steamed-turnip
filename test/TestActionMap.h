#ifndef TESTACTIONMAP_H
#define TESTACTIONMAP_H

#include "cmd/Action.h"

class TestActionMap : public turnip::cmd::Action
{
public:
    TestActionMap();

    turnip::cmd::def::ActionDef actionDef() const override;

private:
    turnip::cmd::Value actImpl(const turnip::cmd::ArgList &args, turnip::cmd::err::Error &error) override;

    turnip::cmd::VariantMap data() const override;

    std::string name_ {"Maria"};
    int age_ {18};
    double height_ {1.58};
    char gender_ {'f'};
};

#endif // TESTACTIONMAP_H
