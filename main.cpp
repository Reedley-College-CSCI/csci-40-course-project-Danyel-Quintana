// CSCI-40 Final Project - Danyel's Library
// Author: Danyel Quintana 

/* 
 Description:
 This app allows you the user to browse my library of books
 You can checkout, return, sort, search, and browse all the books!
 This can be done by entering the prompted numbers
 Reads from Library.txt with its selection of 15 books (includes number,title,author,year,and availability)
 checking out a book will not allow you to check it out again untill it is returned
 Enjoy!
 
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//Struct to keep book info together
struct BookInfo {
    int bookNum = 0;
    string title;
    string author;
    int publishYear = 0;
    bool availability = true;
};

const int BOOK_CAPACITY = 500; //Max books possible in Library.txt

BookInfo bookShelves[BOOK_CAPACITY];//Array holding data of struct values
int numOfCurrentBooks = 0;

//Prototypes
void readLibraryFile();
void saveLibraryFile();
void checkoutBook();
void returnBook();
void bookSortBy(int num);
void bookSearch();
void displayBooks();


int main() {
    readLibraryFile();//see function

    int answer;
    

    do {
        //Main menu prompts user for answer
        cout << "~~~~Welcome to Danyel's Library!~~~~\n\n";
        cout << "1: Checkout a Book\n";
        cout << "2: Return a Book\n";
        cout << "3: Sort Books\n";
        cout << "4: Search Books\n";
        cout << "5: Browse Books\n";
        cout << "6: Leave Library\n\n";
        cout << "What Shall I do?: \n";

        cin >> answer;
        //Switch statement to respond to answer
        switch (answer) {
        case 1: checkoutBook(); break;
        case 2: returnBook(); break;
        case 3:{
            int sortBy = 0;//arguement for function bookSortBy
            cout << "How would you like them sorted?\n1:BookNum\n2:Title\n3:Author\n4:Publication\n5:Availability\n\n";
            cin >> sortBy;
            bookSortBy(sortBy);
            displayBooks();
            break;
        }
        case 4: bookSearch(); break;
        case 5: displayBooks(); break;
        case 6: saveLibraryFile(); break; 
        default: cout << "Error: Please enter an integer 1 - 6\n";//when invalid input
        }

    } while (answer != 6);//entering 6 ends program

    return 0;
}

//reads from Library.txt
//prompts error on failure to load file
//assigns data to struct variables
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
    //always close when done
    inFile.close();
}
//Saves changes to struct data
void saveLibraryFile() 
{
    ofstream outFile("Library.txt");

    for (int i = 0; i < numOfCurrentBooks; i++) 
    {
        outFile
            << bookShelves[i].bookNum << " "
            << bookShelves[i].title << " "
            << bookShelves[i].author << " "
            << bookShelves[i].publishYear << " "
            << bookShelves[i].availability << "\n";
    }
    //always close when done
    outFile.close();
}
//displays users all books and their relevant info
void displayBooks()
{
    cout << "\nAll Books:\n";
    for (int i = 0; i < numOfCurrentBooks; i++)
    {
        cout << bookShelves[i].bookNum << " "
            << bookShelves[i].title << " "
            << bookShelves[i].author << " "
            << bookShelves[i].publishYear << " "
            << (bookShelves[i].availability ? "Available" : "Checked Out") << "\n";
    }
    cout << endl;
}
//changes a book availability to checkouted by user instruction
void checkoutBook()
{
    displayBooks();

    int bookId;
    bool bookFound = false;

    cout << "\nEnter the number of the book you would like to check out: \n";

    cin >> bookId;
   
    for (int i = 0; i < numOfCurrentBooks; i++)
    {
        if (bookShelves[i].bookNum == bookId)
        {
            bookFound = true;

            if (bookShelves[i].availability)
            {
                bookShelves[i].availability = 0; 
                cout << "You checked out: " << bookShelves[i].title << "\n\n";
                saveLibraryFile();//saves changes
            }
            else
                cout << "This book is already checked out.\n\n";
           
            break;

        }

    }
}
//changes a book availability to available by user instruction
void returnBook() {
    displayBooks();

    int bookId;
    bool bookFound = false;

    cout << "\nEnter the number of the book you would like to return: \n";

    cin >> bookId;

    for (int i = 0; i < numOfCurrentBooks; i++)
    {
        if (bookShelves[i].bookNum == bookId)
        {
            bookFound = true;

            if (!bookShelves[i].availability)
            {
                bookShelves[i].availability = 1;
                cout << "You returned: " << bookShelves[i].title << "\n\n";
                saveLibraryFile();//saves changes
            }
            else
                cout << "This book is in stock.\n\n";

            break;
                
        }

    }
}
//sorts books by users wanted type
//bookNum
//Title
//Author
//Published year
//Availability
void bookSortBy(int num) {
   
    if (num < 1 || num > 5) {
        cout << "Enter an integer between 1-5\n";
        return;
    }

    for (int i = 0; i < numOfCurrentBooks - 1; i++) {
        for (int j = 0; j < numOfCurrentBooks - i - 1; j++) {
            if (num == 1) {
                if (bookShelves[j].bookNum > bookShelves[j + 1].bookNum) {
                    BookInfo temp = bookShelves[j];
                    bookShelves[j] = bookShelves[j + 1];
                    bookShelves[j + 1] = temp;
                }
            }
            if (num == 2) {
                if (bookShelves[j].title > bookShelves[j + 1].title) {
                    BookInfo temp = bookShelves[j];
                    bookShelves[j] = bookShelves[j + 1];
                    bookShelves[j + 1] = temp;
                }
            }
            if (num == 3) {
                 if (bookShelves[j].author > bookShelves[j + 1].author) {
                    BookInfo temp = bookShelves[j];
                    bookShelves[j] = bookShelves[j + 1];
                    bookShelves[j + 1] = temp;
                    }
            }
            if (num == 4) {
                if (bookShelves[j].publishYear > bookShelves[j + 1].publishYear) {
                    BookInfo temp = bookShelves[j];
                    bookShelves[j] = bookShelves[j + 1];
                    bookShelves[j + 1] = temp;
                }
            }
            if (num == 5) {
                if (bookShelves[j].availability > bookShelves[j + 1].availability) {
                    BookInfo temp = bookShelves[j];
                    bookShelves[j] = bookShelves[j + 1];
                    bookShelves[j + 1] = temp;
                }
            }
            
        }
    }
}
//Allows user to search for book however must
//Include underscores in places of spaces
//displays searched book if found
void bookSearch() {
    cin.ignore();
    string bookTitleSearched;
    cout << "Enter a title to search (Include underscores in places of spaces): ";
    getline(cin, bookTitleSearched);

    bool bookFound = false;
    for (int i = 0; i < numOfCurrentBooks; i++) {
        if (bookShelves[i].title == bookTitleSearched) {
            bookFound = true;
            cout << "\nYou Found Your Book!:\n";
            cout << "BookNum: " << bookShelves[i].bookNum << "\n"
                << "Title: " << bookShelves[i].title << "\n"
                << "Author: " << bookShelves[i].author << "\n"
                << "Year: " << bookShelves[i].publishYear << "\n"
                << "Status: " << (bookShelves[i].availability ? "Available" : "Checked Out") << "\n\n";
        }
    }

    if (!bookFound)
        cout << "No book found with that title.\nTry including underscores in place of spaces\nEX: The_Maze_Runner\n\n";
}

