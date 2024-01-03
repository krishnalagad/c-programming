#ifndef USER_H
#define USER_H

#include <iostream>
#define SIZE 3

class User {
    private:
        int userId;
        std::string username;
        std::string department;
    public:
        User();     // default
        User(std::string, std::string);     // parameterized

        void display();

        int getUserId() const { return userId; }
        void setUserId(int userId_) { userId = userId_; }

        std::string getUsername() const { return username; }
        void setUsername(const std::string &username_) { username = username_; }

        std::string getDepartment() const { return department; }
        void setDepartment(const std::string &department_) { department = department_; }

        //operator overlading: >>
        friend std::istream& operator>>(std::istream& is, User& user) {
            std::cout<<"\nEnter username: ";
            is>>user.username;
            std::cout<<"\nEnter department: ";
            is>>user.department;
            return is;
        }

        // operator overloading: ==
        bool operator==(User& user) {
            return this->department == user.department;
        }
};

#endif // USER_H
