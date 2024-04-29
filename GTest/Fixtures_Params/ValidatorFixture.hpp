#ifndef VALIDATORFIXTURE_HPP
#define VALIDATORFIXTURE_HPP

#include <gmock/gmock.h>
#include <functional>
#include <tuple>

#include "LibraryCode.hpp"

using Tuple = std::tuple<int, bool>;
class ValidatorFixture: public testing::TestWithParam<Tuple> {
    protected:
        Validator validator {5,10};
        void SetUp() override {}
        void TearDown() override {}
};

#endif // VALIDATORFIXTURE_HPP
