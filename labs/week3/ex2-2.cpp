//Tính số dãy (dãy dương) con trong dãy có tổng bằng sum
#include <bits/stdc++.h>
using namespace std;
int find(int a[], int n, int sum){
    if(n == -1) return 0;
    else if(a[n] == sum ) return 1 + find(a,n-1,sum);
    else if(a[n] > sum ) return find(a,n-1,sum);
    else return find(a,n-1,sum) + find(a,n-1, sum - a[n]); 
}
int main(){
    int n;
    cin >> n;
    int a[n+5];
    for(int i = 0; i < n;i++ ) cin >> a[i];
    int sum;
    cin >> sum;
    cout << find(a,n,sum);

    return 0;
}