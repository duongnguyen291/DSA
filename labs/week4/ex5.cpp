//Problem: Chapter 2 - Linear Integer Equation - coefficent 1
#include <bits/stdc++.h> 
using namespace std;
int a[50],n,m;
void sol(int p, int sum){
    if(p == n){
        for(int i = 1; i < n;i++) cout << a[i] << " ";
        cout << m - sum << " "<<  endl;
        return;
    }
    for(int i = 1;i <= m - sum - (n - p); i++){
        a[p] = i;
        sol(p+1,sum+i);
    }
}

int main(){ 
    cin >> n >> m;
    sol(1,0);
    return 0;   
}