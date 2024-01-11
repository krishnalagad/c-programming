#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// auto str = 10;   // allowed here

class Employee {
    private:
        int id;
        std::string name;
        int salary;
    public:
        Employee() = default;
        Employee(int id, std::string name): id(id), name(name) {} 
        friend std::istream& operator>> (std::istream& is, Employee& e) {
            std::cout<<"\nEnter ID: ";
            is>>e.id;
            std::cout<<"\nEnter name: ";
            is>>e.name;
            std::cout<<"\nEnter salary: ";
            is>>e.salary;
            return is;
        }
        friend std::ostream& operator<< (std::ostream& is, const Employee& e) {
            is<<"\nID: "<<e.id;
            is<<"\nName: "<<e.name;
            is<<"\nSalary: "<<e.salary;
            return is;
        }
        bool operator<(const Employee& other) const {
            return salary > other.salary;
        }

        int getSalary() const { return salary; }
        void setSalary(int salary_) { salary = salary_; }
};

void tryVector3() {
    std::vector<Employee> v;
    int size = 2;
    Employee ele;
    for(int i = 0; i < size; i++) {
        std::cin>>ele;
        v.push_back(ele);
    }

    auto it = v.begin();
    std::cout<<std::endl;
    for(it = v.begin(); it != v.end(); it++)
        std::cout<<*it<<" ";
    std::cout<<std::endl;

    std::cout<<"\nMax Element: ";
    // it = std::max_element(v.begin(), v.end());      
    it = std::max_element(v.begin(), v.end(), [](const Employee& a, const Employee& b) {
        return a.getSalary() < b.getSalary();   // get max value based on saalary of employee
    });
    std::cout<<*it;

    std::sort(v.begin(), v.end());      // sort based on salary of employee
    std::cout<<std::endl;
    for(it = v.begin(); it != v.end(); it++)
        std::cout<<*it<<" ";
    std::cout<<std::endl;
}

void tryVectorWithObjectsAndUpperBound() {
    std::vector<Employee> v;

    int size = 2;
    Employee ele;
    auto it = v.begin();
    for(int i = 0; i < size; i++) {
        std::cin>>ele;
        it = std::upper_bound(std::begin(v), std::end(v), ele);
        v.insert(it, ele);
    }

    std::cout<<std::endl;
    for(it = v.begin(); it != v.end(); it++)
        std::cout<<*it<<" ";
    std::cout<<std::endl;

    // it = std::max_element(v.begin(), v.end());      
    it = std::max_element(v.begin(), v.end(), [](const Employee& a, const Employee& b) {
        return a.getSalary() < b.getSalary();   // get max value based on ID of employee
    });
    std::cout<<*it;

    std::sort(v.begin(), v.end());      // sort based on salary of employee
    std::cout<<std::endl;
    for(it = v.begin(); it != v.end(); it++)
        std::cout<<*it<<" ";
    std::cout<<std::endl;
}

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

    std::cout<<"Enter element to delete: ";
    int key;
    std::cin>>key;
    it = std::find(v.begin(), v.end(), key);
    if(it == v.end())
        std::cout<<"\nElement is not present in vector to delete!!";
    else    
        v.erase(it);

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
    auto it = v.begin();    // while using auto keyword, it requires initialisation on the same line

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

    std::cout<<"\nAUTO ITERATOR TRY 3 WITH UPPER BOUND\n";
    tryVectorWithObjectsAndUpperBound();

    std::cout<<"\nAUTO ITERATOR TRY 4 WITH PUSH BACK\n";
    tryVector3();

    return 0;
}