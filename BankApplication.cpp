// banking system application
// name:mazen mahmoud adly
// id:20210318

#include<iostream>
#include<vector>

#include"banksystem.cpp"
using namespace std;
class BankApplication{
public:

    BankApplication(){

    }
    void addClient(){
        string name;
        string address;
        string phone;
        string balance;
        cout<<"Please Enter Client Name =======>";
        cin>>name;
        cout<<"Please Enter Client Address =======>";
        cin>>address;
       
        cout<<"Please Enter Client Phone =======>";
        cin>>phone;
       
            int choice;
            cout<<"What Type of Account Do You Like? (1) Basic (2) Saving – Type 1 or 2 =========>";
            cin>>choice;
            if (choice==1){
                
                  cout<<"Please Enter the Starting Balance =========>";
                    cin>>balance;
                    Client client(name,address,phone,balance,1);
                    
                    cvec.push_back("Basic");
                 cout<<"An account was created with ID "<<client.bankaccountptr->getAccountID() << "and Starting Balance" <<client.bankaccountptr->getBalance()<<" L.E."<<endl;

            }
            else if(choice==2){
                    cout<<"Please Enter the Starting Balance =========>";
                    cin>>balance;
                    Client client(name,address,phone,balance,2);
                    
                     cvec.push_back("Saving");
                    cout<<"An account was created with ID " << client.bankaccountptr->getAccountID() << "and Starting Balance" << client.bankaccountptr->getBalance() << " L.E." << endl;

            }

    }
    void display_list(){
        
        for(int i=0;i<cvec.size();i++){
        if(i%6==0){
            cout<<endl;
          }
          cout<<cvec[i]<<" ";
     

        }
    }

void do_withdraw(){
    cout << "please enter your id: ";
    string id;
    cin >> id;
    auto it = find(cvec.begin(), cvec.end(), id);
    index = it - cvec.begin();
    if (cvec[index + 1] == "Basic"){
        Client client(1);
        client.bankaccountptr->withdraw();
    }
    else{
        Client client(2);
        client.bankaccountptr->withdraw();
    }
}

void do_deposit(){
    cout << "please enter your id: ";
    string id;
    cin >> id;
    auto it = find(cvec.begin(), cvec.end(), id);
    index = it - cvec.begin();
    if (cvec[index + 1] == "Basic"){
        Client client(1);
        client.bankaccountptr->deposit();
    }
    else{
        Client client(2);
        client.bankaccountptr->deposit();
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
cin >> choice;
switch (choice)
{
case '1':
 system("CLS");
addClient();
    break;
case '2':
 system("CLS");
display_list();
// cout<<"list clients and accounts"<<endl;
    break;
case '3':
 system("CLS");
    do_withdraw();
// cout<<"withdraw"<<endl;
    break;
case '4':
 system("CLS");
    do_deposit();
// cout<<"deposit money"<<endl;
    break;
case '5':
system("CLS");
exit(0);

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
