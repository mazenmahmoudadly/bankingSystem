#include<bits/stdc++.h>
using namespace std;
class Process{
protected:    
    int PID;
    string name;
    int memory;
    string Session_Name;
    int SessionNum;
  
public:
    Process(){
        name="";
        PID=0;
        memory=0;
        Session_Name="";
        SessionNum=0;
    }
    Process(string name,int PID,int memory,string Session_Name,int SessionNum){
        this->name=name;
        this->PID=PID;
        this->memory=memory;
        this->Session_Name=Session_Name;
        this->SessionNum=SessionNum;
    }
    string getName(){return name;}
    int getPID(){return PID;}
    int getMemory(){return memory;}
    string getSession_Name(){return Session_Name;}
    int getSessionNum(){return SessionNum;}
   void setName(string name){this->name=name;}
    void setPID(int PID){this->PID=PID;}
    void setMemory(int memory){this->memory=memory;}
    void setSession_Name(string Session_Name){this->Session_Name=Session_Name;}
    void setSessionNum(int SessionNum){this->SessionNum=SessionNum;}

};
class TaskManager{
protected:
    vector<Process>pList;
public:
    void AddProcess(Process p){pList.push_back(p);}
    void print(){
            cout<<"Image Name                     PID Session Name        Session#    Mem Usage"<<endl;
            cout<<"========================= ======== ================ =========== ============"<<endl;
        for(auto p : pList){
            cout<<left<<setw(25)<<p.getName()<<" ";
            cout<<right<<setw(8)<<p.getPID()<<" ";
            cout<<left<<setw(16)<<p.getSession_Name()<<" ";
            cout<<right<<setw(11)<<p.getSessionNum()<<" ";
            cout<<right<<setw(12)<<p.getMemory()<<"K"<<" ";
            cout<<endl;
        }
    }
    void sort_by_name(){
        sort(pList.begin(),pList.end(),[](Process a, Process b){return a.getName()<b.getName();});
    }
    void sort_by_PID(){
        sort(pList.begin(),pList.end(),[](Process a, Process b){return a.getPID()<b.getPID();});


    }
    void sort_by_usage(){
        sort(pList.begin(),pList.end(),[](Process a, Process b){return a.getMemory()<b.getMemory();});

    }
    void get_process(){
        ifstream file;
        file.open("Tasklist.txt",ios::in);
        file.seekg(4);
        const auto StreamMax = std::numeric_limits<std::streamsize>::max();
        if(!file){
            cout<<"error while opening file";
        }
        else{
            string line;
            
    for( int i = 0; i < 2; ++i ){
        file.ignore( StreamMax, '\n' );}
            while (getline(file,line))
            {

            Process p;

            string name=line.substr(0,24);

                int l = name.length(); 
                int c= count(name.begin(), name.end(),' '); 
                remove(name.begin(), name.end(),' '); 
                name.resize(l - c);

            string num=line.substr(26,33);

                int r = num.length(); 
                int a= count(num.begin(), num.end(),' '); 
                remove(num.begin(), num.end(),' '); 
                num.resize(r - a);
                int PID;
                PID=convert(num);

            string SessionName=line.substr(34,46);

                int s = SessionName.length(); 
                int z= count(SessionName.begin(), SessionName.end(),' '); 
                remove(SessionName.begin(), SessionName.end(),' '); 
                remove(SessionName.begin(), SessionName.end(),','); 
                remove(SessionName.begin(), SessionName.end(),'K'); 
                SessionName.resize(s - z);

            string Snum=line.substr(51,63);

                int k = Snum.length(); 
                int o= count(Snum.begin(), Snum.end(),' '); 
                remove(Snum.begin(), Snum.end(),' '); 
                Snum.resize(k - o);          
                int SessionNum;
                SessionNum=convert(Snum);

            string memory=line.substr(65,75);

                int b = memory.length(); 
                int d= count(memory.begin(), memory.end(),' '); 
                remove(memory.begin(), memory.end(),' '); 
                remove(memory.begin(), memory.end(),'K'); 
                memory.resize(b - d);
            int mem;
            mem=convert(memory);

          p.setName(name);
          p.setPID(PID);
          p.setMemory(mem);
          p.setSessionNum(SessionNum);
          p.setSession_Name(removeNumbers(SessionName));
        AddProcess(p);
                
            }
            
        }
    }
    void save(){
        ofstream file;
        file.open("Tasklist.txt",ios::out);
        file.close();
        
        system("tasklist >> Tasklist.txt");
   
        
    }
int convert(string s) 
{ 
   
      stringstream degree(s);

    int x = 0;
    degree >> x;
  
    return x; 
}
string removeNumbers(string str)
{
    int current = 0;
    for(int i = 0; i< str.length(); i++){
        if(!isdigit(str[i])){
            str[current] = str[i];
            current++;
        }
    }

    return str.substr(0,current);
}

};


int main(){
TaskManager t;
int choice;

cout<<"1-sorted by names"<<endl;
cout<<"2-sorted by PID"<<endl;
cout<<"3-sorted by usage"<<endl;
cout<<"enter your choice: "<<endl;
cin>>choice;
switch (choice)
{
case 1:
    t.save();
    t.get_process();
    t.sort_by_name();
    t.print();
    break;
case 2:
    t.save();
    t.get_process();
    t.sort_by_PID();
    t.print();
    break;
case 3:
    t.save();
    t.get_process();
    t.sort_by_usage();
    t.print();

    break;
default:
    break;
}

}