#include <iostream>
#include <algorithm>
#include <string>
#include <list>
#include <vector>

template <typename T>
void display(T& list) {
    std::cout<<"Elements: ";
    for(auto str: list)
        std::cout<<str<<" --> ";
    std::cout<<std::endl;
}

int main() {
    std::vector<std::string> vector = {"Vector", "Krishna", "Lagad", "Bhushan", "Birje"};
    std::list<std::string> list = {"List", "Krishna", "Lagad", "Bhushan", "Birje"};
    display(list);
    display(vector);

    // get max element from list.
    std::list<std::string>::iterator it = std::max_element(std::begin(list), std::end(list));
    std::cout<<"Max element from list: "<<*it<<std::endl;

    // sort the list using algo.
    //std::sort(std::begin(list), std::end(list));    // this is not working, cuz sorting requires random access and in list we can't get random access cuz it is based on doubly LL.
    list.sort();
    display(list);

    auto it_v = std::begin(vector);     // operations allowed: ptr + int, ptr - int, ptr - ptr, ptr++, ptr--, >, <, >=, <=, ==, !=
    auto it_l = std::begin(list);       // operations allowed: ptr++, ptr--, ==, !=
    vector.push_back("Temp");
    list.push_back("Raw");
    ++++it_v;       // pre-increment make changes twice
    (it_l++)++;       // post increment make changes once
    std::cout<<"Vector element: "<<*it_v<<std::endl;
    std::cout<<"List element: "<<*it_l<<std::endl;
    display(list);
    display(vector);

    return 0;
}