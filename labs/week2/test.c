#include <stdio.h>
#include <math.h>

void split(double num, int *int_part, double *frac_part){
    *int_part = (int)num;
    *frac_part = num - *int_part;
    printf("\nThe int part is: %d ", *int_part);
    printf("\nThe frac part is: %lf ", *frac_part);
}
void change(int a[], int size){
    for(int i = 0; i < size; i++){
        printf("\n%d", a[i]*2);
    }
}
int main(){
    int a[5] = {5,10,12,15,4};
    // printf("Address    Content\n");
    // for(int i = 0 ;i < 5;i++){
    //     printf("%d      %d \n", &A[i], A[i]);
    // }
    double n;
    double b;
    // printf("\nEnter number: ");
    // scanf("%lf", &n);
    // split(n,&a,&b);
    for(int i = 0 ;i < 5;i ++){
        printf("%d ", a[i]);
    }
    change(a,5);
    for(int i = 0 ;i < 5;i ++){
        printf("%d ", a[i]);
    }
    return 0;

}