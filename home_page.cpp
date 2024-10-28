#include <iostream>
#include <iomanip>
#include "user.h"
#include "admin.h"
#include "beverages.h"
#include <stdlib.h>
#include <string>
using namespace std;

void displayMenu();
void login_system();
void logo();
void main();
void exit();

void logo() {
    cout << endl;
    cout << fixed;
    cout << left;
    cout << setfill(' ');

    cout << setw(6) << " __" << setw(5) << " __" << setw(4) << "__" << setw(3) << "  __" << setw(4) << "  __" << setw(5) << " __" << setw(4) << "__" << "\n";
    cout << setw(9) << " \\ \\  / / " << setw(2) << " | |  | |" << setw(5) << " | |/ /" << setw(5) << "  | |" << "\n";
    cout << setw(7) << "  \\ \\/ /" << setw(9) << "   | |  | |" << setw(5) << " | ' / " << setw(5) << "  | |" << "\n";
    cout << setw(6) << "   \\  /" << setw(11) << "    | |  | | " << setw(4) << "|  <" << setw(7) << "    | |" << "\n";
    cout << setw(5) << "   / /" << setw(11) << "     | |__| |" << setw(4) << " | |" << setw(3) << "\\ \\" << setw(5) << "  | |" << "\n";
    cout << setw(4) << "  /_/" << setw(12) << "      \\______/" << setw(4) << " |_|" << setw(5) << " \\_\\ " << setw(3) << "|_|" << "\n";
    cout << setw(6) << "\n";
}

void displayMenu() {
    logo();
    cout << "\n" << "______________________________" << endl;
    cout << left << setw(30) << setfill(' ') << "|Welcome to Yuki Cafe        |" << endl;
    cout << "|____________________________|" << endl;
    cout << left << setw(30) << setfill(' ') << "|1. User                     |" << endl;
    cout << left << setw(30) << setfill(' ') << "|2. Staff                    |" << endl;
    cout << left << setw(30) << setfill(' ') << "|3. Exit                     |" << endl;
    cout << '|' << left << setw(29) << setfill('_') <<right << '|' << "" << endl;
}
void login_system() {
    system("cls");
    int option = 0;
    while (true) {
    displayMenu();
    cout << "Enter your choice (1-3): ";
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
            user_login();
            break;
        case 2:
            staff_login();
            break;
        case 3:
            exit();
            break;
        }
    }
}

void exit() {
    system("cls");  
    cout << "===== My Appreciation For Dropping By This Humble Store Of Ours ======";
    cin.ignore();   
    cin.get();      
    system("cls");     
    login_system();
}

