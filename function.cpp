//ordering beverages
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <stdio.h>
#include <fstream>
using namespace std;
//variables
int option = 0;
const int colWidth2 = 15;
const int colWidth = 25;
const int numCols = 2;
int c = 0;//categories
double total = 0;//the total price of drink]
char choose = ' ';//yes or no
int drt = 0;//drink number for tea
int qty = 0;//quantity of drink
const int numCol = 50;
int numDrinks = 0;
int num = 0;
int fk = 0;
int attempt = 0;
string userid;
string enteredPassword;//password
string userPassword;
string correctPassword;
string inPassword;
string inID;
vector<int> drtea;//record tea
vector<int> qtytea;//record qty of tea
vector<int>drsoda;
vector<int>qtysoda;
vector<int>drcoffee;
vector<int>qtycoffee;

//storage drink and price
string nameTea[8] = { "","green tea", "earl grey", "jasmine", "oolong", "pepeprmint", "royal english", "pu-erh" };
int priceTea[8] = { 0,2,3,4,5,6,7,8 };
string nameSoda[5] = { "","Strawberry ","Lychee","yuzhu","melon" };
int priceSoda[5] = { 0,11,11,12,10 };
string nameCoffee[6] = { "","latte","cappccino","mocha","americano","espresso" };
double priceCoffee[6] = { 0,10.90,10.90,11.90,9.90,8.90 };

//function
void printLine(int colWidth, int numCols);
void home();
void menu();
void cart();
void cart_result();
void receipt();
void logo();
void rg();
void login();
void displayMenu();
void tea();
void coffee();
void soda();
void staff_function();
void staff_login();
void user_login();
void login_system();

//table's line
void printLine(int colWidth, int numCols) {
    for (int i = 0; i < numCols; ++i) {
        cout << string(colWidth, '-');
    }
    cout << endl;
}

void displayMenu() {
    cout << left << setw(30) << setfill('*') << "" << endl;
    cout << left << setw(30) << setfill(' ') << "*Welcome to Yuki Cafe*" << endl;
    cout << left << setw(30) << setfill('*') << "" << endl;
    cout << left << setw(30) << setfill(' ') << "* 1. User" << endl;
    cout << left << setw(30) << setfill(' ') << "* 2. Staff" << endl;
    cout << left << setw(30) << setfill(' ') << "* 3. Exit" << endl;
    cout << left << setw(30) << setfill('*') << "" << endl;
}

void rg() {
    ofstream g("data.txt");
    if (!g.is_open()) {
        cout << "Could not open file\n";
        return;
    }

    string userid, userPassword;
    cout << "";
    getline(cin, userid);
    cout << "New Username: ";
    getline(cin, userid);
    userid.erase(remove_if(userid.begin(), userid.end(), ::isspace), userid.end());
    cout << "New Password: ";
    getline(cin, userPassword);
    userPassword.erase(remove_if(userPassword.begin(), userPassword.end(), ::isspace), userPassword.end());

    g << userid << '\n' << userPassword;
    g.close();
    cout << "Account created successfully.\n";
    home();
}

void login() {
    ifstream f("data.txt");
    if (!f.is_open()) {
        cout << "Could not open file\n";
        return;
    }

    string id, password;
    getline(f, id);
    getline(f, password);
    f.close();

    string inID, inPassword;
    while (true) {
        cout << "";
        getline(cin, userid);
        cout << "Enter Username: ";
        getline(cin, inID);
        inID.erase(remove_if(inID.begin(), inID.end(), ::isspace), inID.end());
        cout << "Enter Password: ";
        getline(cin, inPassword);
        inPassword.erase(remove_if(inPassword.begin(), inPassword.end(), ::isspace), inPassword.end());

        if (inID == id && inPassword == password) {
            cout << "Login Successful\nWelcome, " << inID << endl;
            break;
        }
        else {
            attempt++;
            if (attempt == 3) {
                cout << "You already cannot login\n\n";
                exit(0);
            }
            else
            cout << "Incorrect username or password. Try again.\n";
            cout << "Attempt left :" << 3 - attempt << "\n";
            cout << "or want to register new member (Y/N) : ";
            cin >> choose;
            while (true) {
                if (choose == 'Y' || choose == 'y') {
                    cout << "\n";
                    rg();
                }
                else if (choose == 'N' || choose == 'n') {
                    cout << "\n";
                    login();
                }
                else cout << "\nplease re-enter : ";
                cin >> choose;
            }
        }
    }
}

