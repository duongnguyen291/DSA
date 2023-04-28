//Problem: Chap 1- Check Queen solution
#include <bits/stdc++.h>
using namespace std;
#define N 110
#define M 110
int a[N][M];
int check_row(int m){
    //return 1 if not same column/row
    //otherwise return 0;
    int sum;
    for(int i = 0;i < m; i++){
        sum = 0;
        for(int j = 0; j < m; j++ ){
            sum += a[i][j];
        }
        if(sum > 1) return 0;
    }
    return 0;
    
}
int main(){
int count[N]= {0};
    int n,m;
    int sameRow;
    int sum_row;
    freopen("test3.txt","r",stdin);
    cin >> n ;
    while(n--){
        cin >> m;
        for(int i = 0; i < m; i++){
            for(int j = 0;j < m; j++){
                cin >> a[i][j];
            }
        }
        //finish reading

    }
    



    return 0;
}