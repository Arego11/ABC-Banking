#include "functions.h"
#include <iostream>
#include <filesystem>
#include <fstream>
#include <algorithm>

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

void BankAccount::giveInformation() const {
    cout << "\nAccount Number: " << accountNumber
         << "\nAccount Name: " << name
         << "\nAccount Balance: $" << balance
         << "\nAccount Score: " << score
         << "\n-----------------------------" << "\n" << endl;
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

void bringTheAccountsBack(vector<BankAccount>& accounts, const string& folderPath) {
    // Loop through all the text files in the folder and load the accounts
    for (const auto& entry : filesystem::directory_iterator(folderPath)) {
        if (entry.is_regular_file() && entry.path().extension() == ".txt") {
            // Load the account from the file and add it to the vector
            accounts.push_back(BankAccount::loadFromFile(entry.path().string()));
        }
    }

    sort(accounts.begin(), accounts.end(), [](const BankAccount& a, const BankAccount& b){
        return a.getAccountNumber() < b.getAccountNumber();
    });
}

void Menu() {
    vector<BankAccount> accounts;
    string folderPath = "/Users/liner/Documents/cpp training/BankAccount.cpp/Accounts"; // this is my path, change it to yours to use
    if (!filesystem::exists(folderPath)) {
        filesystem::create_directory(folderPath);
    }
    bringTheAccountsBack(accounts, folderPath);

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

void BankAccount::saveToFile(const string& folderPath) const {
    if (!filesystem::exists(folderPath)) {
        filesystem::create_directory(folderPath);
    }

    //creating the files with unique account number based on nextAccountNumber
    string filePath = folderPath + "/Account_" + to_string(accountNumber) + ".txt";
    ifstream existingFile(filePath);
    if (existingFile.is_open()) {
        // File already exists, don't overwrite it
        cerr << "Error: File already exists for this account number.\n";
        existingFile.close();
        return;
    }

    ofstream outFile(filePath);
    if (outFile.is_open()) {
        outFile << "Account Name: " << name << '\n'
                << "Account Number: " << accountNumber << '\n'
                << "Score: " << score << '\n'
                << "Balance: $" << balance << '\n';
        outFile.close();
    } else {
        cerr << "Error: Could not create file " << ".\n";
    }
}

BankAccount BankAccount::loadFromFile(const string& filePath) {
    ifstream inFile(filePath);
    if (!inFile.is_open()) {
        cerr << "Error: Could not open file " << filePath << ".\n";
        return BankAccount(); // Return an empty account if the file can't be read
    }

    string name, line;
    int score = 0, accountNumber = 0;
    double balance = 0.0;

    try {
        getline(inFile, line);
        name = line.substr(line.find(":") + 2);
        getline(inFile, line);
        accountNumber = stoi(line.substr(line.find(":") + 2));
        getline(inFile, line);
        score = stoi(line.substr(line.find(":") + 2));
        getline(inFile, line);
        balance = stod(line.substr(line.find("$") + 1));

        inFile.close();
    }catch (const exception& e){
        cerr << "Error parsing file: " << filePath << "\n" << e.what() << "n";
        inFile.close();
        return BankAccount();
    }

    // Return a new BankAccount object with the loaded data
    BankAccount account(name, balance, score);
    account.accountNumber = accountNumber; // Set the account number
    return account;
}