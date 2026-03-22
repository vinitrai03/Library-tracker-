#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

class Book {
public:
    int id;
    string title;
    string author;
    bool isBorrowed;

    Book(int _id, string _title, string _author)
        : id(_id), title(_title), author(_author), isBorrowed(false) {}
};

class Member {
public:
    int memberId;
    string name;
    vector<int> borrowedBooks;

    Member(int _id, string _name)
        : memberId(_id), name(_name) {}
};
class Library {
private:
    vector<Book> books;
    vector<Member> members;

public:
    void addBook(int id, string title, string author) {
        books.push_back(Book(id, title, author));
        cout << "Book added successfully!\n";
    }

    void addMember(int id, string name) {
        members.push_back(Member(id, name));
        cout << "Member added successfully!\n";
    }

    void displayBooks() {
        cout << "\n--- Book List ---\n";
        cout << setw(5) << "ID" << setw(25) << "Title" << setw(25) << "Author" << setw(15) << "Status\n";
        for (auto &b : books) {
            cout << setw(5) << b.id << setw(25) << b.title << setw(25) << b.author
                 << setw(15) << (b.isBorrowed ? "Borrowed" : "Available") << "\n";
        }
    }

    void borrowBook(int bookId, int memberId) {
        for (auto &b : books) {
            if (b.id == bookId && !b.isBorrowed) {
                for (auto &m : members) {
                    if (m.memberId == memberId) {
                        b.isBorrowed = true;
                        m.borrowedBooks.push_back(bookId);
                        cout << "Book borrowed successfully!\n";
                        return;
                    }
                }
            }
        }
        cout << "Error: Book not available or member not found.\n";
    }

    void returnBook(int bookId, int memberId) {
        for (auto &m : members) {
            if (m.memberId == memberId) {
                for (int i = 0; i < m.borrowedBooks.size(); i++) {
                    if (m.borrowedBooks[i] == bookId) {
                        m.borrowedBooks.erase(m.borrowedBooks.begin() + i);
                        for (auto &b : books) {
                            if (b.id == bookId) {
                                b.isBorrowed = false;
                                cout << "Book returned successfully!\n";
                                return;
                            }
                        }
                    }
                }
            }
        }
        cout << "Error: Book not found in member's borrowed list.\n";
    }

    void saveData() {
        ofstream out("library_data.txt");
        for (auto &b : books) {
            out << b.id << "," << b.title << "," << b.author << "," << b.isBorrowed << "\n";
        }
        out.close();
        cout << "Data saved to file.\n";
    }
};
int main() {
    Library lib;
    int choice;

    while (true) {
        cout << "\n--- Library Tracker Menu ---\n";
        cout << "1. Add Book\n2. Add Member\n3. Display Books\n4. Borrow Book\n5. Return Book\n6. Save Data & Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int id;
            string title, author;
            cout << "Enter Book ID: "; cin >> id;
            cin.ignore();
            cout << "Enter Title: "; getline(cin, title);
            cout << "Enter Author: "; getline(cin, author);
            lib.addBook(id, title, author);
        }
        else if (choice == 2) {
            int id;
            string name;
            cout << "Enter Member ID: "; cin >> id;
            cin.ignore();
            cout << "Enter Member Name: "; getline(cin, name);
            lib.addMember(id, name);
        }
        else if (choice == 3) {
            lib.displayBooks();
        }
        else if (choice == 4) {
            int bookId, memberId;
            cout << "Enter Book ID: "; cin >> bookId;
            cout << "Enter Member ID: "; cin >> memberId;
            lib.borrowBook(bookId, memberId);
        }
        else if (choice == 5) {
            int bookId, memberId;
            cout << "Enter Book ID: "; cin >> bookId;
            cout << "Enter Member ID: "; cin >> memberId;
            lib.returnBook(bookId, memberId);
        }
        else if (choice == 6) {
            lib.saveData();
            break;
        }
        else {
            cout << "Invalid choice.\n";
        }
    }
    return 0;
}
