#include <iostream>
#include <cmath>

template <typename T>
class Container {
    private:
        T param;
    public:
        Container(): param("Default") {}
        Container(T param): param(param) {}
        ~Container() {}

        T getParam() const { return param; }
        void setParam(T &param_) { param = param_; }

        friend std::ostream& operator<<(std::ostream& os, const Container& c) {
            os<<c.getParam();
            return os;
        }
};

template <typename K>
K getSquare(K num) {
    return pow(num, 2);
}

int main(void) {
    Container<std::string> c1 = Container<std::string>("KPIT AutoSAR");
    std::cout<<c1<<"\n";

    Container<int> c2 = Container<int>(987654);
    std::cout<<c2<<"\n";

    std::cout<<getSquare(12)<<"\n";

    double num = 12.23;
    int i = static_cast<int>(num);
    std::cout<<i<<"\n";

    return 0;
}