#include "randword.h"
#include <fstream>
#include <cstdlib>
#include <iostream>

using namespace std;

const int MAX_WORDS = 1000; // Maximum number of words allowed in the list
static string word_list[MAX_WORDS]; // Static global array to store words
static int current_word_count = 0; // Number of words read from the file

/* -----------------------------------------------------------------------------
 * Function: InitDictionary
 * Usage   : InitDictionary(filename)
 * -----------------------------------------------------------------------------
 * 
 * This function initializes the word list by reading words from a specified file.
 * It populates the word_list array with words from the file, ensuring not to exceed MAX_WORDS.
 * ------------------------------------------------------------------------------*/
void InitDictionary(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cout << "\nError opening file: " << filename;
        exit(1);
    }

    string word;
    current_word_count = 0; // Reset word count

    while (getline(file, word) && current_word_count < MAX_WORDS) {
        word_list[current_word_count++] = word;
    }

    file.close();
    srand(static_cast<unsigned>(time(nullptr))); // Seed the random number generator
}

/* -----------------------------------------------------------------------------
 * Function: ChooseRandomWord
 * Usage   : ChooseRandomWord()
 * -----------------------------------------------------------------------------
 * 
 * This function selects a random word from the word_list array.
 * It ensures that there are words available before selecting one.
 * ------------------------------------------------------------------------------*/

string ChooseRandomWord() {
    if (current_word_count == 0) {
        cout << "\nNo words available.";
        exit(1);
    }
    int index = rand() % current_word_count; // Generate a random index
    return word_list[index]; // Return the word at the random index
}
