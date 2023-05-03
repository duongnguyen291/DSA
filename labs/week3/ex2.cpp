//Tính số dãy (dãy dương) con trong dãy có tổng bằng sum
#include<bits/stdc++.h>
using namespace std ;
int Solve(int a[],int n , int sum){
    if(n == 0) return 0;
    else if(a[n] == sum) return 1 + Solve(a, n - 1, sum);
    else if(a[n] > sum ) return Solve(a, n - 1, sum);
    return Solve(a,n-1, sum - a[n]) + solve(a, n - 1, sum);
}
int main()
{
    int n ;
    cin >> n ;
    int a[n+5] ;
    for(int i = 1 ;i <= n ; i++) cin >> a[i] ;
    int sum ;
    cin >> sum ;
    cout << Solve(a,n,sum) ;
    return 0 ;
}