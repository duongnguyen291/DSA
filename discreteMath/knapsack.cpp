#include <iostream>

using namespace std;
const int N = 20;
int v[N], w[N],x[N],x_opt[N];
int n;
int cur_val = 0, bk = 0,b = 0;
int opt_val = -1;
void process(){
    if(cur_val > opt_val){
        opt_val = cur_val;
        for(int i = 1;i<=n;i++){
            x_opt[i] = x[i];
        }
    }
}
void TRY(int k){
    int tk = bk >= w[k];
    for(int i = 0;i <= tk;i++){
        x[i]= i;
        cur_val += x[k] * v[k];
        bk -= x[k] * w[k];
        if(k == n) process();
        else TRY(k + 1);
        cur_val -=x[k] * v[k];
        bk += x[k] * w[k];
    }
}

int main(){
    freopen("test1.txt","r",stdin);
    cin >> n >> b;
    for(int i = 1;i <= n; i++){
        cin >> w[i] >> v[i];
    }
    bk = b;
    // cout << bk << endl;
    TRY(1);
    cout << opt_val << endl;
    for(int i = 1;i<=n;i++){
        cout << x_opt[i] << " ";
    }
    return 0;
}
