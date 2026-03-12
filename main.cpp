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
        cout << "3. Withdraw Money\n";
        cout << "4. Display Account\n";
        cout << "5. Delete Account\n";
        cout << "6. Display All Accounts\n";
        cout << "7. Exit\n";
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
                bank.withdraw();
                break;

            case 4:
                bank.displayAccount();
                break;

            case 5:
                bank.deleteAccount();
                break;

            case 6:
                bank.displayAllAccounts();
                break;

            case 7:
                cout << "Exiting Program...\n";
                return 0;

            default:
                cout << "Invalid Choice\n";
        }
    }
}