void cart_result() {

    for (size_t i = 0; i < drtea.size(); ++i) {
        cout << '|' << left << setw(6) << i + 1 << '|' << setw(colWidth2) << nameTea[drtea[i]] << '|' << setw(colWidth) << qtytea[i] << '|' << setw(colWidth2) << priceTea[drtea[i]] << '|' << setw(colWidth2) << qtytea[i] * priceTea[drtea[i]] << endl;
        total += qtytea[i] * priceTea[drtea[i]];
    }

    for (size_t i = 0; i < drsoda.size(); ++i) {
        cout << '|' << left << setw(6) << i + 1 + drtea.size() << '|' << setw(colWidth2) << nameSoda[drsoda[i]] << '|' << setw(colWidth) << qtysoda[i] << '|' << setw(colWidth2) << priceSoda[drsoda[i]] << '|' << setw(colWidth2) << qtysoda[i] * priceSoda[drsoda[i]] << endl;
        total += qtysoda[i] * priceSoda[drsoda[i]];
    }

    for (size_t i = 0; i < drcoffee.size(); ++i) {
        cout << '|' << left << setw(6) << i + 1 + drtea.size() + drsoda.size() << '|' << setw(colWidth2) << nameCoffee[drcoffee[i]] << '|' << setw(colWidth) << qtycoffee[i] << '|' << setw(colWidth2) << priceCoffee[drcoffee[i]] << '|' << setw(colWidth2) << qtycoffee[i] * priceCoffee[drcoffee[i]] << endl;
        total += qtycoffee[i] * priceCoffee[drcoffee[i]];
    }
}

void cart() {
    printLine(44, numCols);
    cout << '|' << left << setw(6) << "No" << '|' << setw(colWidth2) << "Name" << '|' << setw(colWidth) << "quantity" << setw(30) << '|' << "Price(RM)" << setw(20) << '|' << endl;
    printLine(44, numCols);
    cart_result();
    printLine(44, numCols);
    cout << setw(50) << '|' << fixed << setprecision(2) << setw(40) << total << '|' << endl;
    cout << "wanna place order (Y/N)";
    cin >> choose;
    while (true) {
        if (choose == 'Y' || choose == 'y') {
            if (drsoda.empty() && drtea.empty() && drcoffee.empty()) {
                cout << "your cart is empty " << "\n";
                cout << "you wanna continue using yuki menu (Y/N) : ";
                cin >> choose;
                while (true) {
                    if (choose == 'Y' || choose == 'y') {
                        home();
                    }
                    else if (choose == 'N' || choose == 'n') {
                        cout << "Thank for using yuki menu ";
                        exit(0);
                    }
                    else cout << "INVALID ENTER" << "\n";
                    cout << "please re-enter : ";
                    cin >> choose;
                }
            }
            else
                receipt();
        }
        else if (choose == 'N' || choose == 'n') {
            menu();
        }
        else cout << "INVALID ENTER.please re-enter : " << endl;
        cin >> choose;
    }
}

void logo() {
    cout << endl;
    cout << fixed;
    cout << right;
    cout << setfill(' ');
    cout << setw(53) << "__" << setw(5) << "__" << setw(5) << "__" << setw(3) << "__" << setw(4) << "__" << setw(4.5) << "__" << setw(4) << "__" << "\n";
    cout << setw(60) << "\\ \\  / / " << setw(2) << "| | | |" << setw(5) << " | |/ /" << setw(5) << "| |" << "\n";
    cout << setw(58) << "\\ \\/ /" << setw(9) << "| | | |" << setw(5) << " | ' / " << setw(5) << "| |" << "\n";
    cout << setw(57) << "\\  /" << setw(11) << "| | | | " << setw(4) << "|  <" << setw(7) << "| |" << "\n";
    cout << setw(56) << "/ /" << setw(11) << "| |_| |" << setw(4) << "| |" << setw(3) << "\\ \\" << setw(5) << "| |" << "\n";
    cout << setw(55) << "/_/" << setw(12) << "  \\_____/" << setw(4) << "|_|" << setw(5) << "\\_\\ " << setw(3) << "|_|" << "\n";
    cout << setw(60) << "\n";
}

