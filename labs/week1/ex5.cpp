#include <bits/stdc++.h>
#include <cstring>
using namespace std;
int check(int i, string a, string b, string c){
    if(i + a.size() > c.size()) return 0;
    for(int k = 0; k < a.size() ; k++){
        if(a[k] != c[k+i] ) return 0;
    }
    return 1;
}
int main(){
    string a,b,c,temp;
    getline(cin,a);
    getline(cin,b);
    getline(cin,c);
    for(int i = 0; i < c.size(); i++){
        if(check(i,a,b,c)){
            temp+=b;
            i += a.size() - 1;
        }
        else {
            temp+= c[i];         
        }
    }
    cout << temp;
    return 0;
}