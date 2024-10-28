#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <stdio.h>
#include <fstream>
#include "home_page.h"
#include "admin.h"
#include "user.h"
#include <stdlib.h>
#include "beverages.h";
using namespace std;

int option = 0;
int input = 0;
const int colWidth2 = 15;
const int colWidth = 25;
const int numCols = 2;
double total = 0;//the total price of drink]
char choose = ' ';//yes or no
const int numCol = 50;

const int MAX_DRINKS = 100; // Maximum number of drinks in the cart
const int MAX_TEAS = 7;
const int MAX_SODAS = 4;
const int MAX_COFFEES = 5;

int drtea[MAX_DRINKS]; // record tea
int qtytea[MAX_DRINKS]; // record qty of tea
int drsoda[MAX_DRINKS]; // record soda
int qtysoda[MAX_DRINKS]; // record qty of soda
int drcoffee[MAX_DRINKS]; // record coffee
int qtycoffee[MAX_DRINKS]; // record qty of coffee

int teaCount = 0;
int sodaCount = 0;
int coffeeCount = 0;

int teaSize = 7;
int coffeeSize = 5;
int sodaSize = 4;

string nameTea[MAX_TEAS + 1] = { "", "Green Tea", "Earl Grey", "Jasmine", "Oolong", "Peppermint", "Royal English", "Pu-Erh" };
double priceTea[MAX_TEAS + 1] = { 0, 7.00, 3.00, 4.00, 8.00, 10.00, 9.00, 4.00 };

string nameSoda[MAX_SODAS + 1] = { "", "Strawberry", "Lychee", "Yuzu", "Melon" };
double priceSoda[MAX_SODAS + 1] = { 0, 11.00, 11.00, 12.00, 10.00 };

string nameCoffee[MAX_COFFEES + 1] = { "", "Latte", "Cappuccino", "Mocha", "Americano", "Espresso" };
double priceCoffee[MAX_COFFEES + 1] = { 0, 10.90, 10.90, 11.90, 9.90, 8.90 };


void cart();
void cart_result();
void tea();
void coffee();
void soda();
void update_drink();
void place_order();
void receipt();
void printLine2(int);

void printLine2(int width) {
    cout << '+' << string(width, '-') << '+' << endl;
}

    void tea() {
        system("cls");
        logo();
        cout << "\n";
        printLine(colWidth, numCols);

        cout << '|' << left << setw(6) << "No" << '|' << setw(colWidth2) << "Name" << '|' << setw(colWidth) << "Price(RM)" << '|' << endl;

        printLine(colWidth, numCols);
        for (int i = 1; i <= 7; i++) {

            cout << '|' << left << setw(6) << i << '|' << setw(colWidth2) << nameTea[i] << '|' << setw(colWidth) <<fixed << setprecision(2)<< priceTea[i] << '|' << endl;
        }

        printLine(colWidth, numCols);

        //calculate the total of the drink
        cout << "Enter the number drink you want (Enter 0 back to last page) : ";
        while (true) {
            if (cin >> option) {
                if (cin.peek() == '\n' && option >= 0 && option <= MAX_TEAS) {
                    if (option == 0) {
                        menu();
                    }
                    else if (option >= 1 && option <= MAX_TEAS) {
                        if (teaCount < MAX_DRINKS) {
                            drtea[teaCount] = option;
                            cout << "Enter the quantity of drink: ";
                            cin >> input;
                            qtytea[teaCount] = input;
                            teaCount++;
                            total += input * priceTea[option];
                            place_order();
                        }
                        else {
                            cout << "Cart is full.\n";
                        }
                    }
                    else if (option < 0 || option > MAX_TEAS) {
                        cout << "Invalid input. Please re-enter :  ";
                    }
                }
                else cout << "Invalid input. Please re-enter :  ";
            }

            else {
                cout << "Invalid input. Please re-enter :  ";
            }
        }

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }


