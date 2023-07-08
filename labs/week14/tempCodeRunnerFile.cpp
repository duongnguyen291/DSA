#include <bits/stdc++.h>
using namespace std;
int T[1000000];
int a[1000000];
int main(){
    int n;
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> T[i];
    }

    T[0] = a[0];
    T[1] = a[1];
    T[2] = a[0] + a[2];
    for(int i = 1; i < n;i++) T[i] = max(T[i-2],T[i-3] + a[i]);
    //kq la phan tu lon nhat trong mang
    int res = -10000;
    for(int i = 0;i<n;i++){
        if(T[i] > res) res = T[i];
    }
    cout << res;
    return 0;
}