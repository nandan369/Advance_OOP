#include "myString.h"
#include <gtest/gtest.h>

/*
* I used chatgpt GPT-4o, provided my headerfile and asked for testsuite. 
* I asked to include test cases which covers negative scenarios and empty string cases.
*/

TEST(MyStringTest, DefaultConstructor) {
    MyString str;
    EXPECT_EQ(str.length(), 0);
}

TEST(MyStringTest, ParameterizedConstructor) {
    MyString str("Hello");
    EXPECT_EQ(str.length(), 5);
    EXPECT_STREQ(str.toString(), "Hello");
}

TEST(MyStringTest, CopyConstructor) {
    MyString str1("Hello");
    MyString str2(str1);
    EXPECT_EQ(str2.length(), str1.length());
    EXPECT_STREQ(str2.toString(), str1.toString());
}

TEST(MyStringTest, Destructor) {
    {
        MyString str("Hello");
        EXPECT_EQ(str.length(), 5);
    } // str goes out of scope
}

TEST(MyStringTest, Concatenation) {
    MyString str1("Hello");
    MyString str2(" World");
    MyString result = str1 + str2;
    EXPECT_STREQ(result.toString(), "Hello World");
}

TEST(MyStringTest, Append) {
    MyString str("Hello");
    str += " World";
    EXPECT_STREQ(str.toString(), "Hello World");
}

TEST(MyStringTest, Substring) {
    MyString str("Hello World");
    MyString sub = str.substr(6, 5);
    EXPECT_STREQ(sub.toString(), "World");
}

TEST(MyStringTest, SubstringInvalidIndices) {
    MyString str("Hello");
    EXPECT_THROW(str.substr(10), std::out_of_range); // Start index out of bounds
    EXPECT_NO_THROW(str.substr(0, 10)); // Length longer than actual string
}

TEST(MyStringTest, ConcatenationWithEmptyString) {
    MyString str1("Hello");
    MyString str2("");
    MyString result = str1 + str2;
    EXPECT_STREQ(result.toString(), "Hello");
    result = str2 + str1;
    EXPECT_STREQ(result.toString(), "Hello");
}

TEST(MyStringTest, LengthAfterModification) {
    MyString str("Hello");
    str += " World";
    EXPECT_EQ(str.length(), 11);
}

TEST(MyStringTest, BracketOperator) {
    MyString str("Hello");
    EXPECT_EQ(str[0], 'H');
    EXPECT_THROW(str[10], std::out_of_range); // Check for out of bounds
}

TEST(MyStringTest, BracketOperatorOutOfBounds) {
    MyString str("Hello");
    EXPECT_THROW(str[5], std::out_of_range); // Accessing index equal to length
}

TEST(MyStringTest, Equality) {
    MyString str1("Hello");
    MyString str2("Hello");
    MyString str3("World");
    EXPECT_TRUE(str1 == str2);
    EXPECT_FALSE(str1 == str3);
}

TEST(MyStringTest, Inequality) {
    MyString str1("Hello");
    MyString str2("World");
    EXPECT_TRUE(str1 != str2);
    EXPECT_FALSE(str1 != str1);
}

TEST(MyStringTest, Comparison) {
    MyString str1("Apple");
    MyString str2("Banana");
    EXPECT_TRUE(str1 < str2);
    EXPECT_TRUE(str2 > str1);
}

TEST(MyStringTest, AssignmentOperator) {
    MyString str1("Hello");
    MyString str2;
    str2 = str1;
    EXPECT_EQ(str2.length(), str1.length());
    EXPECT_STREQ(str2.toString(), str1.toString());
    // Test self-assignment
    str2 = str2;
    EXPECT_STREQ(str2.toString(), "Hello");
}

TEST(MyStringTest, ChainedOperations) {
    MyString str1("Hello");
    MyString str2(" ");
    MyString str3("World");
    MyString result = str1 + str2 + str3;
    EXPECT_STREQ(result.toString(), "Hello World");
}

TEST(MyStringTest, CopyFromNullPointer) {
    EXPECT_THROW(MyString str(nullptr), std::invalid_argument); // Assuming you handle null pointers in the constructor
}

TEST(MyStringTest, SubstringNegativeStartIndex) {
    MyString str("Hello");
    EXPECT_THROW(str.substr(-1, 3), std::out_of_range); // Check for negative start index
}

TEST(MyStringTest, LengthOfNullPointer) {
    EXPECT_THROW(MyString str(nullptr), std::invalid_argument); // Ensure constructor throws for nullptr
}

TEST(MyStringTest, InvalidConcatenation) {
    MyString str("Hello");
    EXPECT_THROW(str + MyString(nullptr), std::invalid_argument); // Assuming you handle null pointers in concatenation
}

TEST(MyStringTest, BracketOperatorOutOfBoundsNegative) {
    MyString str("Hello");
    EXPECT_THROW(str[100], std::out_of_range); // Accessing an index much larger than length
}

TEST(MyStringTest, SelfAssignmentInCopyConstructor) {
    MyString str("Hello");
    MyString str2 = str; // Copy constructor should not alter original
    EXPECT_EQ(str2.length(), str.length());
    EXPECT_STREQ(str2.toString(), str.toString());
}

TEST(MyStringTest, LargeString) {
    std::string largeString(10000, 'A'); // Create a large string of 10,000 'A's
    MyString str(largeString.c_str());
    EXPECT_EQ(str.length(), 10000);
    EXPECT_STREQ(str.toString(), largeString.c_str());
}
