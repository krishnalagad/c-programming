#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Employee {
    private:
        int id;
        std::string name;
    public:
        Employee() = default;
        Employee(int id, std::string name): id(id), name(name) {} 
        friend std::istream& operator>> (std::istream& is, Employee& e) {
            std::cout<<"\nEnter ID: ";
            is>>e.id;
            std::cout<<"\nEnter name: ";
            is>>e.name;
            return is;
        }
        friend std::ostream& operator<< (std::ostream& is, const Employee& e) {
            is<<"\nID: "<<e.id;
            is<<"\nName: "<<e.name;
            return is;
        }
        bool operator<(const Employee& other) const {
            return id < other.id;
        }
        // bool compareEmployees(const Employee& a, const Employee& b) {
        //     return a.id < b.id; // Assuming getId() is a member function that returns the ID.
        // }
};

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

    // std::cout<<"\nAUTO ITERATOR TRY 1\n";
    // tryVector();

    // std::cout<<"\nAUTO ITERATOR TRY 2\n";
    // tryVector2();

    std::cout<<"\nAUTO ITERATOR TRY 3\n";
    tryVectorWithObjectsAndUpperBound();

    return 0;
}