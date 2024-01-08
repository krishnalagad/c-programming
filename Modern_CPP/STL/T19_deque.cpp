#include <iostream>
#include <deque>

int main() {
    std::deque<int> d;
    std::cout<<"\nInitial size: "<<d.size();    // deque has no capacity()

    d.push_back(1);
    d.push_front(2);
    std::cout<<"\nSize: "<<d.size(); 
    d.pop_back();
    std::cout<<"\nSize: "<<d.size(); 
    d.pop_front();
    std::cout<<"\nSize: "<<d.size(); 

    d.push_back(1);
    d.push_front(2);
    std::cout<<"\nFirst element of array: "<<d.front();
    std::cout<<"\nLast element of array: "<<d.back();
    std::cout<<"\nElement at index 1 is "<<d.at(1);
    std::cout<<"\nEmpty or not: "<<(d.empty() ? "True" : "False");

    std::cout<<"\nBefore clear -> Size: "<<d.size();
    d.erase(d.begin(), d.begin() + 1);
    std::cout<<"\nAfter clear -> Size: "<<d.size();

    std::cout<<"\n";
    return 0;
}