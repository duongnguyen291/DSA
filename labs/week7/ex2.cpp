//taxi
#include <bits/stdc++.h>
using namespace std;
int a[1000][1000];
int x[100];
int serviced[1000];
int n,f = 0 , min_distance = INT_MAX;
void Try(int k){
    for(int y = 1; y<=n;y++){
        if(!serviced[y]){
            x[k] = y;
            serviced[y] = 1;
            if(k==1) f += a[0][x[k]] + a[x[k]][x[k]+n];          
            else f += a[x[k-1]+n][x[k]] + a[x[k]][x[k]+n];
            if(k == n){
                min_distance = min(f+a[x[n]+n][0], min_distance);
            }
            else Try(k+1);
            serviced[y]=0;
            if(k==1) f -= a[0][x[k]] + a[x[k]][x[k]+n];
            else f -= a[x[k-1]+n][x[k]] + a[x[k]][x[k]+n];
            
        }
    }
}

int main(){
    freopen("test2.txt","r",stdin);
    cin >> n;
    for(int i = 0;i < 2*n + 1 ;i++){
        for(int j = 0; j< 2*n + 1;j++){
            cin >> a[i][j];
        }
    }
    Try(1);
    cout << min_distance;

    return 0;
}