//Problem: Chapter 2 - Permutation generation
#include <bits/stdc++.h>
using namespace std;
bool  check[100];
int hoanvi[100];
void printHoanVi(int hoanVi[100], int n){
    for(int i = 0; i <= n; i++){
        cout << hoanvi[n];
    }
    cout << endl;
}
void timHoanVi(int k, int n){
for(int i = 1; i <= n;i ++){
    if(check[i]){
        hoanvi[k] = i;
        if(k == n){
            printHoanVi(hoanvi, n);
        }
        else{
            check[i] = false;
            timHoanVi(k + 1,n);
            check[i] = true;
        }
    }

}

}
int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n ;i ++){
        check[i] = true;
    }
    timHoanVi(1,n);
    return 0;
}