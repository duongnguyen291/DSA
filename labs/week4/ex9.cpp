//Problem: Chap 2. K-combination sum is equal to m
#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int a[25];
int cnt = 0;
void sol(int p, int cur_k,int sum){
if(cur_k == 0 && sum == m){
    cnt++;
    return;
}
if(p >= n || cur_k <= 0 || sum > m ) return;
//thành phần của dãy không có phần tử a[p]
sol(p + 1, cur_k,sum);
//thành phần của dãy có chứa phần tử a[p]
sol(p + 1, cur_k - 1, sum + a[p]);
    
}

int main(){
    cin >> n >> k >> m;
    for(int i = 0; i < n;i++){
        cin >> a[i];
    }
    sort(a,a+ n);
    sol(0,k,0);
    cout << cnt << endl;
    return 0;
}