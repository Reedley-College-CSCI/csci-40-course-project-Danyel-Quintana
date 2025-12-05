// CSCI-40 Final Project
// Author: Danyel Quintana 

/* 
 Description:
 
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct BookInfo {
    int bookNum;
    string title;
    string author;
    int publishYear;
    bool availability;
};

const int BOOK_CAPACITY = 500;
BookInfo bookShelves[BOOK_CAPACITY];
int numOfCurrentBooks = 0;



void readLibraryFile();
void saveLibraryFile();
void checkoutBook();
void returnBook();
void bookSort();
void bookSearch();
void displayBooks();



int main() {
    readLibraryFile();

    int answer;

    do {

        cout << "~~~~Welcome to Danyel Quintana's Library!~~~~\n\n";
        cout << "1: Checkout a Book\n";
        cout << "2: Return a Book\n";
        cout << "3: Sort Books\n";
        cout << "4: Search Books\n";
        cout << "5: Leave Library\n\n";
        cout << "What Shall I do?: \n";

        cin >> answer;
        switch (answer) {
        case 1: checkoutBook(); break;
        case 2: returnBook(); break;
        case 3: bookSort(); break;
        case 4: bookSearch(); break;
        case 5: saveLibraryFile(); break; 
        default: cout << "Please enter an integer 1 - 5\n";
        }

    } while (answer != 5);

    return 0;
}

void readLibraryFile() {
    ifstream inFile("Library.txt");
    if (!inFile) {
        cout << "Error: Could not load Library.txt";
        return;
    }

   
    numOfCurrentBooks = 0;
    while 
        (numOfCurrentBooks < BOOK_CAPACITY &&
        inFile 
        >> bookShelves[numOfCurrentBooks].bookNum
        >> bookShelves[numOfCurrentBooks].title
        >> bookShelves[numOfCurrentBooks].author
        >> bookShelves[numOfCurrentBooks].publishYear
        >> bookShelves[numOfCurrentBooks].availability)
    {
        numOfCurrentBooks++;
    }

    inFile.close();
};

void saveLibraryFile() {
    ofstream outFile("Library.txt");

    for (int i = 0; i < numOfCurrentBooks; i++) {
        outFile
            << bookShelves[i].bookNum << " "
            << bookShelves[i].title << " "
            << bookShelves[i].author << " "
            << bookShelves[i].publishYear << " "
            << bookShelves[i].availability << "\n";
    }

    outFile.close();
};

void checkoutBook() {
    displayBooks();
};

void returnBook() {
    displayBooks();
}

void bookSort() {

};

void bookSearch() {

};

void displayBooks() {
    cout << "\nAll Books:\n";
    for (int i = 0; i < numOfCurrentBooks; i++) {
        cout << bookShelves[i].bookNum << " "
            << bookShelves[i].title << " "
            << bookShelves[i].author << " "
            << bookShelves[i].publishYear << " "
            << (bookShelves[i].availability ? "Available" : "Checked Out") << "\n";
    };
}