void home() {
    logo();
    cout << "Welcome to YUKI cafe" << endl;
    cout << "Our YUKI cafe is make at" << endl;//introduction to the cafe
    cout << "----------------------------------------------------------------------------------------------------------------" << endl;
    cout << "1.MENU" << endl;
    cout << "2.CART" << endl;
    cout << "3.QUIT" << endl;
    cout << "ENTER YOUR OPTION = ";
    cin >> option;
    while (true) {
        switch (option) {
        case 1:
            menu();
            break;
            
        case 2:
            cart();
            break;

        case 3:
            cout << "THANK FOR USING YUKI MENU";
            exit(0);

        default:
            cout << "please re-enter the option : ";
            cin >> option;
        }
    }
}

void menu() {
    logo();
    cout << "----------------------------------------------------------------------------------------------------------------" << endl;
    cout << "MENU" << endl;
    cout << "1.TEA" << endl;
    cout << "2.SODA" << endl;
    cout << "3.COFFEE" << endl;
    cout << "Which drink will you like to choose : ";
    cin >> c;
    if (c == 0) {// enter 0 bring you back to home
        home();
    }
    //tea
    else 
        while (true) {
            switch (c) {
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
            default:
                cout << "invalid enter.please re-enter :";
                cin >> c;
                break;
            }
        }
}

void tea() {
    printLine(colWidth, numCols);

    cout << '|' << left << setw(6) << "No" << '|' << setw(colWidth2) << "Name" << '|' << setw(colWidth) << "Price(RM)" << '|' << endl;

    printLine(colWidth, numCols);
    for (int i = 1; i <= 7; i++) {

        cout << '|' << left << setw(6) << i << '|' << setw(colWidth2) << nameTea[i] << '|' << setw(colWidth) << priceTea[i] << '|' << endl;
    }

    printLine(colWidth, numCols);

    //calculate the total of the drink
    cout << "Enter the number drink you want : ";
    cin >> drt;
    if (drt == 0) {
        menu();
    }
    else if (drt >= 1 && drt <= 7) {
        drtea.push_back(drt);
        cout << "Enter the quantity of drink : ";
        cin >> qty;
        qtytea.push_back(qty);
    }
    else {
        cout << "INVALID NUMBER,PLEASE ENTER THE VALID NUMBER";

    }
    cout << endl;
    cout << "You wanna order more drink (Y/N) : ";//choose wanna order more or no
    cin >> choose;
    if (choose == 'Y' || choose == 'y') {//if yes this function will bring you back to menu
        menu();
    }
    else if (choose == 'N' || choose == 'n') {
        cout << "PLACE ORDER (Y/N) : ";
        cin >> choose;
        if (choose == 'Y' || choose == 'y') {
            cart();
        }
        else if (choose == ' N' || choose == 'n') {
            home();
        }
    }
}

void soda() {
    printLine(colWidth, numCols);

    cout << '|' << left << setw(6) << "No" << '|' << setw(colWidth2) << "Name" << '|' << setw(colWidth) << "Price(RM)" << '|' << endl;

    printLine(colWidth, numCols);
    for (int i = 1; i <= 4; i++) {

        cout << '|' << left << setw(6) << i << '|' << setw(colWidth2) << nameSoda[i] << '|' << setw(colWidth) << priceSoda[i] << '|' << endl;
    }

    printLine(colWidth, numCols);

    //calculate the total of the drink
    cout << "Enter the number drink you want : ";
    cin >> drt;
    if (drt == 0) {
        menu();
    }
    else if (drt >= 1 && drt <= 4) {
        drsoda.push_back(drt);
        cout << "Enter the quantity of drink : ";
        cin >> qty;
        qtysoda.push_back(qty);
    }
    else {
        cout << "INVALID NUMBER,PLEASE ENTER THE VALID NUMBER";

    }
    cout << endl;
    cout << "You wanna order more drink (Y/N) : ";//choose wanna order more or no
    cin >> choose;
    if (choose == 'Y' || choose == 'y') {//if yes this function will bring you back to menu
        menu();
    }
    else if (choose == 'N' || choose == 'n') {
        cout << "PLACE ORDER (Y/N) : ";
        cin >> choose;
        if (choose == 'Y' || choose == 'y') {
            cart();
        }
        else if (choose == ' N' || choose == 'n') {
            menu();
        }
    }
}

