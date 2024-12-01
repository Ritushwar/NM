// Find the root of equation of X^3 - 2.5*X^2 - 2.46*X + 3.96
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
double f(double X){
    double result = pow(X, 3) - 2.5*pow(X, 2) - 2.4*pow(X,1) + 3.96;
    return result;
}

int main(){
    cout.precision(5);
    cout.setf(ios::fixed);
    double a, b, c, e, fa, fb, fc;  // declare the required variable
    back:
    cout<<"Enter the initial guess:\na=";
    cin>>a;
    cout<<"\nb=";
    cin>>b;
    cout<<"Enter the degree of accuracy desired"<<endl;
    cin>>e;
    if (f(a)*f(b)>0){
        cout<<"Please enter a different initial guess"<<endl;
        goto back;
    }
    else{
        while(abs(a-b)>=e){
            c = (a+b)/2;
            fa = f(a);
            fb = f(b);
            fc = f(c);

            if(fc==0){
                cout<<"Required root is: "<<c<<endl;
                return 0;
            }
            if(fa*fc>0){   // no root exist between a and c
              a = c;
            }
            if(fa*fc<0){   // then the root exist between a and c
               b = c;
            }
        }
        cout<<"Required root is: "<<c<<endl;
    }
    return 0;
}