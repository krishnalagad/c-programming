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
    Employee e;
    std::cin>>e;
    v.push_back(e);
}

void display(const std::vector<Employee>& v) {
    for(const Employee& emp : v )
        std::cout<<emp;
}

void getEmployeeWithMaxSalary(const std::vector<Employee>& v) {
    auto it = std::max_element(std::begin(v), std::end(v), [](const Employee& e1, const Employee& e2){
        return e1.getSalary() < e2.getSalary();
    });
    std::cout<<*it;
}

void sortVectorBasedOnSalary(std::vector<Employee>& v) {
    std::sort(std::begin(v), std::end(v), [](const Employee& e1, const Employee& e2){
        return e1.getSalary() < e2.getSalary();
    });
    display(v);
}

int main() {
    std::vector<Employee> v;
    addData(v); addData(v); addData(v);
    display(v);
    getEmployeeWithMaxSalary(v);
    sortVectorBasedOnSalary(v);
    return 0;
}