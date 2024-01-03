#ifndef EXAM_H
#define EXAM_H

#include <iostream>
#define SIZE 5

class Exam {
    public:
        enum Exam_Category{UNIT_TEST, MID_TERM, END_SEM};
    private:
        std::string examCode;
        int timeDuration;
        Exam_Category ec;
    public:
        Exam();
        Exam(std::string, int, Exam_Category);
        virtual ~Exam();
        virtual void display() = 0;     // pure virtual

        std::string getExamCode()  { return examCode; }
        void setExamCode(std::string examCode_) { examCode = examCode_; }

        int getTimeDuration()  { return timeDuration; }
        void setTimeDuration(int timeDuration_) { timeDuration = timeDuration_; }

        Exam_Category getEc() const { return ec; }
        void setEc(const Exam_Category ec_) { ec = ec_; }
};

#endif // EXAM_H
