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

        int getId() const { return id; }
        void setId(int id_) { id = id_; }

        std::string getName() const { return name; }
        void setName(const std::string &name_) { name = name_; }
};