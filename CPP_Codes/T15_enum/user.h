#include <iostream>

class User {
    public:
        enum Activity { READING, WRITING, TRAVELLING };

    private:
        int id;
        std::string name;
        Activity currentActivity;

    public:
        // Constructor
        User(int userId, std::string userName);

        // Display user information
        void display();

        // Set user activity
        void setActivity(Activity activity) {
            currentActivity = activity;
        }
};