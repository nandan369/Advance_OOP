#include "library.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/* -----------------------------------------------------------------------------
 * Function: getNonEmptyInput
 * Usage   : getNonEmptyInput(string_message)
 * -----------------------------------------------------------------------------
 * 
 * This function Prompts the user for input until a non-empty string is provided
 * ------------------------------------------------------------------------------*/
string getNonEmptyInput(const string& prompt) {
    string input;
    do {
        cout << prompt;
        getline(cin, input);
        if (input.empty()) {
            cout << "Input cannot be empty. Please try again." << endl;
        }
    } while (input.empty());
    return input;
}

/* -----------------------------------------------------------------------------
 * Function: addNewBook
 * Usage   : addNewBook(struct_obj)
 * -----------------------------------------------------------------------------
 * 
 * This function adds a new book to the library data structure.
 * It checks if the library is full before proceeding.
 * Prompts the user to input details of New Book.
 * ------------------------------------------------------------------------------*/
void addNewBook(libraryT& libdata) {
    // Check if the library is full (cannot exceed MAX_BOOKS)
    if (libdata.bookCount >= MAX_BOOKS) {
        cout << "\nLibrary is full! No space left.";
        return;
    }

    libraryT::bookT newBook; // Creating a new book entry

    // Input book title
    newBook.title = getNonEmptyInput("\nEnter book title: ");

    // Input up to MAX_AUTHORS author names
    cout << "\nEnter author names up to " << MAX_AUTHORS << " : ";
    for (int i = 0; i < MAX_AUTHORS; ++i) {
        string author;
        if(i == 0) {author = getNonEmptyInput("\nFirst Auther Name: ");} 
        else{
            cout<<"\nEnter other author Names or press enter to skip :";
            getline(cin, author);
            if (author.empty()) break; // Stop if the user enters an empty string
        }
        newBook.authorNames[i] = author;
    }

    // Input Library of Congress catalog number
    newBook.libCatalogNumber = getNonEmptyInput("\nEnter Library of Congress catalog number: ");

    // Input up to MAX_SUBJECTS subject names
    cout << "\nEnter subjects (up to " << MAX_SUBJECTS << "): ";
    for (int i = 0; i < MAX_SUBJECTS; ++i) {
        string subject;
        if(i == 0) {subject = getNonEmptyInput("\nFirst Subject Name: ");} 
        else {
            cout<<"\nEnter other subjects or press enter to skip :";
            getline(cin, subject);
            if (subject.empty()) break; // Stop if the user enters an empty string
        }
        newBook.subjectNames[i] = subject;
    }

    // Input publisher name
    newBook.publisher = getNonEmptyInput("\nEnter publisher: ");

    // Input year of publication
    cout << "\nEnter year of publication: ";
    cin >> newBook.publicationYear;

    // Input circulation status (1 for yes, 0 for no)
    cout << "\nIs the book circulating (1 for yes, 0 for no): ";
    int circulating;
    cin >> circulating;
    newBook.isCirculating = circulating == 1; // Store as a boolean value

    // Add the new book to the library and increment bookCount
    libdata.books.push_back(newBook);
    libdata.bookCount++;
}

/* -----------------------------------------------------------------------------
 * Function: searchBySubject
 * Usage   : searchBySubject(struct_obj, string_subject)
 * -----------------------------------------------------------------------------
 * 
 * This function searches for books in the library that match a given subject.
 * It iterates over all books in the library and checks each book's subject list.
 * If a match is found, displays the book's title, first author, and Library of Congress catalog number.
 * ------------------------------------------------------------------------------*/
void searchBySubject(const libraryT& libdata, const string& subject) {
    bool foundFlag = false; 
    // Iterate over all books in the library
    for (int i = 0; i < libdata.bookCount; ++i) {  
        const auto& book = libdata.books[i];
        // Iterate over the subjects of the current book
        for (int j = 0; j < MAX_SUBJECTS; ++j) {  
            // Check if the subject matches
            if (book.subjectNames[j] == subject) { 
                // Display book information
                cout << "\n------------------------------------";
                cout << "\nBook with subject : " <<subject; 
                cout << "\nTitle: " << book.title;
                cout << "\nFirst Author: " << book.authorNames[0];
                cout << "\nCatalog Number: " << book.libCatalogNumber;
                cout << "\n------------------------------------";
                foundFlag = true;
                break; // Stop searching the current book once a match is found
            }
        }
    }
    if (!foundFlag) {
        cout << "\nNo books available with the subject: " << subject;
    }
}

/* -----------------------------------------------------------------------------
 * Function: displayAllBooks
 * Usage   : displayAllBooks(struct_obj)
 * -----------------------------------------------------------------------------
 * 
 * This function displays the title and authors of all books in the library.
 * It iterates through all the books in the library and prints book title and auther names.
 * ------------------------------------------------------------------------------*/
void displayAllBooks(const libraryT& libdata) {
    for (int i = 0; i < libdata.bookCount; ++i) {
        cout << "\nTitle: " << libdata.books[i].title;
        cout << "\nAuthors: ";
        for (const auto& author : libdata.books[i].authorNames) {
            if (!author.empty()) cout << author << ", ";
        }
        cout << "\n------------------------------------";
    }
}

/* -----------------------------------------------------------------------------
 * Function: displayMenu
 * Usage   : displayMenu()
 * -----------------------------------------------------------------------------
 * 
 * This function displays the option menu for user
 * ------------------------------------------------------------------------------*/
void displayMenu() {
    cout << "\nLibrary Menu:";
    cout << "\n1. Add a new book";
    cout << "\n2. Search by subject";
    cout << "\n3. Display all books";
    cout << "\n4. Exit";
    cout << "\nEnter your choice: ";
}
