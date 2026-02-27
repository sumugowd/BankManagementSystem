#ifndef ACCOUNT_H
#define ACCOUNT_h

#include <iostream>
using namespace std;

class Account {
    private:

    int accountNumber;
    string name;
    double balance;

    public:
    Account();
    void createAccount();
    void deposit(double amount);
    void display() const;
    
    int getAccountNumber() const;
    double getBalance() const;
    string getName() const;
};

#endif