#include "roots.hpp"
#include <cmath>

using namespace std;

//Bisection method
bool bisection(std::function<double(double)> f,
               double a, double b,
               double *root)
{
double estimate = 0.0;

do{
*root = estimate;
if(f(a) * f(b) >= 0){
    return false;
}
else{
    estimate = ((a+b)/2);
    if(f(estimate) < 0){
        a = estimate;
    }
    else{
        b = estimate;
    }
}
}while(abs(f(*root)-f(estimate)) >= 0.000001);
return true;
}

//Regula Falsi method
bool regula_falsi(std::function<double(double)> f,
                  double a, double b,
                  double *root)
                  {
double estimate = 0.0;
*root = 0.0;

if((f(a)*f(b)) >= 0){
    return false;
}
else{
    do{
        *root = estimate;
        estimate = a - ((f(a)*(b - a))/(f(b)-f(a)));
        if(f(estimate) < 0){
            a = estimate;
        }
        else{
            b = estimate;
        }
    }while(abs(f(*root)-f(estimate)) >= 0.000001);
}
return true;
                  }

//Newton Raphson method
bool newton_raphson(std::function<double(double)> f,
                    std::function<double(double)> g,
                    double a, double b, double c,
                    double *root){
*root = 0.0;

if((f(a)*f(b)) <= 0 && c > a && c < b){
    do{
    *root = c;
    c = c - (f(c)/g(c));
    }while(abs(f(*root)-f(c)) >= 0.000001);
}
else{
    return false;
}
return true;
                    }

//Secant method
bool secant(std::function<double(double)> f,
            double a, double b, double c,
            double *root){

double c_0 = c+1;
double estimate = 0.0;
*root = 0.0;

if( c > a && c < b){
    do{
    {
        *root = estimate;
        estimate = c - f(c)*((c-c_0)/(f(c)-f(c_0)));
        c_0 = c;
        c = estimate;
    }
    }while(abs(f(*root)-f(c)) >= 0.000001);
}
else{
    return false;
}
return true;
            }