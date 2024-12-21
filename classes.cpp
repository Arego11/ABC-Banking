#include "classes.h"
#include <iostream>
#include <fstream>
#include <filesystem>
using namespace std;

int BankAccount::nextAccountNumber = 0;

BankAccount::BankAccount(string nameCust, double balanceAmmount, int scoreCust)
        : name(move(nameCust)), score(scoreCust), balance(balanceAmmount) {
    accountNumber = ++nextAccountNumber;
}

BankAccount::BankAccount() : name(""), score(0), balance(0), accountNumber(++nextAccountNumber) {}

void BankAccount::setName(const string& name) { this->name = name; }
void BankAccount::setScore(int score) { this->score = score; }
void BankAccount::setBalance(double balance) { this->balance = balance; }

int BankAccount::getScore() const { return score; }
double BankAccount::getBalance() const { return balance; }
string BankAccount::GetName() const { return name; }
int BankAccount::getAccountNumber() const { return accountNumber; }

void BankAccount::giveInformation() const {
    cout << "\nAccount Number: " << accountNumber
         << "\nAccount Name: " << name
         << "\nAccount Balance: $" << balance
         << "\nAccount Score: " << score
         << "\n-----------------------------" << "\n" << endl;
}

void BankAccount::saveToFile(const string& folderPath) const {
    if (!filesystem::exists(folderPath)) {
        filesystem::create_directory(folderPath);
    }
    string filePath = folderPath + "/Account_" + to_string(accountNumber) + ".txt";
    ofstream outFile(filePath);
    if (outFile.is_open()) {
        outFile << "Account Name: " << name << '\n'
                << "Account Number: " << accountNumber << '\n'
                << "Score: " << score << '\n'
                << "Balance: $" << balance << '\n';
        outFile.close();
        cout << "Account details saved to " << filePath << ".\n";
    } else {
        cerr << "Error: Could not create file " << filePath << ".\n";
    }
}