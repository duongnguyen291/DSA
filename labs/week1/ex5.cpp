#include <bits/stdc++.h>
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
    cout << a;
    int k = 0;
    for(int i = 0; i < c.size(); i++){
        if(check(i,a,b,c) == 1){
            for(int j = 0 ;j < b.size(); j ++){
                temp[j + k] = b[j];
            }
            k = k + b.size()- 1;
            i += a.size();
        }
        else {
            temp[k] = c[i]; k++;
        }
    }
    cout << temp;
    return 0;
}