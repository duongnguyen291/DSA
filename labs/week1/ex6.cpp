//Problem: Chapter 1 - Black Column
#include <bits/stdc++.h>
using namespace std;
int main(){
    int row, column, count = 0, check;
    cin >> row >> column;
    int matrix[row][column];
    for(int i = 0; i < row ; i++){
        for(int j = 0; j < column ;j ++){
            cin >> matrix[i][j];
        }
            cout << endl;
    }
    for(int j = 0; j < column ;j++){
        check = 1;
        for(int i = 0; i < row ;i++){
            if(matrix[i][j] == 0){
                check*=0;
            }
        }
        count+=check;
    }
    cout << check;
    return 0;
}