void soda() {
    system("cls");
    logo();
    cout << "\n";
    printLine(colWidth, numCols);

    cout << '|' << left << setw(6) << "No" << '|' << setw(colWidth2) << "Name" << '|' << setw(colWidth) << "Price(RM)" << '|' << endl;

    printLine(colWidth, numCols);
    for (int i = 1; i <= 4; i++) {

        cout << '|' << left << setw(6) << i << '|' << setw(colWidth2) << nameSoda[i] << '|' << setw(colWidth) <<fixed << setprecision(2)<< priceSoda[i] << '|' << endl;
    }

    printLine(colWidth, numCols);

    //calculate the total of the drink

    cout << "Enter the number drink you want (Enter 0 back to last page): ";
    while (true) {
        if (cin >> option) {
            if (cin.peek() == '\n' && option >= 0 && option <= MAX_SODAS) {
                if (option == 0) {
                    menu();
                }
                else if (option >= 1 && option <= MAX_SODAS) {
                    if (sodaCount < MAX_DRINKS) {
                        drsoda[sodaCount] = option;
                        cout << "Enter the quantity of drink: ";
                        cin >> input;
                        qtysoda[sodaCount] = input;
                        sodaCount++;
                        total += input * priceSoda[option];
                        place_order();
                    }
                    else {
                        cout << "Cart is full.\n";
                    }
                }
                else if (option < 0 || option > MAX_SODAS) {
                    cout << "Invalid input. Please re-enter :  ";
                }
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

void coffee() {
    system("cls");
    logo();
    cout << "\n";
    printLine(colWidth, numCols);

    cout << '|' << left << setw(6) << "No" << '|' << setw(colWidth2) << "Name" << '|' << setw(colWidth) << "Price(RM)" << '|' << endl;

    printLine(colWidth, numCols);
    for (int i = 1; i <= 5; i++) {

        cout << '|' << left << setw(6) << i << '|' << setw(colWidth2) << nameCoffee[i] << '|' << setw(colWidth) << fixed << setprecision(2) << priceCoffee[i] << '|' << endl;
    }

    printLine(colWidth, numCols);

    //calculate the total of the drink
    cout << "Enter the number drink you want (Enter 0 back to last page): ";
    while (true) {
        if (cin >> option) {
            if (cin.peek() == '\n' && option >= 0 && option <= MAX_COFFEES) {
                if (option == 0) {
                    menu();
                }
                else if (option == 1 && option <= MAX_COFFEES) {
                    if (coffeeCount < MAX_DRINKS) {
                        drcoffee[coffeeCount] = option;
                        cout << "Enter the quantity of drink: ";
                        cin >> input;
                        qtycoffee[coffeeCount] = input;
                        coffeeCount++;
                        total += input * priceCoffee[option];
                        place_order();
                    }
                    else {
                        cout << "Cart is full.\n";
                    }
                    break;
                }
                else if (option < 0 || option > MAX_COFFEES) {
                    cout << "Invalid input. Please re-enter :  ";
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

void cart_result() {
    for (int i = 0; i < teaCount; ++i) {
        cout << '|' << left << setw(6) << i + 1 << '|' << setw(20) << nameTea[drtea[i]] << '|' << setw(12) << qtytea[i] << '|' << setw(20) << priceTea[drtea[i]] << '|' << setw(20) << qtytea[i] * priceTea[drtea[i]]  << '|' << endl;
    }

    for (int i = 0; i < sodaCount; ++i) {
        cout << '|' << left << setw(6) << i + 1 + teaCount << '|' << setw(20) << nameSoda[drsoda[i]] << '|' << setw(12) << qtysoda[i] << '|' << setw(20) << priceSoda[drsoda[i]] << '|' << setw(20) << qtysoda[i] * priceSoda[drsoda[i]] << '|' << endl;
    }

    for (int i = 0; i < coffeeCount; ++i) {
        cout << '|' << left << setw(6) << i + 1 + teaCount + sodaCount << '|' << setw(20) << nameCoffee[drcoffee[i]] << '|' << setw(12) << qtycoffee[i] << '|' << setw(20) << priceCoffee[drcoffee[i]] << '|' << setw(20) << qtycoffee[i] * priceCoffee[drcoffee[i]] << '|' << endl;
    }
}

void place_order() {
    cout << "\nYou wanna order more drink (Y/N) : ";//choose wanna order more or no
    while (true) {
        cin >> choose;

        if (choose == 'y' || choose == 'Y') {
            menu();
            break;
        }
        else if (choose == 'n' || choose == 'N') {
            cout << "PLACE ORDER (Y/N) : ";
            while (true) {
                cin >> choose;
                if (choose == 'Y' || choose == 'y') {
                    cart();
                }
                else if (choose == ' N' || choose == 'n') {
                    menu();
                    break;
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

void update_drink() {
    int option = 0;
    int price = 0;
    system("cls");
    logo();
    while (true) {
        cout << "\n1.Tea\n";
        cout << "2.Soda\n";
        cout << "3.Coffee\n";
        cout << "4.Exit\n";
        cout << "Which type of drink want to update price (Enter 0 back to last page) : ";
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
            system("cls");
            logo();
            cout << "\n";
            printLine(colWidth, numCols);

            cout << setfill(' ') << '|' << left << setw(6) << "No" << '|' << setw(colWidth2) << "Name" << '|' << setw(colWidth) << "Price(RM)" << '|' << endl;

            printLine(colWidth, numCols);
            for (int i = 1; i <= 7; i++) {

                cout << '|' << left << setw(6) << i << '|' << setw(colWidth2) << nameTea[i] << '|' << setw(colWidth) << fixed << setprecision(2) << priceTea[i] << '|' << endl;
            }

            printLine(colWidth, numCols);

            //calculate the total of the drink
            while (true) {
                cout << "Enter the number drink you want to change (Enter 0 back to last page): ";
                while (true) {
                    if (cin >> option) {
                        if (cin.peek() == '\n' && option >= 0 && option <= MAX_TEAS) {
                            if (option == 0) {
                                update_drink();
                            }
                            else if (option >= 1 && option <= MAX_TEAS) {
                                cout << "Enter the price : ";
                                cin >> price;
                                priceTea[option] = price;
                                cout << "\nNew price already been record";
                                cin.ignore();
                                cin.get();
                                system("cls");
                                continues_staff();
                            }
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
            break;
        case 2:
            system("cls");
            logo();
            cout << "\n";
            printLine(colWidth, numCols);

            cout << setfill(' ') << '|' << left << setw(6) << "No" << '|' << setw(colWidth2) << "Name" << '|' << setw(colWidth) << "Price(RM)" << '|' << endl;

            printLine(colWidth, numCols);
            for (int i = 1; i <= 4; i++) {

                cout << '|' << left << setw(6) << i << '|' << setw(colWidth2) << nameSoda[i] << '|' << setw(colWidth) << fixed << setprecision(2)<< priceSoda[i] << '|' << endl;
            }

            printLine(colWidth, numCols);

            //calculate the total of the drink

            cout << "Enter the number drink you want to change (Enter 0 back to last page) : ";
            while (true) {
                if (cin >> option) {
                    if (cin.peek() == '\n' && option >= 0 && option <= MAX_SODAS) {
                        if (option == 0) {
                            update_drink();
                        }
                        else if (option >= 1 && option <= MAX_SODAS) {
                            cout << "Enter the price : ";
                            cin >> price;
                            priceSoda[option] = price;
                            cout << "\nNew price already been record";
                            cin.ignore();
                            cin.get();
                            system("cls");
                            continues_staff();
                        }
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
            break;
        case 3:
            system("cls");
            logo();
            cout << "\n";
            printLine(colWidth, numCols);

            cout << '|' << left << setw(6) << "No" << '|' << setw(colWidth2) << "Name" << '|' << setw(colWidth) << "Price(RM)" << '|' << endl;

            printLine(colWidth, numCols);
            for (int i = 1; i <= 5; i++) {

                cout << '|' << left << setw(6) << i << '|' << setw(colWidth2) << nameCoffee[i] << '|' << setw(colWidth) << fixed << setprecision(2) << priceCoffee[i] << '|' << endl;
            }

            printLine(colWidth, numCols);

            //calculate the total of the drink
            cout << "Enter the number drink you want (Enter 0 back to last page) : ";
            while (true) {
                if (cin >> option) {
                    if (cin.peek() == '\n' && option >= 0 && option <= MAX_COFFEES) {
                        if (option == 0) {
                            update_drink();
                        }
                        else if (option >= 1 && option <= MAX_COFFEES) {
                            cout << "Enter the price : ";
                            cin >> price;
                            priceCoffee[option] = price;
                            cout << "\nNew price already been record";
                            cin.ignore();
                            cin.get();
                            system("cls");
                            continues_staff();
                        }
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
                break;
            }
        case 4:
            exit();
            break;
        }
    }
}

void cart() {
    system("cls");
    if (sodaCount == 0 && teaCount == 0 && coffeeCount == 0) {
        logo();
        cout << "\n" << "Your cart is empty " << "\n";
        cout << "Continues? (Y/N) : ";
        cin >> choose;
        while (true) {
            if (choose == 'Y' || choose == 'y') {
                user_home();
            }
            else if (choose == 'N' || choose == 'n') {
                exit();
                return;
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
    logo();
    cout << "\n";
    printLine2(82);
    cout << '|' << left << setw(6) << "No" << '|' << setw(20) << "Name" << '|' << setw(12) << "Quantity" << '|' << setw(20) << "Price (RM)" << '|' << setw(20) << "Total Price (RM)" << '|' << endl;
    printLine2(82);
    cart_result();
    printLine2(82);
    cout << '|' << setw(6) << "" << '|' << setw(20) << "" << '|' << setw(12) << "" << '|' << setw(20) << "" << '|' << setw(20) << fixed << setprecision(2) << total << '|' << endl;
    printLine2(82);
    cout << " Confirmed Order? (Y/N) : ";
    while (true) {
        cin >> choose;
        if (choose == 'y' || choose == 'Y') {
            receipt();
        }
        else if (choose == 'n' || choose == 'N') {
            menu();
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

void receipt() {
    string payment;
    double cash = 0;
    double src = total * 0.10;
    double tax = total * 0.06;
    double total_2 = total * 1.16;
    cout << "\nCash,Credit Card or TNG(C,D,T) : ";
    while (true) {
        cin >> choose;
        if (choose == 'c' || choose == 'C') {
            payment = "Cash";
            cout << "Please Enter Your Pay Amount : ";
            cin >> cash;

            system("cls");
            logo();
            cout << "\n";
            printLine2(82);
            cart_result();
            printLine2(82);
            cout << '|' << setw(6) << "" << '|' << setw(20) << "" << '|' << setw(12) << "" << '|' << setw(20) << "" << '|' << setw(20) << fixed << setprecision(2) << total << '|' << endl;
            printLine2(82);
            cout << "\n" << "Payment Method      : " << payment << "\n";
            cout << "Service Charge(10%) : " << setprecision(2) << fixed << src << "\n";
            cout << "Tax (6%)            : " << setprecision(2) << fixed << tax << "\n";
            cout << "Total Payable       : " << setprecision(2) << fixed << total_2 << "\n";
            cout << "\nYour Pay Amount     : " << setprecision(2) << fixed << cash << "\n";
            cout << "Change              : " << setprecision(2) << fixed << cash - total_2;
        }
        else if (choose == 'D' || choose == 'd') {
            payment = "Credit Card";
            system("cls");
            logo();
            cout << "\n";
            printLine2(82);
            cart_result();
            printLine2(82);
            cout << '|' << setw(6) << "" << '|' << setw(20) << "" << '|' << setw(12) << "" << '|' << setw(20) << "" << '|' << setw(20) << fixed << setprecision(2) << total << '|' << endl;
            printLine2(82);
            cout << "\n" << "Payment Method      : " << payment << "\n";
            cout << "Service Charge(10%) : " << setprecision(2) << fixed << src << "\n";
            cout << "Tax (6%)            : " << setprecision(2) << fixed << tax << "\n";
            cout << "Total Payable       : " << setprecision(2) << fixed << total_2 ;
        }
        else if (choose == 't' || choose == 'T') {
            payment = "Tng";
            system("cls");
            logo();
            cout << "\n";
            printLine2(82);
            cart_result();
            printLine2(82);
            cout << '|' << setw(6) << "" << '|' << setw(20) << "" << '|' << setw(12) << "" << '|' << setw(20) << "" << '|' << setw(20) << fixed << setprecision(2) << total << '|' << endl;
            printLine2(82);
            cout << "\n" << "Payment Method      : " << payment << "\n";
            cout << "Service Charge(10%) : " << setprecision(2) << fixed << src << "\n";
            cout << "Tax (6%)            : " << setprecision(2) << fixed << tax << "\n";
            cout << "Total Payable       : " << setprecision(2) << fixed << total_2 ;
        }
        else if (isdigit(choose)) {
            cout << "\nNumbers are not allowed. Please re-enter : ";
        }
        else {
            cout << "\nInvalid enter. Please re-enter : ";
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore();
    cin.get();
    exit();
    return;
}

