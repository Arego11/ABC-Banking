#include "classes.h"
#include <fstream>
#include <iostream>

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