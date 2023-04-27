#include <bits/stdc++.h>
using namespace std;
const int a = 1000,b = 1000;
int d[a][b];
int Try(int n, int k){
if(k == 0 || k == n) return 1;
else{
    if(d[n][k] > 0){
        return d[n][k];
    }
    else{
        d[n][k] = Try(n-1,k-1) + Try(n-1,k);
        return d[n][k];
    }
}
}
int main(){
    int n,k;
    cin >> n >> k;
    cout << Try(n,k);
    return 0;
}