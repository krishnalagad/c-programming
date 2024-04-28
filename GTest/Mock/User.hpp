#ifndef USER_HPP
#define USER_HPP

#include <string>

class User {
    private:
        int id;
        std::string name;
        float age;
        std::string mobile;
    public:
        User() = delete;
        User(int id_, std::string name_, float age_, std::string mobile_);
        ~User() = default;

        int getId() const { return id; }

        std::string getName() const { return name; }
        void setName(const std::string &name_) { name = name_; }

        float getAge() const { return age; }
        void setAge(float age_) { age = age_; }

        std::string getMobile() const { return mobile; }
        void setMobile(const std::string &mobile_) { mobile = mobile_; }
};

#endif // USER_HPP
