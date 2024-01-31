#include <iostream>
#include <vector>
#include <functional>

// normal function parameter
// void manager(int (*fn)(int), std::vector<int> data) {
//     for (int val: data)
//         std::cout << fn(val) << std::endl;
// }

// function param using functional programming : modern c++
void manager(std::function<int(int)> fn, std::vector<int> data) {        // type eraser
    for (int val: data)
        std::cout << fn(val) << std::endl;
}

void demo() {
    [](int num) -> int { return num * num; };
}

int square(int num) {
    return num * num;
}

int cube(int num) {
    return num * num * num;
}

// Class implicitly written by compiler for lambda function.
class Lambda {
    private:   
    public:
        Lambda() {}
        ~Lambda() {}
        int operator()(int num) {
            return num * num;
        }
};

// >> g++  -o app && ./app && rm app
int main() {
    std::vector<int> data {1, 2, 3, 4, 5, 6, 7, 8, 9, 100};
    /*
        lambda fucntions are objects and like other objects they have scope so I can 
        control the scope or the visibility of logic. 
        For lambda functions compiler itself creates temporary class for it and override
        () operators because lambda functions are objects.
    */
    std::function<int(int)> f1 = [](int num){ return num * num * num; };
    std::cout << f1(12) << std::endl;
    manager([](int num) -> int { return num * num; }, data);    
}