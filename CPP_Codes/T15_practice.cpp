#include <iostream>
#include <cstring>

enum Party{
    BJP, INC, AAP, RNC
}

class Candidate{
        
    private:
        int id;
        char *name;
        Party party;
    public:
        Candidate();
        Candidate(const char *);
        void display();

        int getId() { return id; }
        void setId(int id_) { id = id_; }

        char *getName()  { return name; }
        void setName(char *name_) { 
            delete []name;
            this->name = new char[strlen(name_) + 1];
            strcpy(this->name, name_);
        }

        Party getParty() { return party; }
        void setParty(Party party_) { party = party_; }
}

static int idCounter = 100;
Candidate::Candidate() {
    this->id = idCounter++;
    this->name = this->name = new char[8];
    strcpy(this->name, "DEFAULT");
    this->party = BJP;
}

Candidate::Candidate(char *name) {
    this->id = idCounter++;
    this->name = this->name = new char[8];
    strcpy(this->name, name);
    this->party = BJP;
}

void Candidate::display() {
    std::cout<<"\nId: "<<this->id<<"\nName: "<<this->name<<"\nParty: ";
    switch (this->party){
        case BJP:
            std::cout<<"BJP";
            break;
        case INC:
            std::cout<<"INC";
            break;
        case AAP:
            std::cout<<"AAP";
            break;
        case RNC:
            std::cout<<"RNC";
            break;
        default:
            break;
    }
}

int main(void) {
    return 0;
}