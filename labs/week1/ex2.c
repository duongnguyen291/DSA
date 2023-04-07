#include<stdio.h>
int main(){
    int i,a[10];
    printf("\nPlease enter 10 numbers: ");
    for(i = 0; i < 10; i++){
        scanf("%d",&a[i]);
    }
    printf("\nNumber in reversed order: \n");
    for(i = 9; i >= 0;i--){
        printf("%d\n",a[i]);
    }
    int maxD = a[0]; 
    int minD = a[0];
    int avg = a[0];
    for(int i = 1; i <=9;i++){
        if(maxD < a[i]) maxD = a[i];
        if(minD > a[i]) minD = a[i];
        avg+=a[i];
    }
    printf("\nMax value is: %d",maxD);
    printf("\nMin value is: %d",minD);
    printf("\nAve value is: %d",avg/10);
    return 0;
}