//Problem: Chap 1- Check Queen solution
#include <bits/stdc++.h>
using namespace std;
#define N 110
#define M 110
int a[N][M];
int check_row(int m){
    //return 1 if not same row
    //otherwise return 0;
    int sum;
    for(int i = 0;i < m; i++){
        sum = 0;
        for(int j = 0; j < m; j++ ){
            sum += a[i][j];
        }
        if(sum > 1) return 0;
    }
    return 1;
}
int check_column(int m){
    //return 1 if not same column
    //otherwise return 0;
    int sum;
    for(int j = 0; j < m; j++){
            sum = 0;
        for(int i = 0; i < m; i++){
            sum+= a[i][j];
        }
        if(sum > 1) return 0;
    }
    return 1;
}
int check_dia(int m){
    //return 1 if not same dia
    //otherwise return 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == 1){
                //check the dia from left above to righ below
                for(int l = i + 1,  k = j + 1; l < m && k < m; l++,k++){
                    if(a[i][j] == a[l][k]) return 0;
                }
                
                //check the dia from righ above to left below
                for(int l = i - 1,  k = j - 1; l >= 0 && k >= 0; l--, k--){
                    if(a[i][j] == a[l][k]) return 0;
                }               
            }
        }
    }
    return 1;
}
int main(){
int count[N]= {0};
    int n,m;
    int sameRow;
    int sum_row;
    // freopen("test3.txt","r",stdin);
    cin >> n ;
    while(n--){
        cin >> m;
        for(int i = 0; i < m; i++){
            for(int j = 0;j < m; j++){
                cin >> a[i][j];
            }
        }
        //finish reading
        //check the queen 
        // cout << check_column(m) << check_row(m) << check_dia(m) << endl;
        if(check_column(m) && check_row(m) && check_dia(m)) cout << 1 << endl;
        else cout << 0 << endl;
    }
    



    return 0;
}