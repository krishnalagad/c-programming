#ifndef ONLINEEXAM_H
#define ONLINEEXAM_H

#include <iostream>
#include "exam.h"

class OnlineExam: public Exam {
    public:
        enum Platform{MEET, TEAMS, ZOOM};
    private:
        Platform examPlatform;
    public:
        OnlineExam();
        OnlineExam(Platform, std::string, int, Exam_Category);
        OnlineExam(OnlineExam& exam);
        ~OnlineExam();

        void display();
        float getAverageMarks(int*);
        Platform getExamPlatform()  { return examPlatform; }
        void setExamPlatform( Platform examPlatform_) { examPlatform = examPlatform_; }

        // overload operator >> to get input from user
        friend std::istream& operator>>(std::istream& is, OnlineExam& exam) {
            std::cout<<"\nEnter exam code: ";
            std::string str;
            std::cin>>str;
            exam.setExamCode(str);

            std::cout<<"\nEnter time duration: ";
            int time;
            std::cin>>time;
            exam.setTimeDuration(time);

            std::cout<<"\n\n0 - UNIT_TEST, 1 - MID_TERM, 2 - END_SEM";
            std::cout<<"\nEnter your choice for exam type: ";
            int choice1;
            std::cin>>choice1;
            switch(choice1) {
                case 0:
                    exam.setEc(Exam::Exam_Category::UNIT_TEST);
                    break;
                case 1:
                    exam.setEc(Exam::Exam_Category::MID_TERM);
                    break;
                case 2:
                    exam.setEc(Exam::Exam_Category::END_SEM);
                    break;
                default:
                    break;
            }

            std::cout<<"\n\n0 - MEET, 1 - TEAMS, 2 - ZOOM";
            std::cout<<"\nEnter you choice for exam platform: ";
            int choice2;
            std::cin>>choice2;
            switch (choice2){
                case 0:
                    exam.setExamPlatform(MEET);
                    break;
                case 1:
                    exam.setExamPlatform(TEAMS);
                    break;
                case 2:
                    exam.setExamPlatform(ZOOM);
                    break;
            
                default:
                    break;
            }
            return is;
        }
};

    
#endif // ONLINEEXAM_H
