/* --------------------------------------------------------
 * File: Problem1.cpp
 * --------------------------------------------------------
 * This program corrects typing errors by replacing each character in the input
 * string with the one immediately to its left on a standard QWERTY keyboard.
 * -------------------------------------------------------
 */

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

/* --------------------------------------------------------
 * Function: fixTypingError
 * Usage   : fixTypingError(input_string)
 * --------------------------------------------------------
 * 
 * The function uses a predefined mapping where each key is mapped to the key to its immediate left.
 * It processes each character of the input string:
 *   - If the character is found in the mapping, it is replaced with the corresponding key to its left.
 *   - If the character is not in the mapping, it is added to the output unchanged.
 * The function returns the corrected string.
 * ---------------------------------------------------------
 */

string fixTypingError(const string& input) {
    unordered_map<char, char> keyFixingMap = { // Mapping key to its immediate left
        {'1', '`'}, {'2', '1'}, {'3', '2'}, {'4', '3'}, {'5', '4'}, {'6', '5'}, {'7', '6'}, {'8', '7'}, {'9', '8'}, {'0', '9'}, {'-', '0'}, {'=', '-'},
        {'!', '~'}, {'@', '!'}, {'#', '@'}, {'$', '#'}, {'%', '$'}, {'^', '%'}, {'&', '^'}, {'*', '&'}, {'(', '*'}, {'}', '('}, {'_', ')'}, {'+', '_'},
        {'W', 'Q'}, {'E', 'W'}, {'R', 'E'}, {'T', 'R'}, {'Y', 'T'}, {'U', 'Y'}, {'I', 'U'}, {'O', 'I'}, {'P', 'O'}, {'[', 'P'}, {'{', 'P'}, {']', '['}, 
        {'}', '{'}, {'\\', ']'}, {'|', '}'}, {'S', 'A'}, {'D', 'S'}, {'F', 'D'}, {'G', 'F'}, {'H', 'G'}, {'J', 'H'}, {'K', 'J'}, {'L', 'K'}, {';', 'L'}, 
        {':', 'L'}, {'\'', ';'}, {'"', ':'}, {'X', 'Z'}, {'C', 'X'}, {'V', 'C'}, {'B', 'V'}, {'N', 'B'}, {'M', 'N'}, {',', 'M'}, {'<', 'M'}, {'.', ','}, 
        {'>', '<'}, {'/', '.'}, {'?', '>'}
    };

    string decodedText; // To store the corrected input string

    for (char ch : input) {
        try {
            decodedText += keyFixingMap.at(ch); // Try to replace the character using the mapping
        } 
        catch (const out_of_range&) {
            decodedText += ch; // If the character is not in the map, just append it as is
        }
    }
    return decodedText; // Return the corrected input string
}

/* -------------------------------------------------------
 * Function: Main()
 * -------------------------------------------------------
 * Reads a string input from the user, corrects typing errors
 *  using fixTypingError, and outputs the corrected string.
 * -------------------------------------------------------
 */

int main() {
    string user_input; // Variable to store user input
    cout<<"Enter the input string: \n";
    getline(cin, user_input);  // Read one line of input
    cout << fixTypingError(user_input) << endl; //function calling for correcting input string
    return 0;
}