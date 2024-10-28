#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <stdio.h>
#include <fstream>
#include "user.h"
#include <stdlib.h>
#include "home_page.h"
#include "beverages.h"
using namespace std;

void staff_login();
void staff_function();
void update_drink();
void report();
void DisplayreportD();
void DisplayreportM();
void summary();
void continues_staff();


void staff_function() {
    system("cls");
    int option = 0;
    while (true) {
        logo();
        cout << " \n1. Generate the report\n";
        cout << "2. Update the drink's price\n";
        cout << "3. Exit\n";
        cout << "Please enter your option : ";
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
            report();
            break;
        case 2:
            update_drink();
            break;
        case 3:
            exit();
            return;
            break;
        }
    }
}

void staff_login() {
    system("cls");
    logo();
    string empty;
    int attempt = 0;
    string inID;
    string inPassword;
    const string staffid = "S001";
    const string staffPassword = "staff123";
    cout << "\n";
    getline(cin, empty);
    cout << "Please Enter your Staff ID :";
    getline(cin,inID);
    cout << "\nPlease Enter your Staff Password :";
    getline(cin,inPassword);

    while (true) {
        if (inPassword == staffPassword && inID == staffid)
        {
            cout << "\nAccess granted." << endl;
            cout << "\n";
            staff_function();
        }
        else {
            attempt++;
            if (attempt == 3) {
                cout << "\nYou already cannot login system ";
                cin.ignore();
                cin.get();
                login_system();
                return;
            }
            else
                cout << "\nAccess denied.";
            cout << "\nAttempt left : " << 3 - attempt;
            cout << "\n\nPlease re-enter ID :";
            getline(cin, inID); 
            cout << "Please re-enter Password :";
            getline(cin, inPassword);
        }
    }
}

void report() {
    system("cls");
    int option;
    while (true) {
        logo();
        cout << "\n1. Daily Report\n";
        cout << "2. Monthly Report\n";
        cout << "3. Summary Report\n";
        cout << "4. Exit\n";
        cout << "Enter The Option (Enter 0 Return To Last Page) : ";
        while (true) {
            if (cin >> option) {
                if (cin.peek() == '\n' && option >= 0 && option <= 4) {
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
        case 0:
            staff_function();
            break;
        case 1:
            DisplayreportD();
            cin.ignore();
            cin.get();
            system("cls");
            continues_staff();
            break;
        case 2:
            DisplayreportM(); 
            cin.ignore();
            cin.get();
            system("cls");
            continues_staff();
            break;
        case 3:
            summary();
            cin.ignore();
            cin.get();
            system("cls");
            continues_staff();
            break;
        case 4:
            exit();
            return;
            break;
        }
    }
}

void DisplayreportD() {
    system("cls");
    cout << "======================================\n";
    cout << "|   DAILY REPORT OF YUKIS CAFE       |\n";
    cout << "|><><><><><><><><><><><><><><><><><><|\n";
    cout << "|Drinks Name|               |Quantity|\n";
    cout << "|><><><><><><><><><><><><><><><><><><|\n";
    cout << "|1.Green Tea                       13|\n";
    cout << "|2.Strawberry                       7|\n";
    cout << "|3.Oolong                           6|\n";
    cout << "|4.Melon                           10|\n";
    cout << "|5.Americano                        9|\n";
    cout << "|6.Cappuccino                       8|\n";
    cout << "|7.Lychee                          15|\n";
    cout << "======================================\n";
}
void DisplayreportM() {
    system("cls");
    cout << "======================================\n";
    cout << "|   MONTH REPORT OF YUKIS CAFE       |\n";
    cout << "|><><><><><><><><><><><><><><><><><><|\n";
    cout << "|Drinks Name|               |Quantity|\n";
    cout << "|><><><><><><><><><><><><><><><><><><|\n";
    cout << "|1.Green Tea                       75|\n";
    cout << "|2.Earl Grey                       36|\n";
    cout << "|3.Jasmine                         48|\n";
    cout << "|4.Oolong                          65|\n";
    cout << "|5.Pepeprmin                       50|\n";
    cout << "|6.Royal English                   44|\n";
    cout << "|7.Pu-erh                          36|\n";
    cout << "|8.Strawberry                      72|\n";
    cout << "|9.Lychee                          88|\n";
    cout << "|10.Yuzu                           47|\n";
    cout << "|11.Melon                          61|\n";
    cout << "|12.Latte                          53|\n";
    cout << "|13.Cappuccino                     76|\n";
    cout << "|14.Mocha                          53|\n";
    cout << "|15.Americano                      57|\n";
    cout << "|16.Espresso                       42|\n";
    cout << "======================================\n";
}
void summary() {
    system("cls");
    cout << "======================================================\n";
    cout << "|           SUMMARY REPORTS OF YUKI'S CAFE           |\n";
    cout << "|><><><><><><><><><><><><><><><><><><><><><><><><><><|\n";
    cout << "|Top 5 Drink ordered :                       QUANTITY|\n";
    cout << "|Lychee                                          1043|\n";
    cout << "|Cappuccino                                       943|\n";
    cout << "|Green Tea                                        902|\n";
    cout << "|Strawberry                                       821|\n";
    cout << "|Oolong                                           793|\n";
    cout << "|><><><><><><><><><><><><><><><><><><><><><><><><><><|\n";
    cout << "|Total amount of ordered drinks throughout the year :|\n";
    cout << "|                       15784                        |\n";
    cout << "|><><><><><><><><><><><><><><><><><><><><><><><><><><|\n";
    cout << "|   Total amount of profit throughout the year(RM):  |\n";
    cout << "|                       715784                       |\n";
    cout << "======================================================\n";
}


void continues_staff() {
    char choose = ' ';
    cout << "Continues (Y/N) : ";
    while (true) {
        cin >> choose;

        if (choose == 'y' || choose == 'Y') {
            staff_function();
            break;
        }
        else if (choose == 'n' || choose == 'N') {
            exit();
            return;
        }
        else if (isdigit(choose)) {
            cout << "\nNumbers are not allowed. Please enter 'y' or 'n'.";
        }
        else {
            cout << "\nInvalid choice. Please enter 'y' or 'n'.";
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}