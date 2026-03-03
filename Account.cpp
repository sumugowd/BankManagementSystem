#include "Account.h"

// Constructor
Account::Account() {
    accountNumber = 0;
    name = "";
    balance = 0.0;
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
    cout << "\n Account Created Successfully!\n";
}

// Display
void Account::display() const {
    cout << "Account Number: " << accountNumber << endl;
    cout << "Name: " << name << endl;
    cout << "Balance: Rs" << balance << endl;
}

void Account::deposit(double amount) {
    balance += amount;
    cout << "Amount Deposited Successfully\n";
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