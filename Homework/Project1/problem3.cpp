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
 * Function: numReversal
 * Usage   : numReversal(number)
 * --------------------------------------------------------
 * 
 * This function Reverses the digits of a given integer. takes an integer, 
 * extracts its digits one by one, and reverses their order to form a new integer. 
 * --------------------------------------------------------
 */
int numReversal(int num) {
    int reversed = 0;
    while (num != 0) {
        int digit = num % 10;  // Extract the last digit
        reversed = reversed * 10 + digit;  // Append the digit to the reversed number
        num /= 10;  // Remove the last digit
    }
    return reversed;
}

/* --------------------------------------------------------
 * Function: checkPalindrome
 * Usage   : checkPalindrome(number)
 * --------------------------------------------------------
 * 
 * This function Checks if a given integer is a palindrome. 
 * It reverse input intiger and checks with original number, 
 * returns True if it matches else returns False
 * --------------------------------------------------------
 */
bool checkPalindrome(int pNum) {
    if (pNum < 0) return false;  // Check for negative number
    int original = pNum;
    int reversed = numReversal(pNum);
    return original == reversed; // Check for palindrome 
}

/* -----------------------------------------------------------------------------
 * Function: computePalindrome
 * Usage   : computePalindrome(number)
 * -----------------------------------------------------------------------------
 * 
 * This function computes a palindrome by reversing the given number and adding it to the original number.
 * It performs the reverse-and-add process to find a palindrome. It continues this process until
 * either a palindrome is found or a maximum number of iterations (1000) is reached.
 * ------------------------------------------------------------------------------
 */
pair<int, int> computePalindrome(int num) {
    int iterations = 0;
    const int MAX_ITERATIONS = 1000;
    try {
        while (!checkPalindrome(num) && (iterations < MAX_ITERATIONS)) {
            int reversed = numReversal(num);
            num += reversed;
            if (num < 0) { // Check for overflow (negative number)
                cout<<"\nGot Exception..! \nNumber: "<<num<<"\nReverse no: "<<reversed<<"\niteration: "<<iterations<<"\n";
                throw overflow_error("\nOverflow occurred during addition.\n");
            }
            iterations++;
        }
    } catch (const overflow_error& e) {
        cerr << "Error: Overflow occurred during the reverse and add process.\n";
        throw; // Re-throwing the exception
    }
    return make_pair(iterations, num);
}

/* -------------------------------------------------------
 * Function: Main()
 * -------------------------------------------------------
 * Read the user input for the number of test cases in range of 1 to 100 to compute a palindrome.
 * For each test case, it reads a number, computes the palindrome, 
 * and handles any exceptions that may occur during computation.
 * -------------------------------------------------------
 */
int main() {
    int numOfTestcases;
    while(true){
        cout << "Enter the number of test cases (1 to 100)\n";
        cin >>numOfTestcases; // Getting input for number of test case
        if (numOfTestcases < 1 || numOfTestcases > 100) { //validation check for given input
                cout << "Input out of range. Please enter a number between 1 and 100.\n";
        } else {break;} // Exit the loop if valid input is provided
    }

    while (numOfTestcases--) { // Process each test case
        int pNum;
        cout << "Enter the number to compute palindrome\n";
        cin >> pNum;  // Read each number

        try {
            pair<int, int> result = computePalindrome(pNum); // Compute palindrome and get the number of iterations and resulting palindrome
            cout <<"\nIteration / No of Additions: "<< result.first << " Palindrome Number:" << result.second<<"\n";
        } catch (const exception& e) { // Catch and display any errors that occur during computation
            cerr << "An error occurred: " << e.what() << endl;
        }
    }

    return 0;
}


