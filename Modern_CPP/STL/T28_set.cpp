#include <iostream>
#include <set>

int main() {
    std::set<int> set1 = {1, 2, 3, 4, 5, 7, 8, 9, 10, 0};
    std::set<int> set2 = {12, 23, 45, 1, 2, 3, 56};
    set1.insert(6);
    set1.insert(5);
    set1.insert(-1);

    std::set<int>::iterator it = set1.find(4);
    if (it != set1.end()) {
        std::cout << "Element found!!" << std::endl;
        std::set<int>::iterator lower  = set1.lower_bound(4);
        std::set<int>::iterator higher = set1.upper_bound(8);
        set1.erase(lower, higher);
    }

    for(const int& i: set1)
        std::cout << " " << i;
    std::cout<<std::endl;
    std::cout << "Count? : " << set1.count(4) << std::endl;

    // set1.merge(set2);   // this works with c++17 and above. `g++ -std=c++17 T28_set.cpp -o app && ./app && rm app`
    std::cout << "Set1: ";
    for(const int& i: set1)
        std::cout << " " << i;
    std::cout<<std::endl;

    std::cout << "Set2: ";
    for(const int& i: set2)
        std::cout << " " << i;
    std::cout<<std::endl;

    return 0;
}