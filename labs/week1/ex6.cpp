//Problem: Chapter 1 - Black Column
#include <bits/stdc++.h>
using namespace std;
int main(){
    int row, column;
    cin >> row >> column;
    int matrix[row][column];
    for(int i = 0; i < row ; i++){
        for(int j = 0; j < column ;j ++){
            cin >> matrix[i][j];
        }
            cout << endl;
    }
    int count = 0;
    int check;
    for(int j = 0; j < column ;j++){
        check = 1;
        for(int i = 0; i < row ;i++){
            if(matrix[i][j] == 0){
                check*=0;
            }
        }
        count+=check;
    }
    cout << count;
    return 0;
}