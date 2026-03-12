#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
using namespace std;

class Account {
private:
    int accountNumber;
    string name;
    double balance;

public:
    Account();
    Account(int accNo, string nm ,double bal);
    void createAccount();
    void deposit(double amount);
    void withdraw(double amount);
    void display() const;
    
    int getAccountNumber() const;
    double getBalance() const;
    string getName() const;
};

#endif