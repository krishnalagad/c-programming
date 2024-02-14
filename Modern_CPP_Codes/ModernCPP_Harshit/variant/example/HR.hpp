#ifndef HR_HPP
#define HR_HPP

#include <string>

class HR {
private:
    std::string _hrDepartment;
    int _pendingInterviews;

public:
    HR(const std::string& hrDepartment, int pendingInterviews)
        : _hrDepartment(hrDepartment), _pendingInterviews(pendingInterviews) {}

    const std::string& getHRDepartment() const { return _hrDepartment; }
    int getPendingInterviews() const { return _pendingInterviews; }
};

#endif // HR_HPP
