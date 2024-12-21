#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>
#include <string>
#include "classes.h"

void newAccount(vector<BankAccount>& accounts, const string& folderPath);
void checkBalance(const vector<BankAccount>& accounts);
void Menu();

#endif // FUNCTIONS_H