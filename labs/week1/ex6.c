//Problem: Chapter 1 - Black Column
#include <stdio.h>
int main(){
    int row,column;
    scanf("%d %d", &row, &column);
    int matrix[row][column];
    for(int i = 0; i < row ; i++){
        for(int j = 0; j < column ;j ++){
            scanf("%d", &matrix[i][j]);
        }
        printf("\n");
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
    printf("%d",count);
}