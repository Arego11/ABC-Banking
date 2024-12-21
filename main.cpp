
// allow people to sign in, make logins and passwords and make accounts,
// add withdrawal and deposit functions, store them somewhere and google if there are better ways to store information instead of just assigning them to variables.
// add inheritance.
// add menu system.
// add interest and fees.
// smart pointers? google what that is.
// allow to import information using an outside file.


#include <iostream>
#include <utility>
#include <string>
using namespace std;

class BankAccount{
private:
    string name;
    int score;
    double balance;
    static int nextAccountNumber;
    int accountNumber;

public:
    BankAccount(string nameCust, double balanceAmmount, int scoreCust) :
    name(move(nameCust)), score(scoreCust), balance(balanceAmmount){
        accountNumber = ++nextAccountNumber;
    }
    BankAccount() : name (""), score(0), balance(0), accountNumber(++nextAccountNumber){}

    void setName(const string &name) { this->name = name;}
    void setScore(int score) { this->score = score;}
    void setBalance(double balance) { this->balance = balance;}

    int getScore() const { return score;}
    double getBalance() const { return balance;}
    string GetName() const { return name;}
    int getAccountNumber() const { return accountNumber;}

    void giveInformation() const {
        cout
        << "\nAccount Number: " << accountNumber
        << "\nAccount Name: " << name
        << "\nAccount Balance: $" << balance
        << "\nAccount score: " << score
        << "\n-----------------------------" << "\n" << endl;
    }
};

int BankAccount :: nextAccountNumber = 0;

void newAccount(vector<BankAccount>&/*know what this & does*/ accounts){
    string name;
    double balance;
    int score;
    cout << "Your name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Your score (0-850): ";
    cin >> score;
    if (score < 0 || score > 850){
        cout << "incorrect input, please enter a number between 0 to 850: \n";
        cin >> score;
    }

    cout << "Initial deposit: $";
    cin >> balance;
    int interest = 0;
    if (balance >=100000){
        interest = balance * 0.003;
        balance = balance - interest;
        cout << "we have special interest rates for any deposit above $100000,"
                "\nIt is 0.3% instead of the regular 1.2%, which is $" << interest << "."
                "\nYour Bank balance is " << balance << "."
                "\nThank you for choosing ABC Banking :)" << endl;
    }
    else if (balance >=0 ){
        interest = balance * 0.012;
        cout << "Your in interest rate is at 1.2%, which is $" <<  interest << ".""\nThank you for choosing ABC Banking :)" << endl;
    }
    else {
        cout << "incorrect ammount, cant be lower than $0"
                "\n Try again." << endl;
        cin >> balance;
    }
    accounts.emplace_back(name, balance, score);
    cout << "\nCongratulations " << name << ", your account has been created.\n\n";
}

void checkBalance(const vector<BankAccount>& accounts){
    if (accounts.empty()){
        cout << "No account was found\n" << endl;
        return;
    }
    for (const auto& accounts : accounts){
        accounts.giveInformation();
    }
}

void Menu() {
    vector<BankAccount> accounts;
    int choice;

    do {
        cout << "\nWelcome to ABD bank\n"
             << "Choose one of the options\n"
             << "1: Open a new account\n"
             << "2: Check balance\n"
             << "3: Deposit money\n"
             << "4: Withdraw money\n"
             << "0: Quit\n"
             << "\n-----------------------" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                newAccount(accounts);
                break;
            case 2:
                checkBalance(accounts);
                break;
            case 0:
                cout << "Exiting menu:\n" << endl;
                break;
            default:
                cout << "invalid choice, try again\n" << endl;
        }
    }while (choice != 0);
}

int main() {
    Menu();
    return 0;
}