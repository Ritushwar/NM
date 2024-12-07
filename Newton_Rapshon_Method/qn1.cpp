// Find the root of the equation xsinx + cosx = 0 using Newton Rapshon Method.
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
double f(double x){
    double result;
    result = x*sin(x) + cos(x);
    return result;
}
double der_f(double x){
    double res;
    res = x * cos(x);
    return res;
}
int main(){
    double x0, fx0, der_fx0, x1, err;
    cout<<"Enter the initial guess:"<<endl;
    cout<<"x0: ";
    cin>>x0;
    cout<<"Accuracy: ";
    cin>>err;
    fx0 = f(x0);
    der_fx0 = der_f(x0);
    x1 = x0 - (fx0/der_fx0);

    /*cout<<"fx0: "<<fx0<<endl;
    cout<<"Der fx0: "<<der_fx0<<endl;
    cout<<"x1: "<<x1<<endl;  */
    while(fabs(x1-x0)>err){
        x0 = x1;
        fx0 = f(x0);
        der_fx0 = der_f(x0);
        x1 = x0 - (fx0/der_fx0);
        /* cout<<"fx0: "<<fx0<<endl;
        cout<<"Der fx0: "<<der_fx0<<endl;
        cout<<"x1: "<<x1<<endl;  */
    }
// required root is x1
cout<<"Required root is: "<<x1<<endl;
return 0;
}