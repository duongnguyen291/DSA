#include<bits/stdc++.h>
using namespace std;
int dx[4]={0,-1,1,0};
int dy[4]={-1,0,0,1};
int visited[1001][1001]={0};
int ans[1001][1001]={0};
int main()
{
    int n,m,r,c;
    pair<int,int> v;
    int f,s;
    int result = 1001 ;
    cin >> n >> m >> r >> c;
    queue<pair<int,int>>q;
    int a[n+1][m+1];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin >> a[i][j];
        }
    }
    q.push({r,c});
    visited[r][c] = 1;
    ans[r][c] = 1;
    while(!q.empty())
    {
        v = q.front();
        f = v.first;
        s = v.second;
        q.pop();

        for(int i=0;i<=3;i++)
        {
            if(f+dx[i] >= 1 && s+dy[i] >= 1 && f+dx[i] <= n && s+dy[i] <= m && a[f+dx[i]][s+dy[i]]==0 && visited[f+dx[i]][s+dy[i]] == 0)
            {
                q.push({f+dx[i],s+dy[i]});
                visited[f+dx[i]][s+dy[i]] = 1;
                ans[f+dx[i]][s+dy[i]] = ans[f][s] + 1;
                if(f+dx[i] == 1 || s+dy[i] == 1 || f+dx[i] == n || s+dy[i] == m)
                {
                    result = min(result,ans[f+dx[i]][s+dy[i]]);
                }
            }
        }
    }
    if(result == 1001) cout << -1 << '\n';
    else
    cout << result << '\n';
    return 0;
}
