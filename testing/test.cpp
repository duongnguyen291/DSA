#include <bits/stdc++.h>
using namespace std;
int main(){ 
    int a,b,c,d; 
    int i=0; 
    for (a=1;a<60;a++){ 
        for(b=1;b<60;b++){ 
            for(c=1;c<60;c++){ 
                for(d=1;d<60;d++){ 
                    if((2*a+ 4*b + 3*c + 5*d == 60)&&(a+b==6))
                    { i++; 
                    cout <<i<<"."<<a<<" "<<b<<" "<<c<<" "<< d<<endl; 
                    } 
                    } 
            }
        } 
    } 
}
