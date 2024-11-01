#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>
#include <stdexcept>

class MyString {
private:
    char* data;
    size_t len;

    void copyData(const char* str);

public:
    MyString(const char* str = "");  // Constructor 
    MyString(const MyString& other); // Copy constructor
    ~MyString();                     // Destructor

    const char* toString() const;    // Convert to C++ string
    size_t length() const;           // Get length of the string
    MyString substr(size_t start, size_t n = std::string::npos) const; // Substring

    MyString operator+(const MyString& other) const;  // Concatenate
    MyString& operator+=(const MyString& other);      // Append

    friend std::ostream& operator<<(std::ostream& os, const MyString& str); // Output stream

    char& operator[](size_t index); // Bracket operator with bounds checking

    bool operator==(const MyString& other) const;  // Relational operators
    bool operator!=(const MyString& other) const;
    bool operator<(const MyString& other) const;
    bool operator<=(const MyString& other) const;
    bool operator>(const MyString& other) const;
    bool operator>=(const MyString& other) const;

    MyString& operator=(const MyString& other); // Assignment operator
};

#endif // MYSTRING_H
