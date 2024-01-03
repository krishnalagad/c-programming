#include <iostream>
#include "exam.h"
#include "onlineExam.h"
#include "offlineExam.h"

int main() {
    // array of OnlineExam class
    std::cout<<"\nEnter total online exams: ";
    int total;
    std::cin>>total;
    OnlineExam oExams[total];

    for (int i = 0; i < total; i++)
        std::cin>>oExams[i];
    
    for (int i = 0; i < total; i++)
        oExams[i].display();

    // array of OfflineExam class
    std::cout<<"\nEnter total offline exams: ";
    std::cin>>total;
    OfflineExam ofExams[total];

    for (int i = 0; i < total; i++)
        std::cin>>ofExams[i];
    
    for (int i = 0; i < total; i++)
        ofExams[i].display();
    
    return 0;
}