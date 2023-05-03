//Problem: Chapter 2 - Generate ways to represent n by sum of k non-decreasing positive integers
#include <bits/stdc++.h> 
using namespace std;
int a[50],n,m;
void sol(int p, int sum){
    if(p == n && (m - sum) >= a[p-1]){
        for(int i = 1; i < n;i++) cout << a[i] << " ";
        cout << m - sum << " "<<  endl;
        return;
    }
    if(p == 1){
    for(int i = 1;i <= m - sum - (n - p); i++){
        a[p] = i;
        sol(p+1,sum+i);
    }
    }
    else{
        for(int i = a[p-1];i <= m - sum - (n - p); i++){
        a[p] = i;
        sol(p+1,sum+i);
    }
    }
}

int main(){ 
    cin >> n >> m;
    sol(1,0);
    return 0;   
}