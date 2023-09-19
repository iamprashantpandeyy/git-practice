// a library management system - coded by Prashant Pandey 
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Book {
private:
    string title; // title of the book
    string author; // author name 
    string isbn; // International Standard Book Number
    bool available; // is available or not in library

public:
    // Constructor
    Book(string title, string author, string isbn){
        this->title = title;
        this->author = author;
        this->isbn = isbn;
    }
     
    // get methods
    string getTitle() { return title; }
    string getAuthor() { return author; }
    string getISBN() { return isbn; }
    bool isAvailable() { return available; }

    // Mark the book as borrowed or returned
    void borrowBook() { available = false; }
    void returnBook() { available = true; }
};

class Patron {
private:
    string name; // name of patron 
    int id; // his library id
    vector<Book*> borrowedBooks; // books he borrowed

public:
    // class Constructor
    Patron(string name, int id){
        this ->  name = name ;
        this -> id = id;
    }

    // get methods
    string getName() { return name; }
    int getID() { return id; }

    // he borrowed a new book
    void borrowBook(Book* book) {
        borrowedBooks.push_back(book);
    }

    // to show all borrowed books
    void displayBorrowedBooks() {
        cout << "Borrowed books for " << name << " having ID - " << id << endl;
        int i=1;
        for (const auto& book : borrowedBooks) {
            cout<< i++ << ". Book title - " << book->getTitle() << ", author - "<< book->getAuthor() << " & ISBN - "<< book->getISBN()<< endl;
        }
        cout<< endl;
    }
};

class Transaction {
private:
    Book* book;
    Patron* patron;
    time_t dueDate;

public:
    // Constructor
    Transaction(Book* book, Patron* patron) {
        // Calculate due date (14 days from now)
        this->book = book;
        this->patron = patron;
        time_t now = time(nullptr);
        dueDate = now + 14 * 24 * 60 * 60; // 14 days in seconds
    }

    // Display transaction details
    void displayTransaction() {
        cout << "Transaction Details: "<<endl;
        cout << "Book title: " << book->getTitle() << endl;
        cout << "Borrower name: " << patron->getName() << endl;
        cout << "Due Date: " << ctime(&dueDate)<<endl;
    }
};

int main() {
    // creating books and patrons
    Book book1("Harry potter", "Prashant", "ISBN1");
    Book book2("Introduction to C++", "Kevin", "ISBN2");

    Patron patron1("Patron 1", 1);

    // borrowing a book
    patron1.borrowBook(&book1); 
    patron1.borrowBook(&book2);
    
    patron1.displayBorrowedBooks();
    
    Transaction transaction1 (&book1,&patron1);
    transaction1.displayTransaction();
    
    Transaction transaction2 (&book2,&patron1);
    transaction2.displayTransaction();
    
    return 0;
}

/*
1.Encapsulation: Classes like Book, Patron, and Transaction encapsulate their attributes and methods. Data members are  private, which restricts direct access from outside the class. Public methods are provided to interact with and manipulate the internal state of objects.

2. Abstraction: The classes abstract real-world concepts: Book represents a book, Patron represents a library patron, and Transaction represents a book borrowing transaction. The details of how these concepts are implemented are hidden behind their respective classes.

3. Constructor: Each class has a constructor to initialize object attributes during creation. For example, the Book class has a constructor that initializes attributes like title, author, and ISBN.
Member Functions: Each class defines member functions that provide behavior specific to the class. For instance, the borrowBook() and returnBook() methods in the Book class control the book's availability status.

4. Getter Methods: Getter methods like getTitle(), getAuthor(), getName(), etc., allow controlled access to private attributes.

5. Composition: The Patron class has a vector of Book* pointers to represent the books a patron has borrowed. This is a form of composition where a class (in this case, Patron) contains objects of another class (Book).

6. Aggregation: The Transaction class aggregates instances of the Book and Patron classes, forming a "has-a" relationship.
*/
