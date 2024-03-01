#ifndef HR_HPP
#define HR_HPP

#include <string>
#include <ostream>

class HR {
private:
    std::string _hrDepartment;
    int _pendingInterviews;

public:
    HR(const std::string& hrDepartment, int pendingInterviews)
        : _hrDepartment(hrDepartment), _pendingInterviews(pendingInterviews) {}

    const std::string& getHRDepartment() const { return _hrDepartment; }
    int getPendingInterviews() const { return _pendingInterviews; }

    friend std::ostream &operator<<(std::ostream &os, const HR &rhs);
};

inline std::ostream &operator<<(std::ostream &os, const HR &rhs) {
    os << "_hrDepartment: " << rhs._hrDepartment
       << " _pendingInterviews: " << rhs._pendingInterviews;
    return os;
}

#endif // HR_HPP
