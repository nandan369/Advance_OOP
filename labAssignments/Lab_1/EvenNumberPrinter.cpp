/* --------------------------------------------------------
 * File: EvenNumberPrinter.cpp
 * --------------------------------------------------------
 * This Program is to print even numbers between 0 to 100 
 */

#include <iostream>
using namespace std;

int main() {
    int i = 0; // Initialize counter variable to 0

    cout << "Printing even numbers from 0 to 100\n" << endl;

    // Loop to iterate from 0 to 100
    while (i <= 100) {
        // Print the number if it's even
        if (i % 2 == 0) {
            cout << i << endl;
        }
        i++; // Increment the counter
    }

    return 0; // Return 0 to indicate successful completion
}
