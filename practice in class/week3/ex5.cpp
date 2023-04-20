//Check xem string có đối xứng không, ví dụ: NOON, DEED, MADAM,..
//gọi là palindrime
#include <bits/stdc++.h>
using namespace std;

int palindrome(string s, int n, int k){
    if(n >= k) return 1;
    else{
        if(s[n] == s[k]){
            return palindrome(s,n+1,k - 1);
        }
        else return 0;
    }
}


int main(){
    string s;
    cin >> s;
    cout << palindrome(s,0,s.size() - 1);
    return 0;
}   