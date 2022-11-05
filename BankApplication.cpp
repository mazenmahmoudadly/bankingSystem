#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
#include"BankAccount.h"
#include"SavingBankAccount.h"
#include"Client.h"
using namespace std;
class BankApplication{
public:

    BankApplication(){

    }
    bool addClient(){

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
// addClient();
cout<<"addClient()"<<endl;
    break;
case '2':
 system("CLS");
// list clients and accounts
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
