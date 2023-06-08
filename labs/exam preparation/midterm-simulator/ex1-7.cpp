#include <bits/stdc++.h>
using namespace std;
#define size 15
int n;
int a[size][size];
int Try(int r, int c){
    if(r == n && c == n) return 1;
    else{
        if(a[r][c]) Try(r,c+1);
        else if(check(i,r,c)){ //check i thỏa mãn
            a[r][c] = 1;
            if(c == n) Try(r+1,1);
            else 
                Try(r,c+1);
            a[r][c] = 0;
            
        }
    }
}
int main(){
    cin >> n;
    for(int i = 1; i <= n;i++){
        for(int j = 1;j<=n;j++){
            cin >> a[i][j];
        }
    }

}