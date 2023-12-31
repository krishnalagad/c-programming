#include <iostream>

template <typename T>

class Container {
    private:
        T param;
    public:
        Container(): param("Default") {}
        Container(T param): param(param) {}
        ~Container() {}

        T getParam() { return param; }
        void setParam(T &param_) { param = param_; }

        friend std::ostream& operator<<(std::ostream& os, const Container& c) {
            os<<c.param;
            return os;
        }
};

int main(void) {
    Container<std::string> c1 = Container<std::string>("Krishna Lagad");
    std::cout<<c1<<"\n";

    Container<int> c2 = Container<int>(987654);
    std::cout<<c2<<"\n";

    return 0;
}