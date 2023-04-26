//đếm xem có bao đường đi từ tọa độ (i,j) đến (a,b) 
//chỉ được đi từ phải sang và đi lên ( i < a,j < b)
#include <bits/stdc++.h>
using namespace std;
int step(int i , int j , int a, int b){
    if(i == a || j == b) return 1;
    if(i > a || j> b) return 0;
    return step(i+1,j,a,b) + step(i,j+1,a,b);
}
int main( ){
    int i,j,a,b;
    cin >> i >> j >> a >> b;
    cout << step(i,j,a,b) << " hehe";
    return 0;
}