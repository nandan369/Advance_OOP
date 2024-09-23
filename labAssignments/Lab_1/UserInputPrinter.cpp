/* --------------------------------------------------------
 * File: UserInputPrinter.cpp
 * --------------------------------------------------------
 * Program to print user input until "stop" is entered
 */

#include <iostream>
#include <string>   

using namespace std;

int main() {
    string usr_input; // Variable to store user input

    cout << "Program started. Enter strings to be printed. Type 'stop' to end the program.\n" << endl;

    while (true) { // Loop to continuously prompt the user
        cout << "Please enter your string:\n"; 
        getline(cin, usr_input); // Read user input

        if (usr_input == "stop") { // Check if input is "stop"
            cout << "You entered 'stop'. Ending the program." << endl;
            break; // Exit the loop
        }

        cout << "You entered: " << usr_input << endl; // Print the entered string
    }

    cout << "Program terminated. Thank you for using the program." << endl; 

    return 0; // Indicate successful completion
}
