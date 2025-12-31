/*
Library Management System (C++)
• Designed an object-oriented library system with persistent storage using file I/O.
• Implemented CRUD operations, borrowing/return workflows, and availability tracking.
• Built search and sort functionality using STL algorithms and lambda expressions.
• Parsed structured data files and managed in-memory state using vectors.
*/

#include <iostream>  
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <limits>
using namespace std;

class Book {
public:
    int id;
    string title;
    string author;
    bool available;

    Book(int id, string title, string author, bool available = true) 
    {
        this->id = id;
        this->title = title;
        this->author = author;
        this->available = available;
    }

    void display() const {
        cout << id << " | " << title << " | " << author
             << " | " << (available ? "Available" : "Borrowed") << endl;
    }
};

class Library {
private:
    vector<Book> books;

public:
    // load books from file
    void loadFromFile(string filename) 
    {
        ifstream file(filename);
        string line;

        while (getline(file, line)) 
        {
            stringstream ss(line); 
            string idStr, title, author, availStr;
            string* var[] = {&idStr, &title, &author, &availStr};

            for (int i = 0; i < 4; i++) 
            {
                getline(ss, *var[i], ',');
            }

            int id = stoi(idStr);
            bool available = (availStr == "1");

            books.push_back(Book(id, title, author, available));
        }
        file.close();
    }

    // save books to file
    void saveToFile(string filename) {
        ofstream file(filename);
        for (auto &b : books) {
            file << b.id << "," << b.title << "," << b.author << ","
                 << (b.available ? "1" : "0") << endl;
        }
        file.close();
    }

    // add a new book
    void addBook(int id, string title, string author) {
        for (auto &b : books) {
            if (b.id == id) {
                cout << "Book with ID " << id << " already exists." << endl;
                return;
            }
        }
        books.push_back(Book(id, title, author));
        cout << "Book added successfully." << endl;
    }

    // remove book
    void removeBook(int id) {
        for (auto it = books.begin(); it != books.end(); ++it) {
            if (it->id == id) {
                books.erase(it);
                cout << "Book with ID " << id << " removed successfully." << endl;
                return;
            }
        }
        cout << "Book with ID " << id << " not found." << endl;
    }

    // borrow book
    void borrowBook(int id) {
        for (auto &b : books) {
            if (b.id == id) {
                if (b.available) {
                    b.available = false;
                    cout << "You borrowed: " << b.title << endl;
                } else {
                    cout << "Book is already borrowed." << endl;
                }
                return;
            }
        }
        cout << "Book not found." << endl;
    }

    // return book
    void returnBook(int id) {
        for (auto &b : books) {
            if (b.id == id) {
                if (!b.available) {
                    b.available = true;
                    cout << "You returned: " << b.title << endl;
                } else {
                    cout << "Book "<< b.title << "was not borrowed." << endl;
                }
                return;
            }
        }
        cout << "Book not found." << endl;
    }

    // search by title
    void searchByTitle(string keyword) {
        for (auto &b : books) {
            if (b.title.find(keyword) != string::npos) {
                b.display();
            }
        }
    }

    // search by author
    void searchByAuthor(string keyword) {
        for (auto &b : books) {
            if (b.author.find(keyword) != string::npos) {
                b.display();
            }
        }
    }

    // update book
    void updateBook(int id, string newTitle, string newAuthor) {
        for (auto &b : books) {
            if (b.id == id) {
                b.title = newTitle;
                b.author = newAuthor;
                cout << "Book updated successfully." << endl;
                return;
            }
        }
        cout << "Book not found." << endl;
    }

    // sort books by title
    void sortByTitle() {
        sort(books.begin(), books.end(),
             [](Book &a, Book &b) { return a.title < b.title; });
    }

    // sort books by author
    void sortByAuthor() {
        sort(books.begin(), books.end(),
             [](Book &a, Book &b) { return a.author < b.author; });
    }

    // display stats
    void stats() {
        int total = books.size();
        int availableCount = 0;
        for (auto &b : books) {
            if (b.available) availableCount++;
        }
        cout << "Total books: " << total << endl
             << "Available: " << availableCount << endl
             << "Borrowed: " << (total - availableCount) << endl;
    }

    // display all books
    void displayBooks() 
    {
        for (auto &b : books) 
        {
            b.display();
        }
    }
};

int question()
{
    int id; 
    cout << "Enter ID: "; 
    cin >> id;
    return id;
}

int main() {
    Library lib;
    lib.loadFromFile("lib.txt");

    int choice;
    do {
        cout << "\n--- Library Menu ---\n";
        cout << "1. Display all books\n";
        cout << "2. Add book\n";
        cout << "3. Remove book\n";
        cout << "4. Borrow book\n";
        cout << "5. Return book\n";
        cout << "6. Search by title\n";
        cout << "7. Search by author\n";
        cout << "8. Update book\n";
        cout << "9. Sort by title\n";
        cout << "10. Sort by author\n";
        cout << "11. Stats\n";
        cout << "12. Save and Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) lib.displayBooks();
        else if (choice == 2) 
        {
            int id; string title, author;
            cout << "Enter ID, title, author: ";
            cin >> id;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            getline(cin, title);
            getline(cin, author);
            lib.addBook(id, title, author);
        }
        else if (choice == 3) 
        {
            int id = question();
            lib.removeBook(id);
        }
        else if (choice == 4) 
        {
            int id=question();
            lib.borrowBook(id);
        }
        else if (choice == 5) 
        {
            int id=question();
            lib.returnBook(id);
        }
        else if (choice == 6) 
        {
            string kw; 
            cout << "Enter title keyword: "; 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            getline(cin, kw);
            lib.searchByTitle(kw);
        }
        else if (choice == 7) 
        {
            string kw; 
            cout << "Enter author keyword: "; 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            getline(cin, kw);
            lib.searchByAuthor(kw);
        }
        else if (choice == 8) 
        {
            int id; string title, author;
            cout << "Enter ID, new title, new author: ";
            cin >> id;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            getline(cin, title);
            getline(cin, author);
            lib.updateBook(id, title, author);
        }
        else if (choice == 9) {
            lib.sortByTitle();
        }
        else if (choice == 10) {
            lib.sortByAuthor();
        }
        else if (choice == 11) {
            lib.stats();
        }

    } while (choice != 12);

    lib.saveToFile("lib.txt");
    cout << "Library saved. Goodbye!\n";

    return 0;
}
