#ifndef OFFLINEEXAM_H
#define OFFLINEEXAM_H

#include <iostream>
#include "exam.h"

class OfflineExam: public Exam {
    public:
        enum ExamTopic {CPP, DS, JAVA};
    private:
        std::string examLocation;
        ExamTopic topic;
    public:
        OfflineExam();
        OfflineExam(ExamTopic, std::string, std::string, int, Exam_Category);
        ~OfflineExam();
        void display();

        std::string getExamLocation() const { return examLocation; }
        void setExamLocation(const std::string examLocation_) { examLocation = examLocation_; }

        ExamTopic getTopic() const { return topic; }
        void setTopic(const ExamTopic topic_) { topic = topic_; }

        // overload operator >> to get input from user
        friend std::istream& operator>>(std::istream& is, OfflineExam& exam) {
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
            std::cout<<"\nEnter you choice for exam topic: ";
            int choice2;
            std::cin>>choice2;
            switch (choice2){
                case 0:
                    exam.setTopic(CPP);
                    break;
                case 1:
                    exam.setTopic(DS);
                    break;
                case 2:
                    exam.setTopic(JAVA);
                    break;
            
                default:
                    break;
            }
            return is;
        }
};



#endif // OFFLINEEXAM_H
