#include <iostream>
#include <algorithm>
#include <vector>

class Employee {
    int id;
    std::string name;
    int salary;
    
    public:
        Employee() {}
        Employee(int id, std::string name, int salary): id(id), salary(salary), name(name) {}

        int getId() const { return id; }
        void setId(int id_) { id = id_; }

        std::string getName() const { return name; }
        void setName(const std::string &name_) { name = name_; }

        int getSalary() const { return salary; }
        void setSalary(int salary_) { salary = salary_; } 

        friend std::istream& operator>>(std::istream& is, Employee& employee) {
            std::cout<<"Enter id: ";
            is>>employee.id;
            std::cout<<"Enter name: ";
            is>>employee.name;
            std::cout<<"Enter salary: ";
            is>>employee.salary;
            std::cout<<"\n";
            return is;
        }  

        friend std::ostream& operator<<(std::ostream& os, const Employee& employee) {
            os<<"\nEmployee ID: "<<employee.id<<"\nEmployee name: "<<employee.name;
            os<<"\nEmployee salary: "<<employee.salary;
            os<<"\n";
            return os;
        }
};

void addData(std::vector<Employee>& v) {
    // Employee e;
    // std::cin>>e;
    // v.push_back(e);

    // dummy data
    v = { Employee(1, "Krishna Lagad", 25000), Employee(2, "Jack Sparrow", 23000), 
        Employee(3, "Don Bradman", 12000)};
    
}

void display(const std::vector<Employee>& v) {
    std::cout<<"\n-----EMPLOYEE DATA-----"<<std::endl;
    for(const Employee& emp : v )
        std::cout<<emp;
}

void getEmployeeWithMaxSalary(const std::vector<Employee>& v) {
    std::cout<<"\n-----EMPLOYEE WITH MAX SALARY-----"<<std::endl;
    auto it = std::max_element(std::begin(v), std::end(v), [](const Employee& e1, const Employee& e2){
        return e1.getSalary() < e2.getSalary();
    });
    std::cout<<*it;
}

void sortAscVectorBasedOnSalary(std::vector<Employee>& v) {
    std::cout<<"\n-----ASCENDING ORDER ON SALARY-----"<<std::endl;
    std::sort(std::begin(v), std::end(v), [](const Employee& e1, const Employee& e2){
        return e1.getSalary() < e2.getSalary();
    });
    display(v);
}

void sortDescVectorBasedOnSalary(std::vector<Employee>& v) {
    std::cout<<"\n-----DESCEDING ORDER ON SALARY-----"<<std::endl;
    std::sort(std::begin(v), std::end(v), [](const Employee& e1, const Employee& e2){
        return e1.getSalary() > e2.getSalary();
    });
    display(v);
}

void countTotSalGret20k(std::vector<Employee>& v) {
    std::cout<<"\n-----EMPLOYEE WITH SALARY > 20K-----"<<std::endl;
    auto count = std::count_if(std::begin(v), std::end(v), [](const Employee& emp){
        return emp.getSalary() > 20000;
    });
    std::cout<<"Employees with salary greater than 20k: "<<count<<std::endl;
}

void getEmployeeWithNameUpperBound(std::vector<Employee>& v, const std::string& name) {
    std::cout << "\n-----SEARCH EMPLOYEE WITH NAME (UPPER_BOUND())-----" << std::endl;

    Employee targetEmployee;
    targetEmployee.setName(name);

    auto endPtr = std::upper_bound(std::begin(v), std::end(v), targetEmployee, [](const Employee& emp, const Employee& target) {
        return emp.getName() == target.getName();  // Use less-than to establish a strict weak ordering
    });

    if (endPtr != std::end(v) && endPtr->getName() == targetEmployee.getName()) {
        std::string upperName = name;
        std::transform(upperName.begin(), upperName.end(), upperName.begin(), ::toupper);
        std::cout << "Employee found with name " << upperName << std::endl;
        std::cout << *endPtr << std::endl;
    } else {
        std::cout << "No record match with name " << name;
    }
}




void getEmployeeWithNameFindIf(std::vector<Employee>& v, const std::string name) {
    std::cout<<"\n-----SEARCH EMPLOYEE WITH NAME (FIND_IF())-----"<<std::endl;
    Employee e;
    e.setName(name);

    auto it = std::find_if(std::begin(v), std::end(v), [&name](const Employee& emp){
        return name == emp.getName();
    });
    if (!(it == std::end(v))) {
        std::string upperName = name;  // non-const copy for modification
        std::transform(upperName.begin(), upperName.end(), upperName.begin(), ::toupper);
        std::cout<<"Employee found with name "<<upperName<<std::endl;
        std::cout<<*it<<std::endl;
    } else {
        std::cout<<"No record match with name "<<name;
    }
}


int main() {
    std::vector<Employee> v;
    addData(v); addData(v); addData(v);
    display(v);
    getEmployeeWithMaxSalary(v);
    sortAscVectorBasedOnSalary(v);
    sortDescVectorBasedOnSalary(v);
    countTotSalGret20k(v);
    getEmployeeWithNameFindIf(v, "Krishna Lagad");
    getEmployeeWithNameUpperBound(v, "Jack Sparrow");   // this uses binary search, so vector shoud be in sorted order

    return 0;
}