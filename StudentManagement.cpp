#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <conio.h>
using namespace std;

class student
{
    private:
    string name, rollno, course, address, email, phone;
    public:
        void insert();
        void display();
        void modify();
        void search();
        void deleteRecord();
        void menu();
        
};

void student::menu()
{
    menuStart:
    int choice;
    char x;
    system("cls");

    cout<<"-----------------------------------------\n";
    cout<<"|         STUDENT MANAGEMENT SYSTEM     |\n";
    cout<<"-----------------------------------------\n";
    cout<<"| 1. Add Student                        |\n";
    cout<<"| 2. View Students                      |\n";
    cout<<"| 3. Modify Student                     |\n";
    cout<<"| 4. Search Student                     |\n";
    cout<<"| 5. Delete Student                     |\n";
    cout<<"| 6. Exit                               |\n";
    cout<<"-----------------------------------------\n\n";
    cout<<"Enter your choice: "; cin>>choice;
    cout<<endl;

    switch(choice)
    {
        case 1:
            do{
                insert();
                cout<<"\nAdd another student record? (y/n): ";
                cin>>x;
            }while(x=='y'||x=='Y');
            break;
        case 2:
            display();
            break;
        case 3:
            modify();
            break;
        case 4:
            search();
            break;
        case 5:
            deleteRecord();
            break;
        case 6:
            cout<<"Exiting the program..."<<endl;
            exit(0);
        default:
            cout<<"Invalid choice!"<<endl;
    }
    getch();
    goto menuStart;
}

void student::insert()
{
    system("cls");
    fstream file;
    cout<<"-----------------------------------------\n";
    cout<<"|         ADD STUDENT RECORD             |\n";
    cout<<"-----------------------------------------\n";
    cout<<"Enter Name: ";cin>>name;
    cout<<"Enter Roll Number: ";cin>>rollno;
    cout<<"Enter Course: ";cin>>course;
    cout<<"Enter Email: ";cin>>email;
    cout<<"Enter Phone: ";cin>>phone; 
    cout<<"Enter Address: ";cin>>address;
    file.open("studentRecord.txt", ios::app | ios::out);
    file<<name<<" "<<rollno<<" "<<course<<" "<<email<<" "<<phone<<" "<<address<<endl;
    file.close();

}

void student::display()
{
    system("cls");
    fstream file;
    int total=0;
    cout<<"-----------------------------------------\n";
    cout<<"|         STUDENT RECORDS                |\n";
    cout<<"-----------------------------------------\n";
    file.open("studentRecord.txt", ios::in);
    if(!file)
    {
        cout<<"File not found!"<<endl;
        file.close(); 
        return;
    }
    else
    {
        file>>name>>rollno>>course>>email>>phone>>address;
        while(!file.eof())
        {
            total++;
            cout<<"Name: "<<name<<endl;
            cout<<"Roll Number: "<<rollno<<endl;
            cout<<"Course: "<<course<<endl;
            cout<<"Email: "<<email<<endl;
            cout<<"Phone: "<<phone<<endl;
            cout<<"Address: "<<address<<endl;
            cout<<"-----------------------------------------\n";
            file>>name>>rollno>>course>>email>>phone>>address;
        }
        if(total==0)
        {
            cout<<"No records found!"<<endl;
        }
        file.close();
    }
}

void student::modify()
{
    system("cls");
    fstream file, file1;
    cout<<"-----------------------------------------\n";
    cout<<"|         MODIFY STUDENT RECORD          |\n";
    cout<<"-----------------------------------------\n";
    if(!file)
    {
        cout<<"File not found!"<<endl;
        file.close(); 
        return;
    }
    else
    {
        string rollnoToModify;
        cout<<"Enter Roll Number of the student to modify: ";
        cin>>rollnoToModify;
        file.open("studentRecord.txt", ios::in);
        file1.open("temp.txt", ios::app | ios::out);
        bool found = false;
        file>>name>>rollno>>course>>email>>phone>>address;
        while(!file.eof())
        {
            if(rollno == rollnoToModify)
            {
                found = true;
                cout<<"Enter new Name: ";cin>>name;
                cout<<"Enter new Course: ";cin>>course;
                cout<<"Enter new Email: ";cin>>email;
                cout<<"Enter new Phone: ";cin>>phone; 
                cout<<"Enter new Address: ";cin>>address;
            }
            file1<<name<<" "<<rollno<<" "<<course<<" "<<email<<" "<<phone<<" "<<address<<endl;
            file>>name>>rollno>>course>>email>>phone>>address;
        }
        if(!found)
        {
            cout<<"Student with Roll Number "<<rollnoToModify<<" not found!"<<endl;
        }
        file.close();
        file1.close();
        remove("studentRecord.txt");
        rename("temp.txt", "studentRecord.txt");
    }
}

void student::search()
{
    system("cls");
    fstream file;
    cout<<"-----------------------------------------\n";
    cout<<"|         SEARCH STUDENT RECORD          |\n";
    cout<<"-----------------------------------------\n";
    file.open("studentRecord.txt", ios::in);
    if(!file)
    {
        cout<<"File not found!"<<endl;
        file.close(); 
        return;
    }
    else
    {
        string rollnoToSearch;
        cout<<"Enter Roll Number of the student to search: ";
        cin>>rollnoToSearch;
        bool found = false;
        file>>name>>rollno>>course>>email>>phone>>address;
        while(!file.eof())
        {
            if(rollno == rollnoToSearch)
            {
                found = true;
                cout<<"\nName: "<<name<<endl;
                cout<<"Roll Number: "<<rollno<<endl;
                cout<<"Course: "<<course<<endl;
                cout<<"Email: "<<email<<endl;
                cout<<"Phone: "<<phone<<endl;
                cout<<"Address: "<<address<<endl;
                cout<<"-----------------------------------------\n";
            }
            file>>name>>rollno>>course>>email>>phone>>address;
        }
        if(!found)
        {
            cout<<"Student with Roll Number "<<rollnoToSearch<<" not found!"<<endl;
        }
        file.close();
    }
}

void student::deleteRecord()
{
    system("cls");
    fstream file, file1;
    cout<<"-----------------------------------------\n";
    cout<<"|         DELETE STUDENT RECORD          |\n";
    cout<<"-----------------------------------------\n";
    if(!file)
    {
        cout<<"File not found!"<<endl;
        file.close(); 
        return;
    }
    else
    {
        string rollnoToDelete;
        cout<<"Enter Roll Number of the student to delete: ";
        cin>>rollnoToDelete;
        file.open("studentRecord.txt", ios::in);
        file1.open("temp.txt", ios::app | ios::out);
        bool found = false;
        file>>name>>rollno>>course>>email>>phone>>address;
        while(!file.eof())
        {
            if(rollno == rollnoToDelete)
            {
                found = true;
                cout<<"Student with Roll Number "<<rollnoToDelete<<" deleted successfully!"<<endl;
            }
            else
            {
                file1<<name<<" "<<rollno<<" "<<course<<" "<<email<<" "<<phone<<" "<<address<<endl;
            }
            file>>name>>rollno>>course>>email>>phone>>address;
        }
        if(!found)
        {
            cout<<"Student with Roll Number "<<rollnoToDelete<<" not found!"<<endl;
        }
        file.close();
        file1.close();
        remove("studentRecord.txt");
        rename("temp.txt", "studentRecord.txt");
    }
}

int main()
{
    student s;
    s.menu();
    return 0;
}