#include <iostream>
#include <queue>
using namespace std;
#define MAXX 999999
int n,m,r,c;
int main(){
    freopen("bfs.txt","r",stdin);   
    cin >> n >> m >> r >> c;
    int a[n + 1][m + 1], d[n + 1][m + 1];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            a[i][j] = 0;
            d[i][j] = MAXX;
            cin >> a[i][j];
        }
    }
    pair <int,int> direction[4] = {{-1,0},{1,0},{0,-1},{0,1}}; 
    queue <pair<int,int>> q;
    q.push({r,c});
    d[r][c] = 0;
    int res = MAXX;
    while(!q.empty()){
        pair <int,int> current = q.front();
        q.pop();
        for(int i = 0; i <= 3; i++ ){
            int next_x = current.first + direction[i].first;
            int next_y = current.second + direction[i].second;
            if(next_x >= 1 && next_y >= 1 && next_x <= n && next_y <= m && a[next_x][next_y] == 0 && d[next_x][next_y] == MAXX){
                q.push({next_x,next_y});
                d[next_x][next_y] = d[current.first][current.second] + 1;
            }
            if((next_x < 1 || next_y < 1 || next_x > n || next_y > m ) && (res > d[current.first][current.second])) res = d[current.first][current.second];
        }
    }

    if(res == MAXX) cout << -1 << endl;
    else cout << res + 1 << endl;
    return 0;    
}