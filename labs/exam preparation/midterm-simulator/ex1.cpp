//Problem: Chapter 2 - Count sudoku
#include <bits/stdc++.h>
using namespace std;
int a[14][14];
int cnt;
int check(int n, int r, int c){
    //check row (column change)
    for(int i=1;i<=9;i++){
        if(a[r][i] == n) return 0;
    }
    //check column
    for(int i = 1;i<=9;i++){
        if(a[i][c] == n) return 0;
    }
    //check dia
    if (c % 3 == 0)
        c = (c - 3);
    else
        c = c - (c % 3);
    if (r % 3 == 0)
        r = r - 3;
    else
        r = r - (r % 3);
    for (int i = r + 1; i <= r + 3; i++)
        for (int j = c + 1; j <= c + 3; j++)
            if (a[i][j] == n)
                return 0;
    return 1;
}
void Try(int r,int c){
    if(a[r][c]!=0){
        if(c==9 && r ==9) cnt++;
        else if(c==9 && r!=9) Try(r+1,1);
        else Try(r,c+1);
    }
    else{
        for(int i = 1;i <= 9;i++){
            if(check(i,r,c)){
                a[r][c] = i;
                if(c==9 && r ==9) 
                    cnt++;
                else if(c == 9 && r !=9) 
                    Try(r+1,1);
                else 
                    Try(r,c+1);
                a[r][c] = 0;
            }
        }
    }
}
int main(){ 
    freopen("test1.txt", "r",stdin);
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            cin >> a[i][j];
        }
    }
    Try(1,1);
    cout << cnt;
    return 0;
}