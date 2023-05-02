//Problem: Chapter 2 - Binary sequences generation without consecutive 11
#include <bits/stdc++.h>
using namespace std;
void binary(string s, int n){
    if(n == 0) cout << s << endl;
    else if(s[s.size() - 1] == '1') binary(s + "0", n - 1);
    else{
        binary(s + "0", n - 1);
        binary(s + "1", n - 1);
    }

}

int main(){
    int n;
    cin >> n;
    binary("",n);
    return 0;
}