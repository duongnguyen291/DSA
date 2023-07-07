/*Problem: Dynamic programming. Money exchange problem
Description

Given a set of n coins (n <=10) of denominations d0,d1,..dn-1 and value X (X <=100000).
Find the minimum number of coins to exchange for value of X.
Input:
- The first line contains 2 positive interger numbers: n  and X
- The second line contains n positive interger numbers: d0,d1,..dn-1
Output:
- The minimum number of coins to exchange for value of X using the given set coins. 
In case there does not exist to echange, print -1*/
#include <bits/stdc++.h>
using namespace std;
int d[15];
int INF = 9999999;
int mem[10][10000];// kiểm tra bài toán con đã giải chưa
int OPT(int i, int x){
    //1.Base case
    if(x == 0) return 0;
    if(i < 0) return INF;
    if(x<0) return INF;
    //2.Check if the problem has been solved
    if(mem[i][x]!=-1) return mem[i][x];
    //3.Solve the problem 
    int res;
    if(x>=d[i])
        res = min(1 + OPT(i,x - d[i]), OPT(i-1,x));
    else 
        res = OPT(i-1,x);
    mem[i][x] = res;
    return res;
}
int main(){
    int n,X;
    freopen("test1.txt","r",stdin);
    cin >> n >> X;
    for(int i = 0;i < n;i++){
        cin >> d[i];
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<=X;j++){
            mem[i][j] = -1;
        }
    } // set toàn bộ phần tử mem có giá trị -1 
    int res = OPT(n - 1, X);

    if (res == INF)
        cout << -1;
    else
        cout << res;
    return 0;
}