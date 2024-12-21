#ifndef CLASSES_H
#define CLASSES_H

#include <string>
using namespace std;

class BankAccount {
private:
    string name;
    int score;
    double balance;
    static int nextAccountNumber;
    int accountNumber;

public:
    BankAccount(string nameCust, double balanceAmmount, int scoreCust);
    BankAccount();

    void setName(const string& name);
    void setScore(int score);
    void setBalance(double balance);

    int getScore() const;
    double getBalance() const;
    string GetName() const;
    int getAccountNumber() const;

    void giveInformation() const;
    void saveToFile(const string& folderPath) const;
};

#endif // CLASSES_H