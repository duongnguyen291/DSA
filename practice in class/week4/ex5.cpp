//sinh hoán vị 
#include <bits/stdc++.h> 
using namespace std;
int n,m,count;
int a[100];
void Print(){
    for(int i = 1; i <= m; i++) cout << a[i];
    cout << endl;
}
int check(int y, int k){
    for(int j = 1 ; j <= k - 1;j++)
        if(y == a[j]) return 0;
    return 1;
}
void Try(int k){
for(int i = 1;i <= n;i++){
    if(check(i,k) == 1){
    a[k] = i;
    if(k == m) Print();
    else Try(k+1);
        }
    }
}
int main(){
    cin >> n >> m;
    Try(1);
    return 0;
}