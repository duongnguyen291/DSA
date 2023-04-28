//sinh hoán vị
#include <bits/stdc++.h>
using namespace std;
int n;
int a[100];
void printsol(){
    for(int i = 1; i <= n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}
int check(int i, int k){
    for(int j = 1; j < k ; j++){
        if(a[j] == i) return 0;
    }
    return 1;
}
void Try(int k){
    for(int i = 1; i <= n; i++ ){
        if(check(i,k)){
            a[k] = i;
            if(k == n) printsol();
            else Try(k+1);
        }
    }
}
int main(){
    cin >> n;
    Try(1);
    return 0;
}