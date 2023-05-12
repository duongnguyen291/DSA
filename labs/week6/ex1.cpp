//TSP 
#include <bits/stdc++.h>
using namespace std;
int n;
int c[25][25];
int visited[21]; // visited[i] = 1 if city is already visited , otherwise visited[i] = 0
int a[25];
int fopt = INT_MAX; // save the value 
int f = 0;
void Try(int k){
    for(int i = 2;i <= n;i++){
        if(visited[i] == 0){
            a[k] = i;
            visited[i] = 1;
            f += c[a[k-1]][a[k]];
            if(k == n){
                fopt = min(fopt, f + c[a[k]][1]);
            }
            else Try(k + 1);
            visited[i] = 0; f -= c[a[k-1]][a[k]];
        }
    }
}
int main(){
    freopen("test1.txt","r",stdin);
    cin >> n;
    for(int i = 1;i<=n;i++){
        for(int j = 1; j<=n;j++){
            cin >> c[i][j];
        }
    }
 
    a[1] = 1;
    Try(2);
    cout << fopt;
    return 0;
}