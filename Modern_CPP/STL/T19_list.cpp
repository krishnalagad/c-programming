#include <iostream>
#include <list>

int main() {
    std::list<int> l;
    std::cout<<"\nInitial size: "<<l.size();        // list has no capacity()

    l.push_back(1);
    l.push_front(2);
    std::cout<<"\nSize: "<<l.size(); 
    l.pop_back();
    std::cout<<"\nSize: "<<l.size(); 
    l.pop_front();
    std::cout<<"\nSize: "<<l.size(); 

    l.push_back(1);
    l.push_front(2);
    std::cout<<"\nFirst element of array: "<<l.front();
    std::cout<<"\nLast element of array: "<<l.back();
    // std::cout<<"\nElement at index 1 is "<<l.at(1);  not work for list because it uses doubly linked list
    std::cout<<"\nEmpty or not: "<<(l.empty() ? "True" : "False");

    std::cout<<"\nBefore clear -> Size: "<<l.size();
    l.erase(l.begin());
    std::cout<<"\nAfter clear -> Size: "<<l.size();

    std::cout<<"\n";
    return 0;
}