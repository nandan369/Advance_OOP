#include "library.h"
#include <iostream>
#include <limits>

/* -------------------------------------------------------
 * Function: Main()
 * -------------------------------------------------------
 * This function provides a menu-driven interface for managing a library system. 
 * It allows users to add new books, search by subject, display all books, or exit the program.
 * -------------------------------------------------------
 */
int main() {
    libraryT libdata;        
    libdata.bookCount = 5;   

    // Populating the library with some sample books
    libdata.books.push_back({"Mystery of the Lost City", {"Jane Smith", "Alan Doe", "", "", ""}, "0012345678", 
        {"Mystery", "Adventure", "", "", ""}, "Fictional Press", 1998, true});

    libdata.books.push_back({"The Science of Everything", {"Dr. John Expert", "", "", "", ""}, "0019876543", 
        {"Science", "Technology", "", "", ""}, "Tech Publishers", 2012, true});

    libdata.books.push_back({"History of the World", {"Emma Brown", "Chris Green", "", "", ""}, "0023456789", 
        {"History", "World Affairs", "", "", ""}, "Global Knowledge", 2005, false});

    libdata.books.push_back({"Cooking for Beginners", {"Chef Gordon", "Mary White", "", "", ""}, "0034567890", 
        {"Cooking", "Health", "", "", ""}, "Culinary Arts", 2018, true});

    libdata.books.push_back({"A Journey to the Stars", {"Astro Mike", "", "", "", ""}, "0045678901", 
        {"Space", "Astronomy", "", "", ""}, "Galaxy Publications", 2021, false});

    bool isRunning = true;
    while (isRunning) {
        displayMenu(); // Display the menu
        int choice;
        // cin >> choice;
        // Input validation 
        while (!(cin >> choice)) {
            cin.clear();  // Clear the error flag on cin.
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input.
            cout << "Invalid input. Please enter a number: ";
        }

        cin.ignore();  // Clear the input buffer to handle getline correctly
        switch (choice) {
            case 1:
                addNewBook(libdata); // Call the function to add a new book
                break;

            case 2: {
                string subject;
                cout << "\nEnter subject heading to search: ";
                getline(cin, subject);  // Get subject input from user
                searchBySubject(libdata, subject); // Search books by subject
                break;
            }
            case 3:
                displayAllBooks(libdata); // Display all books
                break;

            case 4:
                cout << "\nExiting...";
                isRunning = false; // Exit the loop and terminate the program
                break;

            default:
                cout << "\nInvalid choice, please try again."; // Handle invalid input
                break;
        }
    }

    return 0;
}

