#ifndef FUNCTIONALITIES_HPP
#define FUNCTIONALITIES_HPP

/*
    Declaration of Functionalities for this project goes here in this file
*/

#include <string>
#include <memory>
#include <vector>
#include <functional>

using DataContainer = std::vector<std::string>;
using FnType = std::function<std::string(DataContainer& data)>;
using FnContainer = std::vector<FnType>;

void createLambda(FnContainer& fns);
void performOperation(FnContainer& fns, DataContainer& data);

extern FnType f1;
extern FnType f2;
extern FnType f3;

#endif // FUNCTIONALITIES_HPP
