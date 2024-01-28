#include <iostream>
#include <set>

int main() {
    std::set<int> set = {1, 2, 3, 4, 5};
    set.insert(6);
    set.insert(5);
    set.insert(-1);
    for(int i: set)
        std::cout<<i<<std::endl;
    return 0;
}