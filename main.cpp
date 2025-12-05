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
void bookSortBy();
void bookSearch();
void displayAvailableBooks();



int main() {
    int answer;

    cout << "~~~~Welcome to Danyel Quintana's Library!~~~~\n\n";
    cout << "1: Checkout a Book\n";
    cout << "2: Return a Book\n";
    cout << "3: Sort Books by...\n";
    cout << "4: Search Books\n";
    cout << "5: List of Available Books\n";
    cout << "6: Leave Library\n\n";
    cout << "What Shall I do?: \n";

    cin >> answer;







    return 0;
}

void readLibraryFile() {
    ifstream
};

void checkoutBook() {

};

void returnBook() {

}

void bookSortBy() {

};

void bookSearch() {

};

void displayAvailableBooks() {

};