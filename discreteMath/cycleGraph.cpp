#include <iostream>
#include <vector>
using namespace std;
#define Non 100005
int n,m;
vector <int> a[Non];
vector <int> visited(Non,0);
int check = 0;
void DFS(int u){
    visited[u] = 1;
    for(int v : a[u]){
        if(visited[v] == 1){
            cout << "Found a back edge " << "(" << u << "," << v << ")" << endl;
            cout << "The graph contain cycle path" << endl;
            check = 1;
        }
        else if(visited[v] == 0){
            DFS(v);
        }
    }
    visited[u] = 2;
}
void input(){
    cin >> n >> m;
    for(int i = 0;i < m;i++){
        int x,y;
        cin >> x >> y;
        a[x].push_back(y);
    }
}

int main(){
    freopen("cycleGraph.txt","r",stdin);
    input();
    for(int i = 1;i <= n;i++){
    if(visited[i] == 0 && check == 0) DFS(i);
    }
    return 0;
}
