#include "Functionalities.hpp"
#include "CustomMessageException.hpp"
#include <algorithm>
#include <iostream>

/*
    Implementation of all the functionalities of this project goes here in this file
*/

/*
    This function takes lvalue reference of FnContainer where FnContainer is vector of DataContainer
    and DataContainer is vector od string
    and returns void.
*/
void createLambda(FnContainer &fns) {

    /*
        Implementation if 1st lambda function
    */
    auto f1 = [](DataContainer& data) -> std::string {
        if (data.empty()) 
            throw CustomMessageException("Data Container is empty!!");

        auto element = std::min_element(data.begin(), data.end(), [](const std::string& s1, const std::string& s2){
            return s1.length() < s2.length();
        });
        return *element;
    };

    /*
        Implementation if 2nd lambda function
    */
    auto f2 = [](DataContainer& data) -> std::string {
        if (data.empty()) 
            throw CustomMessageException("Data Container is empty!!");

        std::string result;
        for(std::string str: data) {
            // Convert the string to lowercase
            std::transform(str.begin(), str.end(), str.begin(), ::tolower);
            
            bool hasVowel = false;
            for (int i = 0; i < str.length(); i++) {
                // Check if the character is a vowel
                if(str.at(i) == 'a' || str.at(i) == 'e' || str.at(i) == 'i' || str.at(i) == 'o' || str.at(i) == 'u') {
                    hasVowel = true;
                    break;
                }
            }
            // If the string doesn't have a vowel, update the result
            if (!hasVowel) {
                result = str;
                break; 
            }
        }
        return result;
    };



    /*
        Implementation if 3rd lambda function
    */
    auto f3 = [](DataContainer& data) -> std::string {
        if (data.empty()) 
            throw CustomMessageException("Data Container is empty!!");

        // get string at 2nd position
        return data.at(1);
    };

    // Push all the lambda functions to DataContainer
    fns.push_back(f1);
    fns.push_back(f2);
    fns.push_back(f3);
}


/*
    This function takes lvalue reference of FnContainer, DataContainer where FnContainer is vector of DataContainer
    and DataContainer is vector of string.
    and returns void.
*/
void performOperation(FnContainer &fns, DataContainer &data) {
    int cnt = 0;
    for (const FnType& fn: fns) {
        std::cout << "Output of Lambda fn" << ++cnt << ":  " << fn(data) << std::endl;
    }
}
