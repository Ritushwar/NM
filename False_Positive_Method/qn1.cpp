// Find the root of the equation of x^3 - 4x^2 + x + 6 = 0. Correct upto two decimal place
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
double f(double x){
    double result;
    result = pow(x,3) - 4*pow(x,2) + x + 6;
    return result;
}
int main(){
    double xn1=0;
    double a, b, x1, x2, xn2, fx1, fx2, err, den, num;
    label:
    cout<<"Enter the initial guess"<<endl;
    cout<<"x1: ";
    cin>>x1;
    cout<<"x2: ";
    cin>>x2;
    cout<<"Precision: ";
    cin>>err;
    if(f(x1)*f(x2)>0){
        goto label;
    }
    else{
        if(f(x1)<0){
            a = x1;
            b = x2;
        }
        else{
            a = x2;
            b = x1;
        }
        // Calculating xn
        num = a*f(b) - b*f(a);
        den = f(b) - f(a);
        xn2 = num / den;
        if(f(xn2)>0){
            b = xn2;
        }
        else{
            a = xn2;
        }
        while(fabs(xn1-xn2)>=err){
            xn1 = xn2;
            num = a*f(b) - b*f(a);
            den = f(b) - f(a);
            xn2 = num / den;
            if(f(xn2)>0){
                b = xn2;
            }
            else{
                a = xn2;   
        }
    }
}
  // root is xn
  cout<<" Required root is: "<<xn2<<endl;
  return 0;
}