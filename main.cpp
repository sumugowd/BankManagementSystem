#include "Account.h"
#include <vector>

int main() {
    vector<Account> accounts;
    int choice;
    int accNumber;
    double amount;

    while (true) {
        cout << "\n====== BANK MANAGEMENT SYSTEM ======\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Display Account\n";
        cout << "4. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {

            case 1: {
                Account acc;
                acc.createAccount();
                accounts.push_back(acc);
                break;
            }

            case 2: {
                cout << "Enter Account Number: ";
                cin >> accNumber;

                bool found = false;
                for (auto &acc : accounts) {
                    if (acc.getAccountNumber() == accNumber) {
                        cout << "Enter Amount: ";
                        cin >> amount;
                        acc.deposit(amount);
                        found = true;
                        break;
                    }
                }

                if (!found)
                    cout << "Account Not Found\n";
                break;
            }

            case 3: {
                cout << "Enter Account Number: ";
                cin >> accNumber;

                bool found = false;
                for (auto &acc : accounts) {
                    if (acc.getAccountNumber() == accNumber) {
                        acc.display();
                        found = true;
                        break;
                    }
                }

                if (!found)
                    cout << "Account Not Found\n";

                break;
            }

            case 4:
                cout << "Exiting Program...\n";
                return 0;

            default:
                cout << "Invalid Choice\n";
        }
    }
}