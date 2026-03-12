#include "Account.h"

// Constructor
Account::Account() {
    accountNumber = 0;
    name = "";
    balance = 0.0;
}

Account::Account(int accNo, string n, double bal){
    accountNumber = accNo;
    name = n;
    balance = bal;
}

// Create Account
void Account::createAccount() {
    cout << "Enter Account Number: ";
    cin >> accountNumber;

    cin.ignore();

    cout << "Enter Name: ";
    getline(cin,name);

    cout << "Enter balance: ";
    cin >> balance;
}

// Display
void Account::display() const {
    cout << "Account Number: " << accountNumber << endl;
    cout << "Name: " << name << endl;
    cout << "Balance: Rs" << balance << endl;
}

void Account::deposit(double amount) {
    if(amount <= 0){
        cout << "Invalid deposit amount\n";
        return;
    }
    balance += amount;
    cout << "Amount Deposited Successfully\n";
}

void Account::withdraw(double amount){
    if(amount <= 0){
        cout << "Invalid withdrawl amount\n";
        return;
    }
    if(amount > balance){
        cout << "Insufficient Balance\n";
        return;
    }

    balance -= amount;
    cout << "Withdrawl Successful\n";
}

int Account::getAccountNumber() const {
    return accountNumber;
}

double Account::getBalance() const {
    return balance;
}

string Account::getName() const {
    return name;
}