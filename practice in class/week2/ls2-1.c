/*given a list of prices of a single stock for 
N number of days, find stockspan for each day. 
Stock span is defined as a number of consecutive 
days prior to the current day when the price of
a stock span was less than or equal to the price 
at current day
*/
#include <stdio.h>
int main(){
    int a[7] = {100,60,70,65, 82, 85, 90};
    int sspan[7]={0};
    for(int i = 0; i < 7; i++){
        for(int j = i - 1 ; j >= 0; j -- ){
            if(a[j] <= a[i]){
                sspan[i]++;
            }
            else break;
        }
    }
    int max = sspan[0];
    for(int i = 0 ; i < 7;i++){
        if(max < sspan[i]) max = sspan[i];
    }
    for(int i = 0;i < 7;i++){
        printf("\nThe %d value: %d", i+1 , sspan[i]);
    }
    printf("\nThe max value of sspan: %d", max);
    return 0;
}