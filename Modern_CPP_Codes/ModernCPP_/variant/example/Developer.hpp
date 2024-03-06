#ifndef DEVELOPER_HPP
#define DEVELOPER_HPP

#include <string>
#include <ostream>

class Developer {
    private:
        std::string _devDepartment;
        int _tasksAssigned;

    public:
        Developer(const std::string& devDepartment, int tasksAssigned)
            : _devDepartment(devDepartment), _tasksAssigned(tasksAssigned) {}

        const std::string& getDevDepartment() const { return _devDepartment; }
        int getTasksAssigned() const { return _tasksAssigned; }

        friend std::ostream &operator<<(std::ostream &os, const Developer &rhs);
};

inline std::ostream &operator<<(std::ostream &os, const Developer &rhs) {
    os << "_devDepartment: " << rhs._devDepartment
       << " _tasksAssigned: " << rhs._tasksAssigned;
    return os;
}

#endif // DEVELOPER_HPP
