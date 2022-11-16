 #include"banksystem.h"
 BankAccount::BankAccount(){
        accountID="";
        balance=0.0;
        
    }
    BankAccount::BankAccount(string balance){
       
        setBalance(balance);
     
        setAccountID();
        
    }
    string BankAccount::getType(){return type;}
    void BankAccount::setType(string type){this->type=type;}
    void BankAccount::setAccountID(){
    
    string temp1 ="FCAI-";
    string temp2=to_string((cvec.size()/6)+1);
    this->accountID=temp1+temp2;
    cvec.push_back(this->accountID);
    
    }
    string BankAccount::getAccountID(){
        
        return accountID;
        }
    void BankAccount::setBalance(string balance){this->balance=balance;
    cvec.push_back(balance);
    }
    string BankAccount::getBalance(){return balance;}
    void BankAccount::withdraw(){
        cout << "valid id, please enter the amount of moeny: ";
        double amount;
        cin >> amount;
        stringstream ss;
        double money;
        ss << cvec[index - 1];
        ss >> money;
        if(money >= amount){
            cvec[index - 1] = to_string(money - amount);
            cout << "your new balance is: " << cvec[index - 1] << endl;
        }
        else{
        cout << "your balance is not enough.\n";
    }
}
    void BankAccount::deposit(){
       cout << "valid id, please enter the amount of moeny: ";
        double amount;
        cin >> amount;
        stringstream ss;
        double money;
        ss << cvec[index - 1];
        ss >> money;

        cvec[index - 1] = to_string(money + amount);
        cout << "your new balance is: " << cvec[index - 1] << endl;
        
    }
     SavingsBankAccount::SavingsBankAccount(){
        minimunBalance=1000;
    }
    SavingsBankAccount::SavingsBankAccount(string balance){
       
             if(stoi(balance)>=1000){
        setBalance(balance);
        }
        else{
            cout<<"invaild initial balance amount"<<endl;
            exit(1);
        }
        setAccountID();
    }
   
    void SavingsBankAccount::withdraw(){
        cout << "valid id, please enter the amount of moeny: ";
        double amount;
        cin >> amount;
        stringstream ss;
        double money;
        ss << cvec[index - 1];
        ss >> money;
        if(money - amount >= 1000){
            cvec[index - 1] = to_string(money - amount);
            cout << "your new balance is: " << cvec[index - 1] << endl;
        }
        else{
        cout << "you cant withdraw this amount of money, because your balance will be less than 1000.\n";
    }
        }
    
    void SavingsBankAccount::deposit(){
        cout << "valid id, please enter the amount of moeny: ";
        double amount;
        cin >> amount;
        if (amount >= 100){
             stringstream ss;
        double money;
        ss << cvec[index - 1];
        ss >> money;

        cvec[index - 1] = to_string(money + amount);
        cout << "your new balance is: " << cvec[index - 1] << endl;
        
        }
        else{
            cout<<"you cant deposit less than 100"<<endl;
        }
       
    }