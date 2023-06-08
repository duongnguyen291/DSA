#include <bits/stdc++.h>
using namespace std;
#define size 1000
int m,n;
int a[size][size];
int check(int i){//check cột i
    for(int j = 0; j<m;j++){
        if(a[j][i] == 0) return 0;
    }
    return 1;
}
int main(){
    freopen("test1-2.txt","r",stdin);
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        for(int j = 0; j<m;j++){
            cin >> a[i][j];
        }
    }
    //count 
    int count = 0;
    for(int i = 0;i < n;i++){
        count+=check(i);
    }
    cout << count;
}