#ifndef FUNCTIONALITIES_HPP
#define FUNCTIONALITIES_HPP

#include <stack>
#include "Reading.hpp"

using Container = std::stack<Reading>;

/*
    This factory function takes lvalue reference of Container where Container is
    standard stack of Reading class and returns void.
*/
void createObjects(Container& data);

#endif // FUNCTIONALITIES_HPP
