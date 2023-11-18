#include <stdio.h>
#include <math.h>
int main(){
    double money;
    scanf("%lf",&money);
    
    printf("Check %lf \n", money );
    if(money > 50000000){
        printf("%.0lf", money * 0.08 );
    }
    else if(money >  25000000 && money < 50000000){
        printf("%.0lf", money * 0.05 );
    }
    else if(money >  10000000 && money < 25000000){
        printf("%.0lf", money * 0.02 );
    }
    else  printf("%.0lf", money);
    return 0;
}