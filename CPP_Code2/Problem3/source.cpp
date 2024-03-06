#include <iostream>
#include "exam.h"
#include "onlineExam.h"
#include "offlineExam.h"

// ---------------------- Exam class------------------------
Exam::Exam() {}
Exam::~Exam() {}

// ---------------------- OnlineExam class------------------------
OnlineExam::OnlineExam() {      // default
    Exam::setExamCode("EXAM01");
    Exam::setTimeDuration(90);
    Exam::setEc(Exam::Exam_Category::END_SEM);
    this->examPlatform = TEAMS;
}
OnlineExam::OnlineExam(Platform p, std::string str, int time, Exam_Category e) { // parameterized
    OnlineExam::setExamCode(str);
    OnlineExam::setTimeDuration(time);
    OnlineExam::setEc(e);
    this->examPlatform = p;
}
OnlineExam::OnlineExam(OnlineExam &exam) {  // copy
    this->setExamCode(exam.getExamCode());
    this->setTimeDuration(exam.getTimeDuration());
    this->setEc(exam.getEc());
    this->setExamPlatform(exam.getExamPlatform());
}
OnlineExam::~OnlineExam() {}

void OnlineExam::display() {    // implementation
    std::cout<<"\nExam Code: "<<Exam::getExamCode();
    std::cout<<"\nTime Duration: "<<Exam::getTimeDuration();
    std::cout<<"\nExam Type: ";
    switch (Exam::getEc()) {
        case 0:
            std::cout<<"Unit Test";
            break;
        case 1:
            std::cout<<"Mid-term exam";
            break;
        case 2:
            std::cout<<"End-term exam";
            break;
        
        default:
            break;
    }

    std::cout<<"\nExam Platform: ";
    switch (examPlatform) {
        case 0:
            std::cout<<"Meet";
            break;
        case 1:
            std::cout<<"TEAMS";
            break;
        case 2:
            std::cout<<"ZOOM";
            break;
        
        default:
            break;
    }
    std::cout<<"\n";
}

float OnlineExam::getAverageMarks(int *arr) {
    int sum = 0;
    for (int i = 0; i < SIZE; i++)
        sum += arr[i];
    return sum / 5.0f;
}

// --------------------------------Offline Exam class---------------------
OfflineExam::OfflineExam(){
    Exam::setExamCode("EXAM01");
    Exam::setTimeDuration(90);
    Exam::setEc(Exam::Exam_Category::END_SEM);
    this->examLocation = "PUNE";
    this->topic = JAVA;
}

OfflineExam::OfflineExam(ExamTopic et, std::string location, std::string examCode, int time, Exam_Category ec) {
    Exam::setExamCode(examCode);
    Exam::setTimeDuration(time);
    Exam::setEc(ec);
    this->examLocation = location;
    this->topic = et;
}

OfflineExam::~OfflineExam(){
}

void OfflineExam::display() {
    std::cout<<"\nExam Code: "<<Exam::getExamCode();
    std::cout<<"\nTime Duration: "<<Exam::getTimeDuration();
    std::cout<<"\nExam Location: "<<this->examLocation;
    std::cout<<"\nExam Type: ";
    switch (Exam::getEc()) {
        case 0:
            std::cout<<"Unit Test";
            break;
        case 1:
            std::cout<<"Mid-term exam";
            break;
        case 2:
            std::cout<<"End-term exam";
            break;
        
        default:
            break;
    }

    std::cout<<"\nExam Topic: ";
    switch (topic) {
        case 0:
            std::cout<<"CPP";
            break;
        case 1:
            std::cout<<"DS";
            break;
        case 2:
            std::cout<<"JAVA";
            break;
        
        default:
            break;
    }
    std::cout<<"\n";
}
