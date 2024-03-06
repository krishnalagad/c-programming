#include <iostream>
#include <cstring>
#include "player.h"



int main(void) {
    Player p1, p2;
    p1.accept();
    p1.display();
    std::cout<<"\nAverage of scores: "<<p1.calculateAverageScores(p1.getScores())<<"\n";

    p2.accept();
    p2.display();
    std::cout<<"\nAverage of scores: "<<p2.calculateAverageScores(p2.getScores())<<"\n";

    std::cout<<"\n---------------------------OPERATOR OVERLOADING--------------------------\n";

    // call to overloaded == operator
    bool flag = p1 == p2;
    if(flag)
        std::cout<<"\nSame ID\n";
    else    
        std::cout<<"\nDifferent ID\n";

    // call to overloaded << opeartor
    std::cout<<p1<<std::endl;

    // call to overloaded < operator
    p1 < p2;

    // call to overloaded [] operator
    try{
        char ch = p1[0];
        std::cout<<ch<<std::endl;
    }
    catch(const char *msg){
        std::cout<<"\n"<<msg<<std::endl;
    }

    p1[1] = 'k';
    p1.display();

    return 0;
}