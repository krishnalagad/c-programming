#ifndef DEMO_HPP
#define DEMO_HPP

#include <iostream>

class Demo {
    private:
        std::string name;
        int id;
        float age;
    public:
        Demo() = delete;
        Demo(std::string name_, int id_, float age_): name(name_), id(id_), age(age_) {}
        ~Demo() = default;

        std::string getName() const { return name; }
        void setName(const std::string &name_) { name = name_; }

        int getId() const { return id; }
        void setId(int id_) { id = id_; }

        float getAge() const { return age; }
        void setAge(float age_) { age = age_; }

        friend std::ostream &operator<<(std::ostream &os, const Demo &rhs) {
            os << "name: " << rhs.name
               << ", id: " << rhs.id
               << ", age: " << rhs.age
               << "\n";
            return os;
        }
};

#endif // DEMO_HPP
