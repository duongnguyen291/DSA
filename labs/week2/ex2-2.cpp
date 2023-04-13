//Problem: Chapter 1 - Array Equality
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int a,b;
    cin >> n;
    int arr[1000],brr[1000];
    int count[1000];
    for(int i = 0; i < n ;i++){
        //input data
        cin >> a >> b;
        for(int j = 0 ; j < a; j++){
            cin >> arr[j];
        }
        for(int j = 0; j < b;j++){
            cin >> brr[j];
        }
        //compare the two array
        if(a != b){
            count[i] = 0;
        }
        else{
            for(int j = 0; j < a; j++){
                if(arr[j] == brr[j]) count[i] = 1;
                else{
                    count[i] = 0;
                    break;
                }
            }
        }
    }
    for(int i = 0;i < n; i++){
        cout << count[i] << endl;
    }

    return 0;
}