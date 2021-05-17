// including header files
#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;

//global variables
string fname,lname,phone_num;

// Functions
void addContact();
void searchContact();
void help();
void self_exit();
bool check_digits(string);
bool check_numbers(string);

int main()
{
    short int choice;
    system("cls");
    system("color 0A");
    cout << "\n\n\n\t\t\t\t\t\t\t\t\t\tWelcome to Contact Manager by C0ders";
    cout << "\n\n\t\t\t\t\t\t\t\t\t\t1. Add Contact\n\t\t\t\t\t\t\t\t\t\t2. Search Contact\n\t\t\t\t\t\t\t\t\t\t3. Help\n\t\t\t\t\t\t\t\t\t\t4. Exit\n\t\t\t\t\t\t\t\t\t\t--> ";
    cin >> choice;

    switch(choice)
    {
        case 1:
            addContact();
            break;
        case 2:
            searchContact();
            break;
        case 3:
            help();
            break;
        case 4:
            self_exit();
            break;
        default:
            cout << "\n\n\tInvalid Input !";
            cout << "\n\tPress Any Key To Continue..";
            getch();
            main();
    }
    return 0;
}

void self_exit()
{
    system("cls");
    cout << "\n\n\n\t\tThank you for using our App, we hope you have a great day. :)";
    exit(1);
}

void help()
{
    int ans;
    cout << "\nFor any kind of feedback or reporting our bug, please reach our instagram : @c0ders or our YT channel c0ders" << endl;
    cout << "\n\n Do you want to go back to the menu" << endl;
}

void addContact()
{
    ofstream phone("number.txt", ios::app);
    system("cls");
    cout << "\n\n\tFirst Name : ";
    cin >> fname;
    cout << "\n\tLast Name : ";
    cin >> lname;
    cout << "\n\t10-Digit Phone Number : ";
    cin >> phone_num;

    if(check_digits(phone_num) == true)
    {
        if(check_numbers(phone_num) == true)
        {
            if(phone.is_open())
            {
                char ans;
                phone << fname << " " << lname << " " << phone_num << endl;
                cout << "\n\tContact Saved Successfully !" << endl;
                cout << " Do you want to go the main menu : [Y/N]"<< endl;
                cin >> ans;
                if (ans == 'Y'){
                    main();
                }
                else if(ans == 'N'){
                    cout <<"OK " << endl;
                    self_exit();
                }
                else{
                    cout << "Please enter proper value" << endl;
                }
            }
            else
            {
                cout << "\n\tError Opening File !";
            }
        }
        else
        {
            cout << "\n\tA Phone Number Must Contain Numbers Only !";
        }
    }
    else
    {
        cout << "\n\tA Phone Number Must COntain 10 Digits.";
    }
    phone.close();
}

void searchContact()
{
    bool found = false;
    ifstream myfile("number.txt");
    string keyword;
    cout << "\n\t\t\t\t\t\t\t\t\t\t\tEnter Name To Search : ";
    cin >> keyword;
    while(myfile >> fname >> lname >> phone_num)
    {
        if(keyword == fname || keyword == lname)
        {
            system("cls");
            cout << "\n\t\t\t\t\t\t\t\t\t\t\tContact details..";
            cout << "\n\t\t\t\t\t\t\t\t\t\t\tFirst Name : " << fname;
            cout << "\n\t\t\t\t\t\t\t\t\t\t\tLast Name : " << lname;
            cout << "\n\t\t\t\t\t\t\t\t\t\t\tPhone Number : " << phone_num;
            found = true;
            break;
        }
    }
    if(found == false)
    cout << "\n\tNo Such Contact Found";
}

bool check_digits(string x)
{
    if(x.length() == 10)
    return true;
    else
    return false;
}

bool check_numbers(string x)
{
    bool check = true;

    for(int i=0; i < x.length(); i++)
    {
        if(!(int(x[i]) >= 48 && int(x[i]) <= 57))
        {
            check = false;
            break;
        }
    }

    if(check == true)
    return true;
    if(check == false)
    return false;
}