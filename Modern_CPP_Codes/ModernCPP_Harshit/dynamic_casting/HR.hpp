/*
    public (most linient):
    protected:
    private (most strict):
*/

/*
    PROTECTED INHERITANCE
    base class : private --> protected (reducing security) {not allowed}
                 protected ---> protected {Okay}
                 public ---> protected (inccreasing security)
*/

/*
    PUBLIC INHERITANCE
    base class : private --> public (child) {not allowd}
                 protected --> public (child) {not allowed}
                 public -> public (child) {Allowed}
*/

#ifndef HR_HPP
#define HR_HPP

#include "Employee.hpp"
#include "HrSpecialization.hpp"
#include <ostream>

class HR : public Employee {
    private:
        int __hrTeamSize {0};
        HrSpecialization _hrSpecialization {HrSpecialization::TAG};

    public:
        HR() = delete;
        HR(const HR&) = delete;
        HR(HR&&) = delete;
        HR& operator=(const HR&) = delete;
        HR& operator=(HR&&) = delete;
        ~HR() { std::cout << "HR destroyeed!!\n"; }

        HR(int id, std::string name, float salary, int hrTeamSize, HrSpecialization specialization);

        float calculateTax() override;

        int hrTeamSize() const { return __hrTeamSize; }
        void setHrTeamSize(int hrTeamSize) { __hrTeamSize = hrTeamSize; }

        HrSpecialization hrSpecialization() const { return _hrSpecialization; }
        void setHrSpecialization(const HrSpecialization &hrSpecialization) { _hrSpecialization = hrSpecialization; }

        friend std::ostream &operator<<(std::ostream &os, const HR &rhs);
};

#endif // HR_HPP
