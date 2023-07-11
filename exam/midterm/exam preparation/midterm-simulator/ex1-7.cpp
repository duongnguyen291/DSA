#include <bits/stdc++.h>
using namespace std;
#define size 15
int n;
int a[size][size];
int cnt;
int check( int r, int c){
    a[r][c] = 1;
    //check cột
    int sumCol = 0, sumRow= 0;
    //check cột
    for(int i = 1;i<=n;i++){
        sumCol = 0;
        for(int j = 1;j<=n;j++){
            sumCol += a[j][i];
        }
        if(sumCol > 1) return 0;
    }
    //check hàng
    for(int i = 1;i<=n;i++){
        sumRow = 0;
        for(int j = 1;j<=n;j++){
            sumRow += a[i][j];
        }
        if(sumRow > 1) return 0;
    }
    //check hàng chéo
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < n - i; j++) {
            sum += a[j][j + i];
        }
        if (sum > 1) 
        {
            return 0; // Có con hậu chiếu chéo trên đường chéo chính
        }
    }

    // Kiểm tra đường chéo phụ (từ trái dưới đến phải trên)
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < n - i; j++) {
            sum += a[j + i][j];
        }
        if (sum > 1) {
            return 0; // Có con hậu chiếu chéo trên đường chéo phụ
        }
    }
    return 1;
}
void Try(int r, int c){
        if(a[r][c]){
            if(r == n && c == n) {cnt++;}
            else if(c==n) Try(r+1,1);
            else Try(r,c+1); }
        else { 

            if(check(r,c)){//check i thỏa mãn
                a[r][c] = 1;
                 if(r == n && c == n) cnt++;
                else if(c == n) 
                    Try(r+1,1);
                else 
                    Try(r,c+1);
                a[r][c] = 0;
            }
            else if(c == n) 
                Try(r+1,1);
            else 
                Try(r,c+1);
            // if(r == n && c == n) return;

        }
    
}
int main(){
    freopen("test1-7.txt","r",stdin);
    cin >> n;
    for(int i = 1; i <= n;i++){
        for(int j = 1;j<=n;j++){
            cin >> a[i][j];
        }
    }
    Try(1,1);
    cout << cnt;
}