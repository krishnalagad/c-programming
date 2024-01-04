#include <iostream>
#include <queue>

int main() {
    std::queue<std::string> q;
    std::cout<<"\nInitial size: "<<q.size();        // list has no capacity()

    q.push("Krishna");
    q.push("Dilip");
    q.push("Lagad");
    std::cout<<"\nSize of Stack: "<<q.size(); 
    std::cout<<"\nFirst element: "<<q.front();
    q.pop();
    std::cout<<"\nSize of Stack: "<<q.size(); 
    std::cout<<"\nFirst element: "<<q.front();
    std::cout<<"\nEmpty or not: "<<(q.empty() ? "True" : "False");

    std::cout<<"\n";
    return 0;
}