#include <bits/stdc++.h>
using namespace std;
const int N = 15;
int n;
int c[N][N];
int x[N], x_opt[N] = {1};
int cur_cost = 0, f_opt = 100000;
int visited[N];
int Cmin = 0;
void Try(int k){
    for(int i = 2;i <= n;i++){
        if(!visited[i]){
            x[k] = i;
            cur_cost += c[x[k-1]][i];
            visited[i] = 1;
            if(k == n){
                if(f_opt > cur_cost + c[i][1]){
                    f_opt = cur_cost + c[i][1];
                    for(int j = 1; j <= n;j++){
                        x_opt[j] = x[j];
                    }
                }
            }
            else {
                if(cur_cost + (n - k + 1) * Cmin < f_opt){
                    Try(k + 1);
                }
            }
            cur_cost -= c[x[k-1]][i];
            visited[i] = 0;
        }
    }
}

void input(){
    cin >> n;
    for(int i = 1; i <= n ;i++){
        for(int j = 1; j <= n;j++){
            cin >> c[i][j];
            if(i != j && (Cmin > c[i][j] || Cmin == 0)) Cmin = c[i][j];
        }
    }
}

int main(){
    freopen("test2.txt","r",stdin);
    input();
    Try(2);
    cout << f_opt << endl;
    for(int i = 0; i<=n ;i++){
        cout << x_opt[i] << " ";
    }
    return 0;
}