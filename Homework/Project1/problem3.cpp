/* --------------------------------------------------------
 * File: Problem3.cpp
 * --------------------------------------------------------
 * 
 * The program finds palindromes using the reverse and add method for multiple input numbers.
 * For each number, it:
 * 1. Reverses its digits and adds this reversed number to the original.
 * 2. Repeats the process until a palindrome is achieved.
 * 3. Displays the number of iterations and the final palindrome if found.
 * Assumes the computation will conclude within 1,000 iterations and the result will be within 4,294,967,295.
 * -------------------------------------------------------
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <stdexcept>

using namespace std;

/* --------------------------------------------------------
 * Function: checkPalindrome
 * Usage   : checkPalindrome(number)
 * --------------------------------------------------------
 * 
 * The function Checks if a given integer is a palindrome. 
 * It reverse input intiger and checks with original number, 
 * returns True if it matches else returns False
 * --------------------------------------------------------
 */
bool checkPalindrome(int pNum) {
    if (pNum < 0) return false;  // Check for negative number
    int original = pNum;
    int reversed = 0;

    // Reversing the digits
    while (pNum > 0) {
        int digit = pNum % 10;     // Extract the last digit
        reversed = reversed * 10 + digit;  // Append the digit to the reversed number
        pNum /= 10;  // Remove the last digit from the original number
    }
    return original == reversed; // Check for palindrome 
}

