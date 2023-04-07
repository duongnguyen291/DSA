#include <bits/stdc++.h>
using namespace std;
int main(){
    string c ;
    char a,b;
    cin >> c >> a >> b ;
    for(int i = 0;i < c.size() ;i++){
        if(c[i] == a) c[i] = b;
    }
    cout << c;
    return 0;
}