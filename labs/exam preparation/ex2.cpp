//Problem: Chapter 2 - Check Sudoku
#include <bits/stdc++.h>
using namespace std;
int a[14][14];
int cnt;
int check(int a[14][14]){
    int sumRow = 0, sumColumn = 0 , sumDia = 0;
    //check row
    for(int i = 1; i<=9;i++){
        sumRow = 0;
        for(int j = 1;j <=9;j++){
            sumRow+=a[i][j];
        }
        if(sumRow != 45) return 0;
    }
    //check column
    for(int i = 1; i<=9;i++){
        sumColumn = 0;
        for(int j = 1;j <=9;j++){
            sumColumn+=a[j][i];
        }
        if(sumColumn != 45) return 0;
    }        
    //check dia 
    for(int i = 1;i <= 9;i+=3){
        for(int j = 1;j <=9;j+=3){
            //set ở đầu các ô 9
            sumDia = 0;
            for(int r = i;r <= i+2; r++){
                for(int c = j; c<=j+2;c++){
                    sumDia +=a[r][c];
                }
            }
            if(sumDia !=45) return 0;
        }
    }
    return 1;
}

int main(){ 
    int n;
    freopen("test2.txt", "r",stdin);
    cin >> n;
    for(int k = 1;k <=n;k++){
        for(int i=1;i<=9;i++){
            for(int j=1;j<=9;j++){
                cin >> a[i][j];
            }
        }
        cnt = check(a);
        if(cnt == 1) 
            cout << 1 << endl;
        else 
            cout << 0 << endl;
    }
    return 0;
}