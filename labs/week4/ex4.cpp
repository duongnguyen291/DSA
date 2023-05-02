//Problem: Chapter 1 - Solve degree-2 polynomial equation
/*  Given an equation ax^2 + bx + c = 0. Find solution to the given equation.
Input
Line 1 contains 3 positive integers a, b, c 
Output
Write NO SOLUTION if the given equation has no solution 
Write x0 (2 digits after the decimal point) if the given equation has one solution x0 
Write x1 and x2 with x1 < x2 (2 digits after the decimal point) if the given equation 
has two distinct solutions x1, x2 */
#include <bits/stdc++.h> 
using namespace std;

double a,b,c,x1,x2;
int main(){
    double denta;
    cin >> a >> b >> c;
    denta = b*b - 4*a*c;
    if(denta < 0 ) cout << "NO SOLUTION";
    else if(denta == 0){
        x1 = - b / 2*a;
        printf("%.2lf", x1);
    }
    else if(denta > 0) {
        x1 = (- b - sqrt(denta)) / 2*a;
        x2 = (- b + sqrt(denta)) / 2*a;
        printf("%.2lf %.2lf",x1,x2);
    }
    return 0;
}