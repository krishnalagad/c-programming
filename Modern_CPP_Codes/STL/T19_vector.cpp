#include <iostream>
#include <vector>

int main() {
    std::vector<int> v;
    std::cout<<"\nInitial capacity: "<<v.capacity()<<"\tInitial size: "<<v.size();

    v.push_back(10);
    std::cout<<"\nCapacity: "<<v.capacity()<<"\tSize: "<<v.size();
    v.push_back(20);
    std::cout<<"\nCapacity: "<<v.capacity()<<"\tSize: "<<v.size();
    v.push_back(30);
    std::cout<<"\nCapacity: "<<v.capacity()<<"\tSize: "<<v.size();
    v.push_back(40);
    std::cout<<"\nCapacity: "<<v.capacity()<<"\tSize: "<<v.size();
    v.push_back(50);
    std::cout<<"\nCapacity: "<<v.capacity()<<"\tSize: "<<v.size();

    std::cout<<"\nFirst element of array: "<<v.front();
    std::cout<<"\nLast element of array: "<<v.back();
    std::cout<<"\nElement at index 2 is "<<v.at(2);
    std::cout<<"\nEmpty or not: "<<(v.empty() ? "True" : "False");

    v.pop_back();
    std::cout<<"\nCapacity: "<<v.capacity()<<"\tSize: "<<v.size();

    for(int i: v)
        std::cout<<"\t"<<i;

    std::cout<<"\nBefore clear -> Capacity: "<<v.capacity()<<"\tSize: "<<v.size();
    v.clear();
    std::cout<<"\nAfter clear -> Capacity: "<<v.capacity()<<"\tSize: "<<v.size();

    std::cout<<"\n";
    return 0;
}