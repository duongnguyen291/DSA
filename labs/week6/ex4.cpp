//Count soduku bài này output sai: nguyên nhân, sai hàm check
#include <bits/stdc++.h>
using namespace std;
int a[9][9]; // lưu ý hàng đầu và cột đầu bằng 0, hàng cuối và cột cuối bằng 9 
int cnt = 0;
//kiểm tra điều kiện
int check(int i, int r, int c){
    //check hàng
    for(int j = 0; j < 9;j++){
        if(a[r][j] == i ) return 0;
    }
    //check cột
    for(int j = 0; j < 9;j++){
        if(a[j][c] == i) return 0;
    }
    //check ô nhỏ 3x3 
    int r1 = 3*(r/3);
    int c1 = 3*(c/3);
    for(int u = r1; u <= r1+2;u++){
        for(int v = c1; v <= c1+2; v++){
            if(a[u][v] == i) {return 0;}
        }   
    }
    // if(col % 3 == 0) col = (col - 3) ;
    // else col = col - (col % 3);
    // if(row % 3 == 0) row = row - 3;
    // else row = row - (row % 3);
    return 1;
}
void Try(int r, int c){
    if(a[r][c] != 0){
        if(r == 8 && c == 8) cnt++;
        else if(c == 8 && r!=8) {
            Try(r + 1,c);
        }
        else {
            Try(r, c + 1);
        }
    }
    else{
        for(int i = 1; i <= 9;i++){
            if(check(i,r,c) == 1){
                a[r][c] = i;
                if(r == 8 && c == 8) cnt++;
                else if(c == 8 && r != 8 ){
                    Try(r+1,c); 
                } 
                else {
                    Try(r, c + 1); 
                }
                a[r][c] = 0;
            }
        }
    }
}
int main(){ 
    freopen("test3.txt","r", stdin);
    for(int i = 0;i < 9; i++){
        for(int j = 0; j < 9; j++){
            cin >> a[i][j];
        }
    }
    // for(int i = 0;i < 9; i++){
    //     for(int j = 0; j < 9; j++){
    //         cout << a[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    Try(0,0);
    cout << cnt;
    return 0;
}