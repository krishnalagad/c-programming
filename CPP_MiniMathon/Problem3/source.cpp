#include <iostream>
#include <cstring>
#include "player.h"

static int idGenerator = 219300;
Player::Player(){
    this->playerId = idGenerator++;
    this->pName = new char[8];
    strcpy(this->pName, "KRISHNA");
    for (int i = 0; i < SCORE_LIMIT; i++)
        this->scores[i] = 0;  
}

Player::Player(char *name, int *scores) {
    this->playerId = idGenerator++;
    this->pName = new char[strlen(name) + 1];
    strcpy(this->pName, name);
    for (int i = 0; i < SCORE_LIMIT; i++)
        this->scores[i] = scores[i];  
}

Player::Player(Player &p) {
    this->playerId = p.getPlayerId();
    this->pName = new char[strlen(p.getPName()) + 1];
    strcpy(this->pName, p.getPName());
    int *temp = p.getScores();
    for (int i = 0; i < SCORE_LIMIT; i++)
        this->scores[i] = temp[i];
}

Player::~Player(){
    std::cout<<"\nMemory freed!!";
    delete []pName;
}

float Player::calculateAverageScores(int *arr) {
    float avg;
    int sum = 0;
    for (int i = 0; i < SCORE_LIMIT; i++) {
        sum += arr[i];
    }
    avg = sum / 3.0f;
    return avg;
}

void Player::accept() {
    std::cout<<"\nEnter player name: ";
    char ch[50];
    std::cin>>ch;
    this->pName = new char[strlen(ch) + 1];
    strcpy(this->pName, ch);

    for (int i = 0; i < SCORE_LIMIT; i++){
        std::cout<<"Enter score "<<(i + 1)<<": ";
        std::cin>>this->scores[i];
    }
    
}

void Player::display() {
    std::cout<<"\nPlayer Id: "<<this->playerId<<"\nPlayer Name: "<<this->pName<<"\nPlayer scores: ";
    for (int i = 0; i < SCORE_LIMIT; i++){
        std::cout<<this->scores[i]<<"  ";
    }
    std::cout<<"\n";
}
