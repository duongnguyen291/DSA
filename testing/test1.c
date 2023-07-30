#include <stdio.h>
int ham2(int n){
    int i,j,S = 0;
    for(i=0;i< n;i++)
        for(j=n;j>0;j/=2)
        S++;// Cãu lệnh cần đếm
    return S;
}

int main(){
    // int A[3][3] = {1,2,3,4,5,6,7,8,9};
    // for(int i = 0;i < 3;i++){
    //     for(int j = 0; j < 3;j++){
    //         printf("A[%d][%d] = %d\n", i,j,A[i][j]);
    //     }
    // }
    // int temp = ham2(10);
    int a[5] = {5,3,2,1,4};
    int temp = cal(a,5);
    printf("%d",temp);
    return 0;
}