#include "Bank.h"
#include <iostream>
#include <fstream>

using namespace std;

// constructor
Bank::Bank() {
    loadFromFile();
}

void Bank::createAccount() {
    Account acc;
    acc.createAccount();
    accounts.push_back(acc);
    saveToFile();
}

void Bank::deposit() {
    int accNumber;
    double amount;
    bool found = false;

    cout << "Enter Account Number: ";
    cin >> accNumber;

    for (auto &acc : accounts) {
        if (acc.getAccountNumber() == accNumber) {
            cout << "Enter Amount: ";
            cin >> amount;
            acc.deposit(amount);
            found = true;
            saveToFile();
            break;
        }
    }

    if (!found)
        cout << "Account Not Found\n";
}

void Bank::displayAccount() {
    int accNumber;
    bool found = false;

    cout << "Enter Account Number: ";
    cin >> accNumber;

    for (auto &acc : accounts) {
        if (acc.getAccountNumber() == accNumber) {
            acc.display();
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Account Not Found\n";
}

void Bank::saveToFile() {
    ofstream file("accounts.txt");

    for (auto &acc : accounts) {
        file << acc.getAccountNumber() << " "
             << acc.getName() << " "
             << acc.getBalance() << endl;
    }

    file.close();
}

void Bank::loadFromFile() {
    ifstream file("accounts.txt");

    int accNumber;
    string name;
    double balance;

    while (file >> accNumber >> name >> balance) {
        Account acc;
        acc.deposit(balance);   // temporary loading
        accounts.push_back(acc);
    }

    file.close();
}