#include <bits/stdc++.h>
using namespace std;
int helperSum(int *a, int k){
    if(k == 0) return a[0];
    else return a[k] + helperSum(a, (k - 1));
}
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0 ;i < n;i ++){
        cin >> a[i];
    }    
    cout << helperSum(a, n - 1);
    return 0;
}