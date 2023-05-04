#include <bits/stdc++.h>
using namespace std;
#define N 25

int n, k, r, c;
int a[N];
int cnt = 0;
int check(int k, int j){
    for(int i = 1; i <= n;i++){
        if(a[i] == j || abs(a[i] - j) == abs(i - k)) return 0;
    }
    return 1;
}
void Try(int k){
    //k: column
    for(int j = 1; j <= n; j++){
        //kiểm tra xem đặt hậu ở cột k, hàng j có đụng không
        if(check(k,j)){
            //nếu không đụng, thì đặt lưu biến tại cột k, hàng j
            a[k] = j;
            //nếu k = n nghĩa là đã xét xong hết bàn cờ: giờ in ra hoặc count++
            if(k == n) cnt++; 
            //k chưa bằng n nghĩa là chưa xét xong , xét tiếp đến cột k + 1
            else Try(k+1);
        }
    }

}

int main() {
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        cin >> r >> c;
        if(a[r]!=0) {cout <<"da co con hau o tren cot nay" ; break;}
        a[r] = c;
    }
    Try(1);
    cout << cnt;
    return 0;
}
