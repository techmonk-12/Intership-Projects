#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <fstream>
#include <cstdlib>
#include <conio.h>

using namespace std;

class LibraryManagement
{
    private:
        string bookTitle;
        string author;
        int bookID;
        int quantity;

    public:
        void addBook();
        void displayBooks();
        void searchBook();
        void modifyBook();
        void deleteBook();
        void menu();
};

void LibraryManagement::menu()
{
    menuStart:
    int choice;
    system("cls");

    cout<<"-----------------------------------------\n";
    cout<<"|       LIBRARY MANAGEMENT SYSTEM       |\n";
    cout<<"-----------------------------------------\n";
    cout<<"| 1. Add Book                           |\n";
    cout<<"| 2. View Books                         |\n";
    cout<<"| 3. Modify Book                        |\n";
    cout<<"| 4. Search Book                        |\n";
    cout<<"| 5. Delete Book                        |\n";
    cout<<"| 6. Exit                               |\n";
    cout<<"-----------------------------------------\n\n";

    cout<<"Enter your choice: ";
    cin>>choice;

    switch(choice)
    {
        case 1:
            addBook();
            break;

        case 2:
            displayBooks();
            break;

        case 3:
            modifyBook();
            break;

        case 4:
            searchBook();
            break;

        case 5:
            deleteBook();
            break;

        case 6:
            exit(0);

        default:
            cout<<"\nInvalid choice! Please try again.\n";
    
    }
    getch();
    goto menuStart;
}

void LibraryManagement::addBook()
{
    system("cls");
    fstream file;
    cout<<"-----------------------------------------\n";
    cout<<"|         ADD BOOK RECORD               |\n";
    cout<<"-----------------------------------------\n";
    cout<<"Enter Book Title: "; cin>>bookTitle;
    cout<<"Enter Author Name: "; cin>>author;
    cout<<"Enter Book ID: "; cin>>bookID;
    cout<<"Enter Quantity: "; cin>>quantity;

    file.open("libraryRecord.txt", ios::app | ios::out);
    file<<bookTitle<<" "<<author<<" "<<bookID<<" "<<quantity<<endl;
    file.close();

    cout<<"\nBook record added successfully!\n";
    system("pause");
}

void LibraryManagement::displayBooks()
{
    system("cls");
    fstream file;
    cout<<"-----------------------------------------\n";
    cout<<"|         VIEW BOOK RECORDS             |\n";
    cout<<"-----------------------------------------\n";
    file.open("libraryRecord.txt", ios::in);
    if(!file)
    {
        cout<<"File not found!"<<endl;
        file.close(); 
        return;
    }
    else
    {
        file>>bookTitle>>author>>bookID>>quantity;
        while(!file.eof())
        {
            cout<<"Book Title: "<<bookTitle<<endl;
            cout<<"Author: "<<author<<endl;
            cout<<"Book ID: "<<bookID<<endl;
            cout<<"Quantity: "<<quantity<<endl;
            cout<<"-----------------------------------------\n";
            file>>bookTitle>>author>>bookID>>quantity;
        }
        file.close();
    }
}

void LibraryManagement::searchBook()
{
    system("cls");
    fstream file;
    cout<<"-----------------------------------------\n";
    cout<<"|         SEARCH BOOK RECORD             |\n";
    cout<<"-----------------------------------------\n";
    file.open("libraryRecord.txt", ios::in);
    if(!file)
    {
        cout<<"File not found!"<<endl;
        file.close(); 
        return;
    }
    else
    {
        int bookIDToSearch;
        cout<<"Enter Book ID to search: ";
        cin>>bookIDToSearch;
        bool found = false;
        file>>bookTitle>>author>>bookID>>quantity;
        while(!file.eof())
        {
            if(bookID == bookIDToSearch)
            {
                found = true;
                cout<<"Book Title: "<<bookTitle<<endl;
                cout<<"Author: "<<author<<endl;
                cout<<"Book ID: "<<bookID<<endl;
                cout<<"Quantity: "<<quantity<<endl;
                cout<<"-----------------------------------------\n";
            }
            file>>bookTitle>>author>>bookID>>quantity;
        }
        if(!found)
        {
            cout<<"Book with ID "<<bookIDToSearch<<" not found!"<<endl;
        }
        file.close();
    }
}

void LibraryManagement::modifyBook()
{
    system("cls");
    fstream file, file1;
    cout<<"-----------------------------------------\n";
    cout<<"|         MODIFY BOOK RECORD             |\n";
    cout<<"-----------------------------------------\n";
    file.open("libraryRecord.txt", ios::in);
    if(!file)
    {
        cout<<"File not found!"<<endl;
        file.close(); 
        return;
    }
    else
    {
        int bookIDToModify;
        cout<<"Enter Book ID to modify: ";
        cin>>bookIDToModify;
        bool found = false;
        file1.open("temp.txt", ios::out);
        file>>bookTitle>>author>>bookID>>quantity;
        while(!file.eof())
        {
            if(bookID == bookIDToModify)
            {
                found = true;
                cout<<"Enter new Book Title: "; cin>>bookTitle;
                cout<<"Enter new Author Name: "; cin>>author;
                cout<<"Enter new Quantity: "; cin>>quantity;
            }
            file1<<bookTitle<<" "<<author<<" "<<bookID<<" "<<quantity<<endl;
            file>>bookTitle>>author>>bookID>>quantity;
        }
        file.close();
        file1.close();
        remove("libraryRecord.txt");
        rename("temp.txt", "libraryRecord.txt");
        if(found)
        {
            cout<<"\nBook record modified successfully!\n";
        }
        else
        {
            cout<<"\nBook with ID "<<bookIDToModify<<" not found!\n";
        }
    }
}

void LibraryManagement::deleteBook()
{
    system("cls");
    fstream file, file1;
    cout<<"-----------------------------------------\n";
    cout<<"|         DELETE BOOK RECORD             |\n";
    cout<<"-----------------------------------------\n";
    file.open("libraryRecord.txt", ios::in);
    if(!file)
    {
        cout<<"File not found!"<<endl;
        file.close(); 
        return;
    }
    else
    {
        int bookIDToDelete;
        cout<<"Enter Book ID to delete: ";
        cin>>bookIDToDelete;
        bool found = false;
        file1.open("temp.txt", ios::out);
        file>>bookTitle>>author>>bookID>>quantity;
        while(!file.eof())
        {
            if(bookID == bookIDToDelete)
            {
                found = true;
                cout<<"\nBook record deleted successfully!\n";
            }
            else
            {
                file1<<bookTitle<<" "<<author<<" "<<bookID<<" "<<quantity<<endl;
            }
            file>>bookTitle>>author>>bookID>>quantity;
        }
        file.close();
        file1.close();
        remove("libraryRecord.txt");
        rename("temp.txt", "libraryRecord.txt");
        if(!found)
        {
            cout<<"\nBook with ID "<<bookIDToDelete<<" not found!\n";
        }
    }
}


int main()
{
    LibraryManagement library;
    library.menu();
    return 0;
}