#ifndef BANK_H
#define BANK_H

#include "Account.h"
#include <vector>

using namespace std;

class Bank {
    private:

    vector<Account> accounts;

    public:
    Bank();

    void createAccount();
    void deposit();
    void displayAccount();

    void saveToFile();
    void loadFromFile();
};

#endif