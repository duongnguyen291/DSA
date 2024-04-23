#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int N = 1e4 + 5;
int m,n; // số cạnh, số đỉnh
struct edge{
    int u,v,w; // u -> v có trọng số w
    edge(int _u, int _v, int _w){
        u = _u;
        v = _v;
        w = _w;
    }
};

vector<edge> adj[N]; // danh sách cạnh
vector<int> dist(N,INF); // khoảng cách từ đỉnh s
vector<int> par(N,-1); // đỉnh cha
vector<int> fixedd(N,0); //dán nhãn cố định

void dijkstra(int s){
    dist[s] = 0;
    for(int i = 0; i < n;i ++){
        int v = -1, minDist = INF;
        for(int x = 1; x <= n; x++){
            if(fixedd[x] == 0 && minDist >= dist[x]){
                minDist = dist[x];
                v = x;
            }
        }
        if(v == -1) return;
        fixedd[v] = 1;
        for(const edge &e: adj[v]){
            int u = e.v, w = e.w;
            if(dist[u] > dist[v] + w){
                dist[u] = dist[v] + w;
                par[u] = v;
            } 
        }

    }
}
void input(){
    cin >> n >> m;
    int u,v,w;
    for(int i = 0;i < m;i ++){
        cin >> u >> v >> w;
        adj[u].push_back(edge(u,v,w));
        // adj[v].push_back(edge(v, u, w));
    }
}
void trace(int u){
    stack <int> stk;
    while(true){
        stk.push(u);
        u = par[u];
        if(par[u] == -1) break;
    }
    while(!stk.empty()){
        cout << stk.top() << " ";
        stk.pop();
    }
}
int main(){
    freopen("dijkstra.txt","r",stdin);
    input();
    // cout << n <<" " << m << endl;
    dijkstra(1);
    for(int i = 1; i <= n; i++){
        cout << dist[i] << " \n";
    }
}
