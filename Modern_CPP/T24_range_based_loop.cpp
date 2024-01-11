#include <iostream>
#include <vector>

class Employee {
    public:
        int id;
        std::string name;
        Employee(int id, std::string name): id(id), name(name){}
};

void printVector(std::vector<Employee> v) {
    for(Employee e: v)
        std::cout<<e.id<<"  "<<e.name<<std::endl;
    std::cout<<std::endl;
}

int main() {
    std::vector<Employee> v;
    v.push_back(Employee(10, "Krishna"));
    v.push_back(Employee(11, "Bhushan"));
    v.push_back(Employee(12, "Samiksha"));
    printVector(v);
    return 0;
}