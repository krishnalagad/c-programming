#include <functional>
#include <iostream>

class Krishna {
    private:
        float _height {0.0f};
        float _weight {0.0f};
        std::string&& _color {"white"};
        
    public:
        Krishna() = delete;
        Krishna(float height, float weight, std::string color): _height(height), _weight(weight), _color(std::move(color)) {
            std::cout << "_height: " << this->_height
                        << ", _weight: " << this->_weight
                        << ", _color: " << this->_color
                        << "\n";
        }
        Krishna(const Krishna& krish) { std::cout << "Copy constructor!!\n"; }
        Krishna(Krishna&& krish) { std::cout << "Move construtor!!\n"; }
        ~Krishna() = default;

        friend std::ostream &operator<<(std::ostream &os, const Krishna &rhs) {
            os << "_height: " << rhs._height
            << ", _weight: " << rhs._weight
            << ", _color: " << rhs._color;
            return os;
        }
};

template<typename T, typename... Args>
T middleware(Args&&... args) {
    return T(std::forward<Args>(args)...);
}

/*
    g++ object_reference.cpp -o app && time ./app && rm app
*/
int main() {
    const Krishna krish = middleware<Krishna>(5.9f, 69.0f, "Brown");
    middleware<Krishna>(std::move(krish));
    middleware<Krishna>(std::ref(krish));
    middleware<Krishna>(krish);
    return 0;
}
