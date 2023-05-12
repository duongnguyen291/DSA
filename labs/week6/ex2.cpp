//TSP 
#include <bits/stdc++.h>
using namespace std;
int n,M;
int c[21][21];
int visited[21]; // visited[i] = 1 if city is already visited , otherwise visited[i] = 0
int a[21];
int fopt = INT_MAX; // save the value 
int f = 0;
int cnt;
void Try(int k){
    for(int i = 2;i <= n;i++){
        if(visited[i] == 0){
            a[k] = i;
            visited[i] = 1;
            f += c[a[k-1]][a[k]];
            if(k == n){
                int g = f + c[a[k]][1];
                if(g < M) cnt+=1;
            }
            else Try(k + 1);
            visited[i] = 0; f -= c[a[k-1]][a[k]];
        }
    }
}
int main(){
    // cout << 1;
    freopen("test2.txt","r",stdin);
    cin >> n >> M;
    for(int i = 1;i<=n;i++){
        for(int j = 1; j<=n;j++){
            cin >> c[i][j];
        }
    }
 
    a[1] = 1;
    Try(2);
    cout << cnt;
    return 0;
}