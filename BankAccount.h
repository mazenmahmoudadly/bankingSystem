#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>

#ifndef BANKACCOUNT_MARK_FUNCTION
#define BANKACCOUNT_MARK_FUNCTION
using namespace std;
class Client;
class BankAccount{
protected:    
    string accountID;
    int balance;
    Client* client;
        string type;
    
public:
    static int count;
    BankAccount();
    BankAccount(string accountID,double balance);
    void setAccountID(string accountID);
    string getAccountID();
    string getType();
    void setType(string type);
    void setBalance(double balance);
    double getBalance();
   virtual int withdraw(double amount);
    virtual int deposit(double amount);
};
int BankAccount::count;
#endif