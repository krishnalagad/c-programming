#include <iostream>
#include <array>

class Demo {
    private:
        int _id;
        float _age;
        std::string _name;
        std::array<int, 1000000>&& _arr;
    public:
        Demo(int id, float age, std::string name, std::array<int, 1000000>&& arr)
        : _id(id), _age(age), _name(name), _arr(std::move(arr)) {}
        ~Demo() {
            std::cout<<_arr[0]<<std::endl;
        }
};

/*
    Stack of getInput
    -------------------
    4 bytes for id
    4 bytes for age
    32 bytes for name
    4 million bytes for array
*/
void getInput() {
    int id {-1};
    float age {-1.0f};
    std::string name {""};
    std::array<int, 1000000> data {1};  // actual data is stored in heap, only start and end ptr are created on stack

    std::cin>>id;
    std::cin>>age;
    std::cin>>name;

    Demo(id, age, name, std::move(data));
}

int main() {
    getInput();
    return 0;
}