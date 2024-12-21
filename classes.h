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
    BankAccount(string nameCust, double balanceAmmount, int scoreCust);
    BankAccount();

    void setName(const string& name);
    void setScore(int score);
    void setBalance(double balance);
    static void setNextAccountNumber(int newNumber) {
        nextAccountNumber = newNumber;
    }

    static int getNextAccountNumber() { return nextAccountNumber;}
    int getScore() const;
    double getBalance() const;
    string GetName() const;
    int getAccountNumber() const;

    void giveInformation() const;
    void saveToFile(const string& folderPath) const;

    static BankAccount loadFromFile(const string& filePath);
};

#endif // CLASSES_H