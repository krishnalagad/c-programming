#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// this is working fine!!
void tryVector2() {
    std::vector<int> v;

    int size = 4;
    int ele;
    auto it = v.begin();
    for(int i = 0; i < size; i++) {
        std::cout<<"\nEnter data "<<(i + 1)<<": ";
        std::cin>>ele;
        it = std::upper_bound(std::begin(v), std::end(v), ele);
        v.insert(it, ele);
    }

    std::cout<<std::endl;
    for(it = v.begin(); it != v.end(); it++)
        std::cout<<*it<<" ";
    std::cout<<std::endl;
}

void tryVector() {
    std::vector<int> v;

    int ele = 10;
    auto it = std::upper_bound(std::begin(v), std::end(v), ele);
    v.insert(it, ele);

    ele = 20;
    it = std::upper_bound(std::begin(v), std::end(v), ele);
    v.insert(it, ele);

    ele = 30;
    it = std::upper_bound(std::begin(v), std::end(v), ele);
    v.insert(it, ele);

    std::cout<<std::endl;
    for(it = v.begin(); it != v.end(); it++)
        std::cout<<*it<<" ";
    std::cout<<std::endl;
}

int main() {
    std::vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    // std::vector<int>::iterator it;
    // it = v.begin();
    auto it = v.begin();    // use auto keyword, it requires initialisation on the same line

    // accessing elements of vector using iterator.
    std::cout<<*it<<std::endl;
    // *it += 1;   // not-allowed : this will make increment in previous value of *it, not in the pointer.
    // it++;       // allowed : get the next element
    // it += 1;    // allowed : get the next element
    *it++;      // allowed : get the next element
    std::cout<<*it<<std::endl;

    std::cout<<std::endl;
    for(it = v.begin(); it != v.end(); it++)
        std::cout<<*it<<" ";

    v.insert(it, 100);
    std::cout<<std::endl;
    for(it = v.begin(); it != v.end(); it++)
        std::cout<<*it<<" ";

    std::cout<<"\nAUTO ITERATOR TRY 1\n";
    tryVector();

    std::cout<<"\nAUTO ITERATOR TRY 2\n";
    tryVector2();

    return 0;
}