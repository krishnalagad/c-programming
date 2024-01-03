#include <iostream>
#include "user.h"
#include "userNotFountException.h"
User user[SIZE];

int getCount(User* users, std::string dept) {
    bool flag = true;
    int count = 0;
    for (int i = 0; i < SIZE; i++){
        if(dept == users[i].getDepartment()) {
            count += 1;
            users->display();
            flag = true;
        } 
    }
    if(!flag) {
        throw UserNotFountException("User not found with given department!!");
    }
    return count;
}

int main() {
    
    // get data fro user from client
    for (int i = 0; i < SIZE; i++)
        std::cin>>user[i];

    // display data enter by user
    for (int i = 0; i < SIZE; i++)
        user[i].display();

    std::cout<<"\nEnter department to search an user: ";
    std::string str;
    getchar();
    std::getline(std::cin, str);

    int count = 0;
    try {
        count = getCount(user, str);
    } catch(UserNotFountException ex) {
        std::cout<<"\nUserNotFoundException caught: "<<ex.what();
    }
    std::cout<<"\nCount: "<<count;

    // objects to check operator overlading: ==
    User user1, user2;
    std::cin>>user1;
    std::cin>>user2;

    bool res = user1 == user2;

    if(res)
        std::cout<<"\nBoth user have same department!!\n";
    else 
        std::cout<<"\nDepartment is not same!!\n";
    return 0;
}