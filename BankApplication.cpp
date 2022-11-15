#include<iostream>
#include<fstream>
#include<cctype>
#include<vector>
#include<iomanip>
#include"Client.h"
#include"SavingBankAccount.cpp"
using namespace std;
class BankApplication{
public:

    BankApplication(){

    }
    bool addClient(){
        Client client;
        string name;
        string address;
        string phone;
        int balance;
       BankAccount *bankaccountptr;
        cout<<"Please Enter Client Name =======>";
        cin>>name;
        client.setName(name);
        cout<<"Please Enter Client Address =======>";
        cin>>address;
        client.setAddress(address);
        cout<<"Please Enter Client Phone =======>";
        cin>>phone;
        client.setPhone(phone);
            int choice;
            cout<<"What Type of Account Do You Like? (1) Basic (2) Saving – Type 1 or 2 =========>";
            cin>>choice;
            if (choice==1){
                
            }
            else if(choice==2){
                
            }

        cout<<"Please Enter the Starting Balance =========>";
        cin>>balance;

        
        client.setBalance(balance);

        cout<<"An account was created with ID"<<client.bankaccountptr->getAccountID()<< "and Starting Balance" <<client.bankaccountptr->getBalance()<<" L.E."<<endl;
        save(client);
    }
    void save(Client c){
        
        cvec.push_back(c);
    }
    void display_list(){
        
        for(int i=0;i<cvec.size();i++){
            cout<<"Name: "<<cvec[i].getName()<<endl;
            cout<<"Address: "<<cvec[i].getAddress()<<endl;
            cout<<"ID: "<<cvec[i].bankaccountptr->getAccountID()<<i<<"( "<<cvec[i].bankaccountptr->getType()<<" )"<<endl;
            cout<<"Balance: "<<cvec[i].bankaccountptr->getBalance()<<endl;
            cout<<"-------------------------------"<<endl;

        }
    }
    void display(){
        char choice;
    do{
        system("CLS");
  cout<<"\n Welcome to FCAI Banking Application\n"
"\n1. Create a New Account\n"
"\n2. List Clients and Accounts\n"
"\n3. Withdraw Money\n"
"\n4. Deposit Money\n"
"\n5. Exit\n"
"\nPlease Enter Choice"<<endl;
cin>>choice;
switch (choice)
{
case '1':
 system("CLS");
addClient();
    break;
case '2':
 system("CLS");
display_list();
cout<<"list clients and accounts"<<endl;
    break;
case '3':
 system("CLS");
// withdraw
cout<<"withdraw"<<endl;
    break;
case '4':
 system("CLS");
// deposit money
cout<<"deposit money"<<endl;
    break;
case '5':
system("CLS");
exit(0);
    break;        
default:
    cout<<"invalid input";
   
}
cin.ignore();
cin.get();
    }
    while (choice!=5);

    
    }
};
int main(){
BankApplication b;
b.display();

return 0;
}
