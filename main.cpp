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
    int availability;
};

const int BOOK_CAPACITY = 500;
BookInfo bookSheleves[BOOK_CAPACITY];
int numOfCurrentBooks = 0;



void readLibraryFile();
void checkoutBook();
void returnBook();
void bookSort();
void bookSearch();
void displayAvailableBooks();



int main() {
    int answer;

    cout << "~~~~Welcome to Danyel Quintana's Library!~~~~\n\n";
    cout << "1: Checkout a Book\n";
    cout << "2: Return a Book\n";
    cout << "3: Sort Books\n";
    cout << "4: Search Books\n";
    cout << "5: List of Available Books\n";
    cout << "6: Leave Library\n\n";
    cout << "What Shall I do?: \n";

    cin >> answer;

 





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
        >> bookSheleves[numOfCurrentBooks].bookNum
        >> bookSheleves[numOfCurrentBooks].title
        >> bookSheleves[numOfCurrentBooks].author
        >> bookSheleves[numOfCurrentBooks].publishYear
        >> bookSheleves[numOfCurrentBooks].availability) 
    {
        numOfCurrentBooks++;
    }

    inFile.close();
};

void checkoutBook() {

};

void returnBook() {

}

void bookSort() {

};

void bookSearch() {

};

void displayAvailableBooks() {

};