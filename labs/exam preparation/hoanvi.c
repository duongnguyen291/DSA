#include <stdio.h>
#define size 1000
int a[size];
int n;
void printSol(){
    for(int j = 1;j <=n;j++){
        printf("%d ", a[j]);
    }
    printf("\n");
}
int check(int *a, int i){
    for(int j = 1;j <=n;j++){
        if(a[j] == i) return 0;
    }
    return 1;
}
void Try(int k){
    for(int i = 1;i <=n ;i++){
        if(check(a,i)){
            a[k] = i;
            if(k == n) 
                printSol();
            else Try(k+1);
        }
        a[k] = 0;
    }
}

int main(){
    scanf("%d",&n);
    Try(1);
    return 0;
}