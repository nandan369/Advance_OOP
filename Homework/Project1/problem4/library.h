#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Constants
const int MAX_AUTHORS = 5;   // Maximum number of authors allowed per book
const int MAX_SUBJECTS = 5;  // Maximum number of subject headings allowed per book
const int MAX_BOOKS = 1000;  // Maximum number of books allowed in the library

// Defining a structure for the library
struct libraryT {
    struct bookT {
        string title;                        // Book title
        string authorNames[MAX_AUTHORS];     // Array of author names
        string libCatalogNumber;             // Library of Congress catalog number
        string subjectNames[MAX_SUBJECTS];   // Array of subject headings
        string publisher;                    // Book publisher
        int publicationYear;                 // Year of publication
        bool isCirculating;                  // Circulation status (true = circulating, false = non-circulating)
    };

    std::vector<bookT> books;
    int bookCount;
};

// Function declarations
string getNonEmptyInput(const string& prompt);
void addNewBook(libraryT& libdata);
void searchBySubject(const libraryT& libdata, const string& subject);
void displayAllBooks(const libraryT& libdata);
void displayMenu();

#endif // LIBRARY_H
