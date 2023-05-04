//đặt quân hậu

#include <bits/stdc++.h>
using namespace std;

#define N 100
int n;
int a[N];
int cnt = 0;
void printSol(){
    cnt++;
    for(int i = 1;i <= n;i++){
        cout << " (row = " << i << " column = " << a[i] << ") ";
    }
    cout << endl;
}
int check(int k, int j) {
    for(int i = 1; i < k;i++){
        if(a[i] == j || abs(a[i] - j ) == abs(i - k) ) return 0;
    }
    return 1;
}

// Thuật toán quay lui để đặt quân hậu vào bàn cờ
void Try(int k){
    for(int j = 1;j <= n;j++){
        //check queen is placed at (row j, column k)
        if(check(k,j)){
            a[k] = j;
        if(k == n) printSol();
        else Try(k+1);
        }
    }
}


int main() {
    cin >> n ;
    Try(1);
    if(cnt == 0) cout << "No Solution";
    return 0;
}
