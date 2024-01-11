#include <iostream>
#include <algorithm>
#include <stack>
#include <string>

void reverseString(std::string str) {
    std::stack<char> s;
    for(char ch: str) {
        if (ch != ' ') 
            s.push(ch);
        
        else if (ch == ' ') {
            while (s.empty() == false){
                std::cout<<s.top();
                s.pop();
            } 
            std::cout<<" ";
        } 
    }
    while (!s.empty()) {
        std::cout << s.top();
        s.pop();
    }
    std::cout<<std::endl;
}

bool isValidBrackets2(std::string str) {
    std::stack<char> s;
    for (char ch: str) {
        if (ch == '(' || ch == '{' || ch == '[')
            s.push(ch);
        else if (ch == '}' || ch == ')' || ch == ']') {
            if (s.top() == '{' && ch == '}' || s.top() == '[' && ch == ']' || s.top() == '(' && ch == ')') 
                s.pop();
            else 
                return false;
        } 
    }
    if (!s.empty())
        return false;
    return true;
}

bool isValidBrackets(std::string s) {
    std::stack<char> st;
    for (char ch : s) {
        if (ch == '(') 
            st.push(')');
        else if (ch == '{') 
            st.push('}');
        else if (ch == '[') 
            st.push(']');
        else if (!st.empty() && st.top() == ch) 
            st.pop();
        else 
            return false;  
    }
    if (!st.empty()) 
        return false;

    return true;
}

int main() {
    std::stack<std::string> s;
    std::cout<<"Size: "<<s.size()<<std::endl;
    s.push("Krishna");
    s.push("Dilip");
    s.push("Lagd");
    std::cout<<"Size: "<<s.size()<<std::endl;

    std::cout<<"isValidBrackets: "<<(isValidBrackets("({[]})") ? "YES" : "NO")<<std::endl;
    std::cout<<"isValidBrackets2: "<<(isValidBrackets2("({[]})") ? "YES" : "NO")<<std::endl;
    reverseString("My name is Krishna Lagad");

    return 0;
}