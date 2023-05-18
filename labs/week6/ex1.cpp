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
        //bắt đầu chạy từ thành phố số 1 sang các thành phố 2 >= n
        if(visited[i] == 0){ //nếu thành phố i chưa đi qua
            a[k] = i; // gán a[lần di chuyển thứ k] = thành phố i
            visited[i] = 1; //gán thành phố i đã đi qua r
            f += c[a[k-1]][a[k]]; // f += số bước từ a[k-1] đến a[k]
            if(k == n){ 
                fopt = min(fopt, f + c[a[k]][1]);
            }
            else Try(k + 1);
            visited[i] = 0; f -= c[a[k-1]][a[k]];
        }   
    }
}
void Try_again(int k){
        for(int i = 2;i <= n;i++){
            if(visited[i] == 0){
                a[k] = i;visited[i] = 1;
                f+=c[a[k-1]][a[k]];
                if(k == n){
                    fopt = min(fopt, f + c[a[k]][1]);
                }
                else Try(k+1);
                visited[i] = 0; f-=c[a[k-1]][a[k]];
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