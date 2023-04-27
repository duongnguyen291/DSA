#include <bits/stdc++.h>
using namespace std;
void binary(string s, int n){
if(n == 0) cout << s << endl;
else{
    binary(s + '0', n - 1);
    binary(s + '1', n - 1);
}
}
void sol(string s, int n){
    if(n == 0) cout << s << endl;
    else{
        sol(s + '0', n - 1);
        sol(s + '1', n - 1);
    }
}
int main(){
    int n; cin >> n;
    binary("",n);
    return 0;
}