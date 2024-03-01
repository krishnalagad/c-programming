#include <iostream>
#include <functional>

class Demo {
    private:
        int _id;
    public:
        Demo(int id): _id(id) {}
        ~Demo() {}

        int id() const { return _id; }
};

int main() {
    int n1 = 10;
    Demo d1(10);

    /*
        reference_wrapper eliminates the inconvinience causes by normal wrapper:
        - normal ref dont have memory, but reference_wrapper has memory.
        - normal ref shouldn't assign to other ref var, but reference_wrapper should.
        - normal ref dont get added in container, but reference_wrapper can get added.
    */

    std::reference_wrapper<int> ref = n1;
    std::cout << ref.get() << std::endl;

    // reference wrappper can only store objects which are on stack memory.
    std::reference_wrapper<Demo> dref = d1;

    // get() is used to unwrap the reference_wrapper
    std::cout << dref.get().id() << std::endl;

}