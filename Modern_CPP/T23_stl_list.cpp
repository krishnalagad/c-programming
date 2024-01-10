#include <iostream>
#include <algorithm>
#include <string>
#include <list>
#include <vector>

void display(std::list<std::string>& list) {
    std::cout<<"List elements: ";
    for(std::string str: list)
        std::cout<<str<<" --> ";
    std::cout<<std::endl;
}

int main() {
    std::vector<std::string> vector = {"Krishna", "Lagad", "Bhushan", "Birje"};
    std::list<std::string> list = {"Krishna", "Lagad", "Bhushan", "Birje"};
    display(list);

    // get max element from list.
    std::list<std::string>::iterator it = std::max_element(std::begin(list), std::end(list));
    std::cout<<"Max element from list: "<<*it<<std::endl;

    // sort the list using algo.
    //std::sort(std::begin(list), std::end(list));    // this is not working, cuz sorting requires random access and in list we can't get random access cuz it is based on doubly LL.
    list.sort();
    display(list);

    auto it_v = std::begin(vector);     // operations allowed: ptr + int, ptr - int, ptr - ptr, ptr++, ptr--, >, <, >=, <=, ==, !=
    auto it_l = std::begin(list);       // operations allowed: ptr++, ptr--, ==, !=
    ++++it_v;       // pre-increment make changes twice
    (it_l++)++;       // post increment make changes once
    std::cout<<"Vector element: "<<*it_v<<std::endl;
    std::cout<<"List element: "<<*it_l<<std::endl;

    return 0;
}