#include "myString.h"
#include <cstring> // For strlen and strcpy

/*------------------------------------------------
* Function : copyData(const char* str)
---------------------------------------------------
* This function allocates memory and copies a C-string (str)
* into the data member variable, setting len to its length.
-------------------------------------------------*/
void MyString::copyData(const char* str) {
    len = strlen(str);
    data = new char[len + 1];
    strcpy(data, str);
}

// Constructor
MyString::MyString(const char* str) {
    if (str == nullptr) {
        throw std::invalid_argument("Null pointer passed to MyString constructor");
    }
    copyData(str);
}

// Copy constructor
MyString::MyString(const MyString& other) {
    copyData(other.data);
}

// Destructor
MyString::~MyString() {
    delete[] data;
}

/*------------------------------------------------
* Function : toString() const
---------------------------------------------------
* This function returns the C-string stored in the 
* data member variable.
-------------------------------------------------*/
const char* MyString::toString() const {
    return data;
}

/*------------------------------------------------
* Function : length() const
---------------------------------------------------
* This function returns the length of the string stored 
* in the data member variable by returning the value of len.
-------------------------------------------------*/
size_t MyString::length() const {
    return len;
}

/*------------------------------------------------
* Function : substr(size_t start, size_t n) const
---------------------------------------------------
* Returns a substring starting at 'start' for up to 'n' chars.
* Throws std::out_of_range if 'start' is out of bounds.
-------------------------------------------------*/
MyString MyString::substr(size_t start, size_t n) const {
    if (start >= len) throw std::out_of_range("Index out of range");
    size_t subLen = (n == std::string::npos || start + n > len) ? len - start : n;

    char* subStr = new char[subLen + 1];
    strncpy(subStr, data + start, subLen);
    subStr[subLen] = '\0';

    MyString result(subStr);
    delete[] subStr;
    return result;
}

/*------------------------------------------------
* Function : operator+(const MyString& other) const
---------------------------------------------------
* Concatenates this MyString with another, allocating new 
* memory for the result and returning it as a new object.
-------------------------------------------------*/
MyString MyString::operator+(const MyString& other) const {
    char* newStr = new char[len + other.len + 1];
    strcpy(newStr, data);
    strcat(newStr, other.data);

    MyString result(newStr);
    delete[] newStr;
    return result;
}

/*------------------------------------------------
* Function : operator+=(const MyString& other)
---------------------------------------------------
* This function appends the content of another MyString object 
* to the current string, updating the length and reallocating memory.
-------------------------------------------------*/
MyString& MyString::operator+=(const MyString& other) {
    char* newStr = new char[len + other.len + 1];
    strcpy(newStr, data);
    strcat(newStr, other.data);

    delete[] data;
    data = newStr;
    len += other.len;
    return *this;
}

/*------------------------------------------------
* Function : operator<<(std::ostream& os, const MyString& str)
---------------------------------------------------
* Overloads the << operator to print the MyString
* object’s data to the output stream (os).
-------------------------------------------------*/
std::ostream& operator<<(std::ostream& os, const MyString& str) {
    os << str.data;
    return os;
}

/*------------------------------------------------
* Function : operator[](size_t index)
---------------------------------------------------
* Checks if the given index is within bounds and 
* returns a reference to the character at the specified 
* index in the data member. Throws an exception if out of bounds.
-------------------------------------------------*/
char& MyString::operator[](size_t index) {
    if (index >= len) throw std::out_of_range("Index out of bounds");
    return data[index];
}

// Relational operators
bool MyString::operator==(const MyString& other) const {
    if (len == 0 && other.len == 0) return true; // Both are empty
    return strcmp(data, other.data) == 0;
}

bool MyString::operator!=(const MyString& other) const {
    return !(*this == other);
}

bool MyString::operator<(const MyString& other) const {
    return strcmp(data, other.data) < 0; // strcmp handles empty strings
}

bool MyString::operator<=(const MyString& other) const {
    return strcmp(data, other.data) <= 0;
}

bool MyString::operator>(const MyString& other) const {
    return strcmp(data, other.data) > 0;
}

bool MyString::operator>=(const MyString& other) const {
    return strcmp(data, other.data) >= 0;
}

/*------------------------------------------------
* Function : operator=(const MyString& other)
---------------------------------------------------
* This function overloads the assignment operator to copy data 
* from another MyString object, handling self-assignment and 
* ensuring proper memory management.
-------------------------------------------------*/
MyString& MyString::operator=(const MyString& other) {
    if (this == &other) return *this; // Handle self-assignment

    delete[] data;
    copyData(other.data);
    return *this;
}