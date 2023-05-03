#include <bits/stdc++.h>
using namespace std;

#define N 25
#define M 25

int n, k, r, c;
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

// Kiểm tra xem quân hậu đặt ở hàng i và cột j có bị tấn công bởi
// một quân hậu nào khác hay không
int check(int i, int j) {
    a[i][j] = 1;
    if(check_column(n)&&check_row(n)&&check_dia(n)) return 1;    
    else {
        a[i][j] = 0;
        return 0;
    }
}

// Thuật toán quay lui để đặt quân hậu vào bàn cờ
int solve(int i) {
    if (i > n) {
        return 1;
    }
    int count = 0;
    for (int j = 1; j <= n; j++) {
        if (!a[i][j] && check(i, j)){
            a[i][j] = 1;
            count += solve(i+1);
            a[i][j] = 0;
        }
    }
    return count;
}


int main() {
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        cin >> r >> c;
        a[r][c] = 1;
    }
    cout << solve(1) << endl;
    return 0;
}
