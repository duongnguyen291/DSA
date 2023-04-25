//đếm xem có bao đường đi từ tọa độ (i,j) đến (a,b) chỉ được đi từ phải sang và đi lên ( i < a,j < b)
#include<bits/stdc++.h>
using namespace std ;
int CountPaths(int i , int j , int a , int b )
{
    if(i == a || j == b) return 1 ;
    if(i > a || j > b) return 0 ;
    return CountPaths(i+1,j,a,b) + CountPaths(i,j+1,a,b) ;
}
int main()
{
    int i , j , c , d ;
    cin >> i >> j >> c >> d ;
    cout << CountPaths(i,j,c,d) ;
    return 0 ;
}