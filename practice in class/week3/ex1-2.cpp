//fibonaci
#include <bits/stdc++.h>
using namespace std;
long long f1(int n){
    if(n == 0||n == 1) return n;
    else
    return f1(n - 1) + f1(n - 2);
}
int f2(int n){
    int x,y;
    x = 0;
    y = 1;
    if(n < 2) return n;
    for(int i = 2 ;i  <= n ;i ++ ){
            y = x + y;
            x = y - x; 
    }   
    return y;
}
int main(){
    int n;
    cin >> n;
    cout << f1(n) << endl;
    cout << f2(n);
    return 0;
}