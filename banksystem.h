#ifndef BANKSYSTEM_MARK_FUNCTION
#define BANKSYSTEM_MARK_FUNCTION
#include<iostream>
#include<vector>
#include<sstream>
#include<string>
#include<cctype>
#include<algorithm>
using namespace std;
int index;
vector<string> cvec;
class Client;
class BankAccount{
protected:    
    string accountID;
    string balance;
    Client* client;
        string type;
    
public:
    static int count;
    BankAccount();
    BankAccount(string balance);
    void setAccountID();
    string getAccountID();
    string getType();
    void setType(string type);
    void setBalance(string balance);
    string getBalance();
   virtual void withdraw();
    virtual void deposit();
};
class SavingsBankAccount : public BankAccount{
    using BankAccount::BankAccount;
private:

    int minimunBalance;
public:
    SavingsBankAccount();
    SavingsBankAccount(string balance);
   
    void withdraw();
    void deposit();

};
class Client{
    
    private:
        string name;
        string address;
        string phone;
        
        
    public:
    BankAccount* bankaccountptr;
        Client(){
            name="";
           address="";
           phone="";
           
           
        }
        Client(string name, string address,string phone,string balance,int type){
             if (type == 1){
                bankaccountptr = new BankAccount(balance);}
            else{ bankaccountptr = new SavingsBankAccount(balance);}
            this->name=name;
            this->address=address;
            this->phone=phone;
            cvec.push_back(name);
            cvec.push_back(address);
            cvec.push_back(phone);
        
            
        }
        Client(int type){
            
   switch (type)
            {
            case 1:
                bankaccountptr =new BankAccount();
                break;
            case 2:
                bankaccountptr = new SavingsBankAccount();
                break;
            default:
                break;}
        }
        void setName(string name){this->name=name;}
        string getName(){return name;}

        void setAddress(string address){this->address=address;}
        string getAddress(){return address;}
        void setPhone(string phone){this->phone=phone;}
        string getPhone(){return phone;}


};
#endif