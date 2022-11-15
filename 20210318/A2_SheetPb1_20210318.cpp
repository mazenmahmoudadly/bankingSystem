#include<bits/stdc++.h>
using namespace std;
class Function{
    virtual double evaluateAt(double value)=0;
        
};
class SimpleFunction:public Function{
    private:
        function<double(double)> fun;
    public:
        SimpleFunction(function<double(double)> fun){
            this->fun=fun;
        }
        double evaluateAt(double value){
            return fun(value);
        }

};
class CompositionFunction:public Function{
    private:
        function<double(double)>f;
        function<double(double)>g;
    public:
        CompositionFunction(function<double(double)>f,
         function<double(double)>g){
          this->f=f;
          this->g=g;      
            
        } 
        double evaluateAt(double value){
            return f(g(value));
        }

};
class DerivativeFunction:public Function{
    private:
        function<double(double)> fun;
        double dx;
    public:
        DerivativeFunction(function<double(double)> fun,double dx){
            this->fun=fun;
            this->dx=dx;
        }
        double evaluateAt(double value){
            double res = (fun(value+dx)-fun(value-dx))/2*dx;
            return res;
        }

};
double cube(double x){
    return x*x*x;
}
double second(double d){
return d*d-5*d-4;
}
double fun(double d){
    return d*d-3*d-4;
}
int main(){
SimpleFunction a(cube);
SimpleFunction b([](double d){return -d;});

cout<<a.evaluateAt(10)<<endl;
// cout<<b.evaluateAt(2)<<endl;
// CompositionFunction c(cube,second);
// cout<<c.evaluateAt(2)<<endl;
DerivativeFunction d(cube,1);
cout<<d.evaluateAt(5);
}