#include <bits/stdc++.h>
using namespace std;
int a[100];int n;
void PrintSol(){
    for(int i = 1;i <= n;i++){
        cout << a[i];
    }
    cout << endl;
}

void bin(int k){
    for(int y = 0; y <= 1;y++){
        a[k] = y;
        if(k == n) PrintSol();
        else bin(k + 1);
    }
}


int main(){
    cout << "Enter n = "; 
    cin >> n;
    bin(1);    
    return 0;
}