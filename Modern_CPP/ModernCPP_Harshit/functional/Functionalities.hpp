#ifndef FUNCTIONALITIES_HPP
#define FUNCTIONALITIES_HPP

#include <iostream>
#include <functional>
#include <vector>

using DataContainer = std::vector<int>;
using FnType = std::function<int(DataContainer& data)>;
using FnContainer = std::vector<FnType>;

void makeLambda(FnContainer& fns);
void operation(FnContainer& fns, DataContainer& data);

extern FnType f1;
extern FnType f2;
extern FnType f3;

#endif