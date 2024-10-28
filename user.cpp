//ordering beverages
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <stdio.h>
#include <fstream>
#include "home_page.h"
#include "admin.h"
#include <stdlib.h>
#include "beverages.h";
using namespace std;
//variables
const int colWidth2 = 15;
const int colWidth = 25;
const int numCols = 2;
const int numCol = 50;

int attempt = 0;

//storage drink and price

//function
void printLine(int colWidth, int numCols);
void user_home();
void menu();
void rg();
void login();
void user_login();


//table's line
void printLine(int colWidth, int numCols) {
    for (int i = 0; i < numCols; ++i) {
        cout << string(colWidth, '-');
    }
    cout << endl;
}

void user_login() {
    char choose = ' ';
    system("cls");
    cout << "New user? Register (Y/N): ";
    while (true) {
        cin >> choose;

        if (choose == 'y' || choose == 'Y') {
            rg();
            break;
        }
        else if (choose == 'n' || choose == 'N') {
            login();
            break;
        }
        else if (isdigit(choose)) {
            cout << "\nNumbers are not allowed. Please enter 'y' or 'n' : ";
        }
        else {
            cout << "\nInvalid choice. Please enter 'y' or 'n' : ";
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}


void rg() {
    ofstream g("data.txt");
    if (!g.is_open()) {
        cout << "Could not open file\n";
        return;
    }

    string userid, userPassword;
    cout << "\n";
    getline(cin, userid);
    cout << "New Username: ";
    getline(cin, userid);
    userid.erase(remove_if(userid.begin(), userid.end(), ::isspace), userid.end());
    cout << "New Password: ";
    getline(cin, userPassword);
    userPassword.erase(remove_if(userPassword.begin(), userPassword.end(), ::isspace), userPassword.end());

    g << userid << '\n' << userPassword;
    g.close();
    cout << "Account created successfully.\nWelcome to yuki cafe , " << userid;
    user_home();
}

void login() {
    char choose = ' ';
    ifstream f("data.txt");
    if (!f.is_open()) {
        cout << "Could not open file\n";
        return;
    }

    string id, password;
    getline(f, id);
    getline(f, password);
    f.close();

    string inID, inPassword, empty;
    while (true) {
        cout << "\n";
        getline(cin, empty);
        cout << "Enter Username: ";
        getline(cin, inID);
        inID.erase(remove_if(inID.begin(), inID.end(), ::isspace), inID.end());
        cout << "Enter Password: ";
        getline(cin, inPassword);
        inPassword.erase(remove_if(inPassword.begin(), inPassword.end(), ::isspace), inPassword.end());

        if (inID == id && inPassword == password) {
            cout << "Login Successful\nWelcome, " << inID << endl;
            user_home();
            break;
        }
        else {
            attempt++;
            if (attempt == 3) {
                cout << "You already cannot login";
                cin.ignore();
                cin.get();
                system("cls");
                login_system();
                return;
            }
            else
                cout << "\nIncorrect username or password. Try again.\n";
            cout << "Attempt left :" << 3 - attempt << "\n";
            cout << "or want to register new member (Y/N) : ";
            while (true) {
                cin >> choose;

                if (choose == 'y' || choose == 'Y') {
                    rg();
                    break;
                }
                else if (choose == 'n' || choose == 'N') {
                    login();
                    break;
                }
                else if (isdigit(choose)) {
                    cout << "\nNumbers are not allowed. Please enter 'y' or 'n' : ";
                }
                else {
                    cout << "\nInvalid enter. Please enter 'y' or 'n' : ";
                }
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
    }
}

void user_home() {
    int option = 0;
    system("cls");
    logo();
    while (true) {
    cout <<"\n" << "1.MENU" << endl;
    cout << "2.CART" << endl;
    cout << "3.QUIT" << endl;
    cout << "ENTER YOUR OPTION = ";
    while (true) {
        if (cin >> option) {
            if (cin.peek() == '\n' && option >= 1 && option <= 3) {
                break;
            }
            else {
                cout << "Invalid input. Please re-enter :  ";
            }
        }
        else {
            cout << "Invalid input. Please re-enter :  ";
        }

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
        switch (option) {
        case 1:
            menu();
            break;
            
        case 2:
            cart();
            break;

        case 3:
            exit();
            return;
        }
    }
}

void menu() {
    int option = 0;
    system("cls");
    logo();
    while (true) {
        cout << "\n" << "MENU" << endl;
        cout << "1.TEA" << endl;
        cout << "2.SODA" << endl;
        cout << "3.COFFEE" << endl;
        cout << "Which drink will you like to choose (Enter 0 back to last page) : ";
        while (true) {
            if (cin >> option) {
                if (cin.peek() == '\n' && option >= 0 && option <= 3) {
                    switch (option) {
                    case 0:
                        user_home();
                        break;
                    case 1:
                        tea();
                        break;
                        //soda
                    case 2:
                        soda();
                        break;
                    case 3:
                        coffee();
                        break;
                    }
                    break;
                }
                else {
                    cout << "Invalid input. Please re-enter :  ";
                }
            }
            else {
                cout << "Invalid input. Please re-enter :  ";
            }

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}








