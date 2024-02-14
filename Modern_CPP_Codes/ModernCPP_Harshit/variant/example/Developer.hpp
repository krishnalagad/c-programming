#ifndef DEVELOPER_HPP
#define DEVELOPER_HPP

#include <string>

class Developer {
private:
    std::string _devDepartment;
    int _tasksAssigned;

public:
    Developer(const std::string& devDepartment, int tasksAssigned)
        : _devDepartment(devDepartment), _tasksAssigned(tasksAssigned) {}

    const std::string& getDevDepartment() const { return _devDepartment; }
    int getTasksAssigned() const { return _tasksAssigned; }
};

#endif // DEVELOPER_HPP
