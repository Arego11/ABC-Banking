#ifndef CLASSES_H
#define CLASSES_H

#include <string>
using namespace std;

class BankAccount {
private:
    string name;
    int score;
    double balance;
    int accountNumber;
public:

    static int nextAccountNumber;


public:
    BankAccount(string nameCust, double balanceAmmount, int scoreCust);

    BankAccount();

    void saveToFile(const std::string& filename) const;

    void giveInformation() const;

    void setName(const string &name);

    void setScore(int score);

    void setBalance(double balance);

    static void setNextAccountNumber(int newNumber) {
        nextAccountNumber = newNumber;
    }

    static int getNextAccountNumber() { return nextAccountNumber; }

    int getScore() const;

    double getBalance() const;

    string GetName() const;

    int getAccountNumber() const;

    static BankAccount loadFromFile(const string &filePath);

#endif // CLASSES_H
};