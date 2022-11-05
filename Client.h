#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
#include"BankAccount.h"
#include"SavingBankAccount.h"
using namespace std;
#ifndef CLIENT_MARK_FUNCTION
#define CLIENT_MARK_FUNCTION
class Client{
    private:
        string name;
        string address;
        string phone;
        // BankAccount pointer
        int balance;
    public:
        Client(string name, string address,string phone,int balance){
            this->name=name;
            this->address=address;
            this->phone=phone;
            // bankaccount type
            this->balance=balance;
        }   

};
#endif