#ifndef FUNCTIONALITIES_HPP
#define FUNCTIONALITIES_HPP

#include <array>
#include <thread>
#include <iostream>
#include <vector>
#include <future>

using Container = std::array<std::thread, 4>;

/*
    Function takes lvalue reference of Container where Container is arry of threads
    and returns void
*/
void createThreads(Container& threads, int f1_param, std::vector<int>& f2_param, std::array<int, 5>& f3_param, std::array<int, 5>& f4_param);

/*
    Function to print sum of first N positive integers
*/
void printSumOfNNumbers(int n);

/*
    Function to print sum of first N positive integers
*/
void displayEvenNumbersInVector(const std::vector<int>& data);

/*
    Function generates 5 integers starting from value N
*/
void generateAndDisplayIntegers(std::promise<int>& ft);

/*
    Function to generate and store squares
*/
void generateAndStoreSquares(std::array<int, 5>& arr);

/*  
    Function to generate and store cubes
*/
void generateAndStoreCube(std::array<int, 5>& data);



#endif // FUNCTIONALITIES_HPP
