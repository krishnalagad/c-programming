#include <iostream>
#include <set>

int main() {
    std::set<int> set = {1, 2, 3, 4, 5};
    set.insert(6);
    set.insert(5);
    set.insert(-1);

    std::set<int>::iterator it = set.find(4);
    if (it != set.end()) {
        std::cout << "Element found!!" << std::endl;
        set.erase(4);
    }

    for(int i: set)
        std::cout<<i<<std::endl;
    std::cout << "Count? : " << set.count(4) << std::endl;
    
    return 0;
}