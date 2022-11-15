#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
#include"BankAccount.h"
#include "SavingBankAccount.h"
using namespace std;
#ifndef CLIENT_MARK_FUNCTION
#define CLIENT_MARK_FUNCTION
class BankAccount;
class Client{
    
    private:
        string name;
        string address;
        string phone;
        int balance;
        
    public:
    BankAccount* bankaccountptr;
        Client(){
            name="";
           address="";
           phone="";
           
           
        }
        Client(string name, string address,string phone,int balance,int type){
            this->name=name;
            this->address=address;
            this->phone=phone;
            bankaccountptr->setBalance(balance);
          
            
        }
        Client(int type){
            
   switch (type)
            {
            case 1:
            
                bankaccountptr =new BankAccount();
                
                cout<<"your bank account type is basic"<<endl;
                bankaccountptr->setType("Basic");
                break;
            case 2:
            
                bankaccountptr = new SavingsBankAccount();
                
              cout<<"your bank account type is saving"<<endl;
              bankaccountptr->setType("Saving");
                break;
            default:
                break;}
        }
        void setName(string name){this->name=name;}
        string getName(){return name;}
          void setBalance(double balance){this->balance=balance;}
    int getBalance(){return balance;}
        void setAddress(string address){this->address=address;}
        string getAddress(){return address;}
        void setPhone(string phone){this->phone=phone;}
        string getPhone(){return phone;}


};
#endif