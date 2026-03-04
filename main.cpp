#include "Bank.h"
#include <iostream>
using namespace std;

int main() {
    Bank bank;
    int choice;

    while (true) {
        cout << "\n====== BANK MANAGEMENT SYSTEM ======\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Display Account\n";
        cout << "4. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                bank.createAccount();
                break;

            case 2:
                bank.deposit();
                break;

            case 3:
                bank.displayAccount();
                break;

            case 4:
                cout << "Exiting Program...\n";
                return 0;

            default:
                cout << "Invalid Choice\n";
        }
    }
}