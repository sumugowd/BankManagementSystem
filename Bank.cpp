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

void Bank::withdraw(){
    int accNumber;
    double amount;
    bool found = false;

    cout << "Enter Account Number: ";
    cin >> accNumber;

    for(auto &acc : accounts){
        if(acc.getAccountNumber() == accNumber){
            cout << "Enter Amount to Withdraw: ";
            cin >> amount;

            acc.withdraw(amount);

            saveToFile();
            found = true;
            break;
        }
    }
    if(!found){
        cout << "Account Not Found\n";
    }
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

void Bank::deleteAccount(){
    int accNumber;
    bool found = false;

    cout << "Enter Account Number to Delete: ";
    cin >> accNumber;

    for(auto it = accounts.begin(); it != accounts.end(); it++){
        if(it->getAccountNumber() == accNumber){
            accounts.erase(it);
            saveToFile();

            cout << "Account Deleted Successfully\n";
            found = true;
            break;
        }
    }
    if(!found){
        cout << "Account Not Found\n";
    }
}

void Bank::displayAllAccounts(){
    if(accounts.empty()){
        cout << "No accounts available\n";
        return;
    }

    cout << "\n ------ All Bank Accounts ------\n";

    for(const auto &acc : accounts){
        acc.display();
        cout << endl;
    }
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

    if(!file.is_open()){
        return;
    }

    int accNumber;
    string name;
    double balance;

    while (file >> accNumber >> name >> balance) {
        Account acc(accNumber, name, balance);
        accounts.push_back(acc);
    }

    file.close();
}