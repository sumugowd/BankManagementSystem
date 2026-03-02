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
}

// Display
void Account::display() const {
    cout << "Account Number: " << accountNumber << endl;
    cout << "Name: " << name << endl;
    cout << "Balance: ₹" << balance << endl;
}