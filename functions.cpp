#include "functions.h"
#include <iostream>
#include <filesystem>
using namespace std;

void newAccount(vector<BankAccount>& accounts, const string& folderPath) {
    string name;
    double balance;
    int score;

    cout << "Your name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Your score (0-850): ";
    cin >> score;
    if (score < 0 || score > 850) {
        cout << "Invalid input, please enter a number between 0 and 850: ";
        cin >> score;
    }

    cout << "Initial deposit: $";
    cin >> balance;
    double interest = 0;

    if (balance >= 100000) {
        interest = balance * 0.003;
        balance -= interest;
        cout << "Special interest rate for deposits over $100000 (0.3%) applied.\n";
    } else if (balance >= 0) {
        interest = balance * 0.012;
        cout << "Standard interest rate of 1.2% applied.\n";
    } else {
        cout << "Amount cannot be negative. Try again.\n";
        return;
    }

    accounts.emplace_back(name, balance, score);
    accounts.back().saveToFile(folderPath);
    cout << "\nAccount created successfully.\n";
}

void checkBalance(const vector<BankAccount>& accounts) {
    if (accounts.empty()) {
        cout << "No accounts found.\n";
        return;
    }
    for (const auto& account : accounts) {
        account.giveInformation();
    }
}

void Menu() {
    vector<BankAccount> accounts;
    string folderPath = "/Users/liner/Documents/cpp training/Accounts";
    if (!filesystem::exists(folderPath)) {
        filesystem::create_directory(folderPath);
    }

    int choice;
    do {
        cout << "\nWelcome to ABC Bank\n"
             << "1: Open a new account\n"
             << "2: Check balance\n"
             << "0: Quit\n"
             << "-----------------------\n";
        cin >> choice;

        switch (choice) {
            case 1:
                newAccount(accounts, folderPath);
                break;
            case 2:
                checkBalance(accounts);
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);
}