//Problem: Chapter 3 - Maze
#include <bits/stdc++.h>
using namespace std;
#define size 1000
#define size_
int a[size][size];
int n,m,r,c;
int visited[size][size];
int ans[size][size];
//di chuyển lần lượt thứ tự là : lên trên, xuống dưới, sang trái , sang phải
int dx[4]={0,-1,1,0};
int dy[4]={-1,0,0,1};
//check xem đi hướng nào và còn trong bàn không, đánh dấu là chưa đi 
int check(int x,int y, int i){
    return x+dx[i] > 0 && y+dy[i]>0&&x+dx[i]<=n&&y+dy[i]<=m && visited[x+dx[i]][y+dy[i]] == 0 && a[x+dx[i]][y+dy[i]]==0;
}
int main(){
    pair<int,int> toado;
    queue<pair<int,int>> q;
    freopen("test3.txt","r",stdin);
    cin >> n >> m >> r >> c;
    for(int i = 1;i <= n;i++){
        for(int j = 1; j <= m;j++){
            cin >> a[i][j];
        }
    }
    q.push({r,c});
    int x,y;
    int result = INT_MAX;
    visited[r][c] = 1;
    ans[r][c] = 1;
    while(!q.empty()){
        toado = q.front();
        x = toado.first;
        y = toado.second;
        q.pop();
        for(int i = 0;i<4;i++){
            //check xem đi được những hướng nào
            if(check(x,y,i)){
                visited[x+dx[i]][y+dy[i]] = 1, a[x+dx[i]][y+dy[i]]== 1;
                q.push({x+dx[i],y+dy[i]});
                ans[x+dx[i]][y+dy[i]] = ans[x][y] + 1;
                //check xem đã ra khỏi mê cung chưa
                if(x + dx[i] == 1 || y + dy[i] == 1 || x+dx[i] == n || y+dy[i] == m){
                    result = min(result, ans[x+dx[i]][y+dy[i]]);
                }
            }   
        }
    }
    if(result == INT_MAX) cout << "-1" << endl;
    else 
    cout << result << endl;
    return 0;
}