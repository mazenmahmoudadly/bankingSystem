#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
using namespace std;
#include"SavingBankAccount.h"
#include"BankAccount.cpp"

    SavingsBankAccount::SavingsBankAccount():BankAccount(){
        minimunBalance=1000;
        count++;
    }
    SavingsBankAccount::SavingsBankAccount(string accountID,int balance,int minimumBalance=1000):BankAccount(accountID,balance){
        this->minimunBalance=minimumBalance;
        if(balance>=minimunBalance){
            this->balance=balance;
        }
        else{
            cout<<"your initial balance is less than the minimum balance required"<<endl;
        }
        count++;
        
    }
     void SavingsBankAccount::setMinimunBalance(int minimumBalance){
        this->minimunBalance=minimumBalance;
     }
    double SavingsBankAccount::getMinimunBalance(){return minimunBalance;}
    int SavingsBankAccount::withdraw(double amount){
                if(amount<=0){
            cout<<"invalid input"<<endl;
        }
        if(balance-amount<minimunBalance){
            cout<<"your withdraw amount is less than the minimum balance required"<<endl;
        }
           else{ 
            balance-=amount;
            }
        
       
        }
    
    int SavingsBankAccount::deposit(double amount){
            if(amount<100){
            cout<<"invalid input"<<endl;
        }
        else{
            balance+=amount;
        }
    }