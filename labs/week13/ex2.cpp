//Problem: Dynamic Programming: Longest Common Subsequence
    #include <bits/stdc++.h>
    using namespace std;
    #define size 10000
    int memory[size][size];
    int X[size], Y[size];
    int LCS(int i, int j){
        if(i == 0 || j == 0){
            return 0;
        }
        if(memory[i][j] != -1) return memory[i][j];
        if(X[i] == Y[j]) memory[i][j] = 1+LCS(i-1,j-1);
        else{
            memory[i][j] = max(LCS(i-1,j),LCS(i,j-1));\
        }
            return memory[i][j];

    }
    int main(){
        int m,n;
        freopen("test2.txt","r",stdin);
        cin >> n >> m;
        for(int i = 0; i < n;i++){
            cin >> X[i];
        }
        for(int i = 0; i <= m;i++){
            cin >> Y[i];
        }
        for(int i = 0; i <= n;i++){
            for(int j = 0;j<m;j++){
                memory[i][j] = -1;
            }
        }
        int res = LCS(n,m);
        cout << res;
        return 0;
    }