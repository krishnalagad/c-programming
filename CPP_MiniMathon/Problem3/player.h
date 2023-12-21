#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <cstring>
#define SCORE_LIMIT 3

class Player{
    private:
        int playerId;
        char *pName;
        int scores[SCORE_LIMIT];
    public:
        Player();
        Player(char *, int *);
        Player(Player &p);
        ~Player();

        float calculateAverageScores(int *arr);
        void accept();
        void display();

        int getPlayerId()  { return playerId; }
        void setPlayerId(int playerId_) { playerId = playerId_; }

        char *getPName()  { return pName; }
        void setPName(char *pName_) { strcpy(this->pName, pName_); }

        int* getScores()  { return this->scores; }
        void setScores(int *scores_) { 
            for (int i = 0; i < SCORE_LIMIT; i++){
                this->scores[i] = scores_[i];
            } 
        }

        // operator overloading: ==
        bool operator ==(Player &p) {
            std::cout<<"\noperator overloadding: == \n";
            bool idFlag = this->playerId == p.getPlayerId();
            if(idFlag)
                return true;
            else
                return false;
        }

        // operator overloading: []
        char& operator[](int index) {
            std::cout<<"\noperator overloadding: [] \n";
            if(!(index>=0 && index < strlen(pName)))
                throw "Index out of bound";
            return this->pName[index];
        }

        // oparator overloading: <<
        friend std::ostream& operator<<(std::ostream &os, const Player &p) {
            std::cout<<"\noperator overloadding: << \n";
            os<<"\nPlayer Id: "<<p.playerId;
            os<<"\nPlayer Name: "<<p.pName;
            return os;
        }

        // operator overloadding: <
        void operator <(Player &p) {
            std::cout<<"\noperator overloadding: < \n";
            this->playerId < p.playerId ? std::cout<<"P1 is smaller" : std::cout<<"P2 is smaller";
        }
};


#endif // PLAYER_H
