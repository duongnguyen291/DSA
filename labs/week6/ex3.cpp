//đếm dãy bit n số, đếm xem baonh số ko có dãy con
#include <bits/stdc++.h>
using namespace std;
int cnt = 0;
int n, m;
string s;
int ST[15];
int a[25];
int check(int k, int i){
    if(k < m) return 1;
    for(int j = 1 ;  j <= m - 1;j++){
        if(ST[j] != a[k - m + j]) return 1;
    }
    //nếu đến đây mà vẫn bằng nhau, tiếp theo kiểm tra tiếp
    //xem ST[m] có bằng i không, nếu bằng tức là gặp đúng sâu con
    //nghĩa là ko in ra nữa mà return 0
    if(ST[m] == i) return 0; 
    else return 1;
}
void Try(int k){
    for(int i = 0 ; i<=1;i++){
        if(check(k,i) == 1){
            a[k] = i;
            if(k == n) cnt++;
            else Try(k+1);
        }
    }
}
int main(){
    cin >> n >> s;
    m = s.size();
    //đổi từ string lưu vào array
    for(int i = 0;i < m; i++) ST[i+1] = s[i] - '0';
    Try(1);
    cout << cnt;
}