#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
#include"BankAccount.h"

using namespace std;
#ifndef SAVINGBANKACCOUNT_MARK_FUNCTION
#define SAVINGBANKACCOUNT_MARK_FUNCTION
class SavingsBankAccount : public BankAccount{
    using BankAccount::BankAccount;
private:

    int minimunBalance;
public:
    SavingsBankAccount();
    SavingsBankAccount(string accountID,int balance,int minimumBalance);
    void setMinimunBalance(int minimumBalance);
    double getMinimunBalance();
    int withdraw(double amount)override;
    int deposit(double amount)override;

};
#endif