#include <bits/stdc++.h>
using namespace std;
int main(){
    int a[7] = {100,60,70,65,82,85,90};
    int sspan[7]= {0};
    for( int i = 0; i < 7; i++){
        for(int j = i - 1; j >= 0; j--){
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
    cout << " The max value is : " << max;



    return 0;
}