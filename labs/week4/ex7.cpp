//Problem: Chap2 - Count Queen Solutions with some specified queens
#include <bits/stdc++.h> 
using namespace std;
int n, k, r, c;
int main(){
    cin >> n >> k;
    int arr[n+5][n+5];
    for(int i = 1 ; i <= k; i++){
        cin >> c >> r;
        arr[c][r] = 1;
    }
    for(int i = 1; i <= n; i++){

    }
    return 0;
}