#include <iostream>
#include <string>
#include "randword.h"

using namespace std;

#define MAX_INCORRECT_ATTEMPTS 8
#define MAX_WORD_SIZE 100 // Define maximum word size

// Static array to hold guessed letters
static bool guessed_letters[MAX_WORD_SIZE] = { false };

/* -----------------------------------------------------------------------------
 * Function: DisplayCurrentState
 * Usage   : DisplayCurrentState(word)
 * -----------------------------------------------------------------------------
 * 
 * This function prints the current state of the word being guessed.
 * It shows correctly guessed letters and hides unguessed letters with dashes.
 * ------------------------------------------------------------------------------*/
 
void DisplayCurrentState(const string& word) {
    for (size_t i = 0; i < word.size(); ++i) {
        if (guessed_letters[i]) {
            cout << word[i];
        } else {
            cout << "-";
        }
    }
    cout <<"\n";
}

/* -----------------------------------------------------------------------------
 * Function: AreAllLettersGuessed
 * Usage   : AreAllLettersGuessed(word)
 * -----------------------------------------------------------------------------
 * 
 * This function checks if all letters in the word have been guessed.
 * It returns true if all letters have been guessed; otherwise, false.
 * ------------------------------------------------------------------------------*/

bool AreAllLettersGuessed(const string& word) {
    for (size_t i = 0; i < word.size(); ++i) {
        if (!guessed_letters[i]) return false;
    }
    return true;
}

 /* -----------------------------------------------------------------------------
 * Function: Main()
 * -----------------------------------------------------------------------------
 * 
 * This is the main function of the Hangman game.
 * It handles the core game logic including initialization, user input, and game state updates.
 * ------------------------------------------------------------------------------*/
int main() {
    try {
        InitDictionary("wordsList.txt");  // Provide the path to your words file
        string secret_word = ChooseRandomWord();

        // Initialize guessed_letters array based on the length of the secret word
        for (size_t i = 0; i < secret_word.size(); ++i) {
            guessed_letters[i] = false;
        }

        int incorrect_attempts = 0;
        char guessed_char;
        bool letter_found;

        while (incorrect_attempts < MAX_INCORRECT_ATTEMPTS) {
            // Display the current state of the word, showing correctly guessed letters and hiding others with dashes.
            DisplayCurrentState(secret_word);

            cout << "Guess a letter: ";
            cin >> guessed_char;

            letter_found = false; // Reset the letter_found flag for each new guess.
            for (size_t i = 0; i < secret_word.size(); ++i) {
                if (secret_word[i] == guessed_char) {
                    guessed_letters[i] = true;
                    letter_found = true;
                }
            }

            // If the guessed letter was not found in the secret word, increment the incorrect_attempts counter.
            if (!letter_found) {
                incorrect_attempts++;
                cout << "\nIncorrect guess. You have " << (MAX_INCORRECT_ATTEMPTS - incorrect_attempts) << " guesses left.";
            }

            // Check if all letters in the secret word have been guessed.
            if (AreAllLettersGuessed(secret_word)) {
                cout << "\nYou've guessed the word correctly..! " << secret_word;
                break;  //Existing the loop as 
            }
        }

        if (incorrect_attempts >= MAX_INCORRECT_ATTEMPTS) {
            cout << "\nNo guesses left..! The word was: " << secret_word;
        }
    } catch (const exception& e) {
        // Handle any exceptions that occur during the execution of the game.
        cerr << "\nError: " << e.what();
        return 1;
    }

    return 0;
}
