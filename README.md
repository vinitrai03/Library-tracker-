# Library Tracker

A simple, console-based C++ application to manage a small library's book inventory and membership.

## Features

- **Add Book**: Register a new book with an ID, Title, and Author.
- **Add Member**: Register a new library member with an ID and Name.
- **Display Books**: View a formatted list of all books along with their current availability status (Available / Borrowed).
- **Borrow Book**: Allow a member to check out an available book using their Member ID and the Book ID.
- **Return Book**: Process the return of a borrowed book.
- **Save Data & Exit**: Save the current library inventory state to a local text file (`library_data.txt`) before exiting the application.

## How to Run

1. Compile the code using a C++ compiler. For example:
   ```bash
   g++ code.cpp -o code
   ```
2. Run the executable:
   ```bash
   ./code
   ```
   *(On Windows, run `.\code.exe`)*
