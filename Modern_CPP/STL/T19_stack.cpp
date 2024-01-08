#include <iostream>
#include <stack>

int main() {
    std::stack<std::string> s;
    std::cout<<"\nInitial size: "<<s.size();        // list has no capacity()
    
    s.push("Krishna");
    s.push("Dilip");
    s.push("Lagad");
    std::cout<<"\nSize of Stack: "<<s.size(); 

    std::cout<<"\nTop of stack: "<<s.top();
    s.pop();
    std::cout<<"\nTop of stack: "<<s.top();
    std::cout<<"\nEmpty or not: "<<(s.empty() ? "True" : "False");

    std::cout<<"\n";
    return 0;
}