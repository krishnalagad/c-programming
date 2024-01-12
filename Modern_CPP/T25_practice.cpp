

int main() {
    std::string strArr[] = {"Krishna", "Dilip", "Lagad", "My", "Name"};
    std::sort(std::begin(strArr), std::end(strArr), [](const std::string& s1, const std::string& s2) -> bool {
        return s1.length() < s2.length();
    });

    for(int i = 0; i < 5; i++) {
        std::cout<<strArr[i]<<std::endl;
    }
    std::cout<<std::endl;

    std::vector<Vehicle*> v = {new Vehicle(), new Bike()};
    for(Vehicle* i: v)
        i->show();

    return 0;
}