
#include <iostream>
#include <cstring>

enum Party {
    BJP, INC, AAP, RNC
};
static int idCounter = 100;
class Candidate {

    private:
        int id;
        char *name;
        Party party;

    public:
        // Default constructor
        Candidate() {
            this->id = idCounter++;
            this->name = new char[8];
            strcpy(this->name, "DEFAULT");
            this->party = BJP;
        }

        // Parameterized constructor
        Candidate(const char *name) {
            this->id = idCounter++;
            this->name = new char[strlen(name) + 1];
            strcpy(this->name, name);
            this->party = BJP;
        }

        // Copy constructor
        Candidate(const Candidate &other) {
            this->id = other.id;
            this->name = new char[strlen(other.name) + 1];
            strcpy(this->name, other.name);
            this->party = other.party;
        }

        // Destructor
        ~Candidate() {
            delete[] name;
        }

        // Overloaded assignment operator
        Candidate &operator=(const Candidate &other) {
            if (this != &other) {
                this->id = other.id;
                delete[] this->name;
                this->name = new char[strlen(other.name) + 1];
                strcpy(this->name, other.name);
                this->party = other.party;
            }
            return *this;
        }

        void display() const {
            std::cout << "\nId: " << this->id << "\nName: " << this->name << "\nParty: ";
            switch (this->party) {
                case BJP:
                    std::cout << "BJP";
                    break;
                case INC:
                    std::cout << "INC";
                    break;
                case AAP:
                    std::cout << "AAP";
                    break;
                case RNC:
                    std::cout << "RNC";
                    break;
                default:
                    break;
            }
            std::cout << "\n";
        }

        int getId() const { return id; }
        void setId(int id_) { id = id_; }

        const char *getName() const { return name; }
        void setName(const char *name_) {
            delete[] name;
            this->name = new char[strlen(name_) + 1];
            strcpy(this->name, name_);
        }

        Party getParty() const { return party; }
        void setParty(Party party_) { party = party_; }
};

int main() {
    Candidate c1("Modi");
    char *name;
    Party party;

    while (true) {
        std::cout << "\n1. Add\n2. View\n3. Exit\n";
        std::cout << "\nEnter choice: ";
        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "\nEnter name: ";
                name = new char[50];
                std::cin.ignore();  // Consume newline left in buffer
                std::cin.getline(name, 50);
                c1 = Candidate(name);

                std::cout << "\nEnter party number: ";
                int no;
                std::cin >> no;
                switch (no) {
                    case 1:
                        c1.setParty(BJP);
                        break;
                    case 2:
                        c1.setParty(INC);
                        break;
                    case 3:
                        c1.setParty(AAP);
                        break;
                    case 4:
                        c1.setParty(RNC);
                        break;
                    default:
                        std::cout << "Enter correct party number.\n";
                        break;
                }
                break;
            case 2:
                c1.display();
                break;
            case 3:
                return 0;
            default:
                break;
        }
    }
    return 0;
}





// #include <iostream>
// #include <cstring>

// static int idCounter = 100;
// enum Party {
//     BJP, INC, AAP, RNC
// };

// class Candidate {

// private:
//     int id;
//     char *name;
//     Party party;

// public:
//     // Default constructor
//     Candidate() {
//         this->id = idCounter++;
//         this->name = new char[8];
//         strcpy(this->name, "DEFAULT");
//         this->party = BJP;
//     }

//     // Parameterized constructor
//     Candidate(const char *name) {
//         this->id = idCounter++;
//         this->name = new char[strlen(name) + 1];
//         strcpy(this->name, name);
//         this->party = BJP;
//     }

//     // Destructor
//     ~Candidate() {
//         delete[] name;
//     }

//     void display() const {
//     std::cout << "\nId: " << this->id << "\nName: " << this->getName() << "\nParty: ";
//     switch (this->party) {
//         case BJP:
//             std::cout << "BJP";
//             break;
//         case INC:
//             std::cout << "INC";
//             break;
//         case AAP:
//             std::cout << "AAP";
//             break;
//         case RNC:
//             std::cout << "RNC";
//             break;
//         default:
//             break;
//     }
//     std::cout << "\n";
// }


//     int getId() const { return id; }
//     void setId(int id_) { id = id_; }

//     const char *getName() const { return name; }
//     void setName(const char *name_) {
//         delete[] name;
//         this->name = new char[strlen(name_) + 1];
//         strcpy(this->name, name_);
//     }

//     Party getParty() const { return party; }
//     void setParty(Party party_) { party = party_; }
// };



// int main() {
//     Candidate c1("Modi");
//     char name[50];
//     Party party;

//     while (true) {
//         std::cout << "\n1. Add\n2. Search\n3. Exit\n";
//         std::cout << "\nEnter choice: ";
//         int choice;
//         std::cin >> choice;

//         switch (choice) {
//             case 1:
//                 std::cout << "\nEnter name: ";
//                 std::cin.ignore();  // Consume newline left in buffer
//                 std::cin.getline(name, 50);
//                 c1 = Candidate(name);

//                 std::cout << "\nEnter party number: ";
//                 int no;
//                 std::cin >> no;
//                 switch (no) {
//                     case 1:
//                         c1.setParty(BJP);
//                         break;
//                     case 2:
//                         c1.setParty(INC);
//                         break;
//                     case 3:
//                         c1.setParty(AAP);
//                         break;
//                     case 4:
//                         c1.setParty(RNC);
//                         break;
//                     default:
//                         std::cout << "Enter correct party number.\n";
//                         break;
//                 }
//                 break;
//             case 2:
//                 c1.display();
//                 break;
//             case 3:
//                 return 0;
//             default:
//                 break;
//         }
//     }
//     return 0;
// }



