void coffee() {
    printLine(colWidth, numCols);

    cout << '|' << left << setw(6) << "No" << '|' << setw(colWidth2) << "Name" << '|' << setw(colWidth) << "Price(RM)" << '|' << endl;

    printLine(colWidth, numCols);
    for (int i = 1; i <= 5; i++) {

        cout << '|' << left << setw(6) << i << '|' << setw(colWidth2) << nameCoffee[i] << '|' << setw(colWidth)<<fixed << setprecision(2) << priceCoffee[i] << '|' << endl;
    }

    printLine(colWidth, numCols);

    //calculate the total of the drink
    cout << "Enter the number drink you want : ";
    cin >> drt;
    if (drt == 0) {
        menu();
    }
    else if (drt >= 1 && drt <= 5) {
        drcoffee.push_back(drt);
        cout << "Enter the quantity of drink : ";
        cin >> qty;
        qtycoffee.push_back(qty);
    }
    else {
        cout << "INVALID NUMBER,PLEASE ENTER THE VALID NUMBER";

    }
    cout << endl;
    cout << "You wanna order more drink (Y/N) : ";//choose wanna order more or no
    cin >> choose;
    if (choose == 'Y' || choose == 'y') {//if yes this function will bring you back to menu
        menu();
    }
    else if (choose == 'N' || choose == 'n') {
        cout << "PLACE ORDER (Y/N) : ";
        cin >> choose;
        if (choose == 'Y' || choose == 'y') {
            cart();
        }
        else if (choose == ' N' || choose == 'n') {
            menu();
        }
    }
}

void receipt() {
    double src = total * 0.10;
    double tax = total * 0.06;
    double total_2 = total * 1.16;
    cout << "Cash,Credit Card or TNG(C,D,T) : ";
    cin >> choose;
    printLine(colWidth, numCols);
    cart_result();
    printLine(colWidth, numCols);
    if (choose == 'c' || choose == 'C') {
        cout << "Payment Method : Cash\n";
    }
    else if (choose == 'D' || choose == 'd') {
        cout << "Payment Method : Credit Card\n";
    }
    else if (choose == 't' || choose == 'T') {
        cout << "Payment Method : TNG\n";
    }
    cout << "Service charge(10%) : " << setprecision(2) << fixed << src << "\n";
    cout << "Tax (6%)            : " << setprecision(2) << fixed << tax << "\n";
    cout << "total payable       : " << setprecision(2) << fixed << total_2 << "\n";
    exit(0);
}

void staff_function() {

}


void login_system() {

    displayMenu();
    cout << "Enter your choice (1-3): ";
    cin >> option;

    while (true) {
        switch (option) {
        case 1:
            user_login();
            break;
        case 2:
            staff_login();
            break;
        case 3:
            cout << "Existing the main page" << "\n";
            cout << "Thanks for Looking at Yuki's cafe menu" << "\n";
            break;

        default:
            cout << "Invalid choice. Please enter a number between 1 and 3 : ";
            cin >> option;
            break;
        }
    }
}

void user_login() {
    cout << "\nnew user.register? (y/n): ";
    cin >> choose;
    if (choose == 'y' || choose == 'Y') {
        rg();
    }
    else if (choose == 'n' || choose == 'N') {
        login();
    }
    home();
}

void staff_login() {
    const string staffid = "S001";
    const string staffPassword = "staff123";
    cout << "Pleae Enter your Staff ID :";
    cin >> inID;
    cout << "Pleae Enter your Staff Password :";
    cin >> enteredPassword;

    while(true){
        if (enteredPassword == staffPassword && inID == staffid)
        {
            cout << "Access granted." << endl;
            cout << "\n";
            staff_function();
            break;
        }
        else
        cout << "\nAccess denied.";
        cout << "\n\nPlease re-enter ID :";
        cin >> inID;
        cout << "Please re-enter Password :";
        cin >> enteredPassword;

    } 
}
