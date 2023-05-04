//sinh hoán vị n
#include <bits/stdc++.h>
using namespace std;
#define N 50
int a[N], use[N];
int n;  
void printSol(){
    for(int i = 1;i <= n;i++) cout << a[i] << " ";
    cout << endl;
}


void Try1(int k){
    for(int y = 1; y <= n;y++){
        if(!use[y]){
            a[k] = y;
            use[y] = 1;
            if(k == n) printSol();
            else Try1(k + 1);
            use[y] = 0;
        }
    }
}

int main(){
    cin >> n;
    Try1(1);

    return 0;
}