#include "user.h"

//Default Constructor 
User::User() 
    : userName("Unknown"), email("unknown@example.com") {}

//Parameterized  Constructor
User::User(const string& userName, const string& email)
    : userName(userName), email(email) {}

/* --------------------------------------------------------
 * Function: addFriend
 * Usage: addFriend(User* newFriend)
 * --------------------------------------------------------
 * This function adds a new friend to the user's friend list if the list
 * has not reached its maximum capacity(100). 
 * ---------------------------------------------------------*/
void User::addFriend(User* newFriend) {
    // Ensure the friend list isn't full
    if (friendList.size() >= MAX_FRIENDS) {
        cout << "Oops, limit reached...!\n";    
    } else {
        friendList.push_back(newFriend);
        cout << newFriend->getUserName() << " has been added to friend list..!\n";
    }
}

/* --------------------------------------------------------
 * Function: removeFriend
 * Usage: removeFriend(const string &userName)
 * --------------------------------------------------------
 * This function removes a friend from the user's friend list based on the 
 * provided username. 
 * ---------------------------------------------------------*/
void User::removeFriend(const string &userName){
    bool friendFound = false;
    for (size_t i = 0; i < friendList.size(); ++i) {
        if (friendList[i]->getUserName() == userName) {
            // Erase the friend from the list using the index
            friendList.erase(friendList.begin() + i);
            cout << userName << " has been removed from friend list..!\n";
            friendFound = true;
            break;
        }
    }
    if(!friendFound){
        cout <<userName<<" not found in frined list..!\n";
    }
}

/* --------------------------------------------------------
 * Function: numFriends
 * Usage: int numFriends() const
 * --------------------------------------------------------
 * This function returns the total number of friends in the user's 
 * friend list.
 * ---------------------------------------------------------*/
int User::numFriends() const{
    return friendList.size();
}

/* --------------------------------------------------------
 * Function: getFriendAt
 * Usage: User* getFriendAt(int index) const
 * --------------------------------------------------------
 * This function retrieves a pointer to the friend at the specified 
 * index in the user's friend list. 
 * ---------------------------------------------------------*/
User* User::getFriendAt(int index) const{
        if (index < 0 || index >= friendList.size()) {
            cout << "Invalid index." << endl;
            return nullptr;
        }
        return friendList[index];
}

//function to get username
string User::getUserName() const { 
    return userName; 
}

//function to set username
void User::setUserName(const string& name) { 
    userName = name; 
}

//function to get Email
string User::getEmail() const { 
    return email; 
}

//function to set Email
void User::setEmail(const string& emailAddress) {
    email = emailAddress; 
}