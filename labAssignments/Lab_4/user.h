#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class User {
    protected:
        string userName;           
        string email;              
        vector<User*> friendList;  
        const int MAX_FRIENDS = 100; 

    public: 
        // Default constructor
        User();

        // Parameterized constructor
        User(const string& userName, const string& email);

        // Adds a new friend to the user's friend list
        void addFriend(User* newFriend); 
        
        // Removes a friend from the user's friend list by username
        void removeFriend(const string &userName);

        // Returns the number of friends in the user's friend list
        int numFriends() const;

        // Retrieves a pointer to the friend at the specified index
        User* getFriendAt(int index) const;

        // Getters and setters for userName
        string getUserName() const;  // Returns the username
        void setUserName(const string& name); // Sets the username

        // Getters and setters for email
        string getEmail() const; // Returns the email address
        void setEmail(const string& emailAddress); // Sets the email address
};

#endif
