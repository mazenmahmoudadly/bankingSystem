#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
#include<string>
using namespace std;
#include"BankAccount.h"
vector<Client> cvec;
    BankAccount::BankAccount(){
        accountID="";
        balance=0.0;
        count++;
    }
    BankAccount::BankAccount(string accountID,double balance){
        this->accountID=accountID;
        this->balance=balance;
        count++;
    }
    string BankAccount::getType(){return type;}
    void BankAccount::setType(string type){this->type=type;}
    void BankAccount::setAccountID(string accountID){
        
    string temp1 ="FCAI-";
    string temp2=to_string((cvec.size()/6)+1);
    this->accountID=temp1+temp2;
    // cvec.push_back(accountID);
    
    }
    string BankAccount::getAccountID(){
        
        return accountID;
        }
    void BankAccount::setBalance(double balance){this->balance=balance;}
    double BankAccount::getBalance(){return balance;}
    int BankAccount::withdraw(double amount){
        if(amount<=0){
            cout<<"invalid input"<<endl;
        }
        else{
        if(balance>=amount){
            balance-=amount;
        }
        else{
            cout<<"your balance is less than the withdraw amount"<<endl;
        }}
    }
    int BankAccount::deposit(double amount){
        if(amount<=0){
            cout<<"invalid input"<<endl;
        }
        else{
            balance+=amount;
        }
    }