#include <iostream>
#include <string>
#include "user.h"


int main() {
    int userId;
    std::string userName;
    User::Activity activityChoice;
    User newUser(0, "Unknown");  

    while (true) {
        std::cout << "Menu:\n1. Create/Update User\n2. Display User Info\n3. Exit\n";
        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter User ID: ";
                std::cin >> userId;
                std::cout << "Enter User Name: ";
                // std::cin.ignore(); 
                getchar();
                std::getline(std::cin, userName);

                newUser = User(userId, userName);

                std::cout << "Select Activity:\n1. Reading\n2. Writing\n3. Travelling\n";
                int activityChoice;
                std::cout << "Enter your choice: ";
                std::cin >> activityChoice;

                switch (activityChoice) {
                    case 1:
                        newUser.setActivity(User::READING);
                        break;
                    case 2:
                        newUser.setActivity(User::WRITING);
                        break;
                    case 3:
                        newUser.setActivity(User::TRAVELLING);
                        break;
                    default:
                        std::cout << "Invalid choice.\n";
                        break;
                }
                break;

            case 2:
                newUser.display();
                break;

            case 3:
                std::cout << "Exiting the program.\n";
                return 0;

            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    }

    return 0;
}
