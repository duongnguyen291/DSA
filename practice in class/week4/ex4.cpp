//enumerate all m-element subsets of the set n elements N = {1,2,3,4,..n}
#include <bits/stdc++.h> 
using namespace std;
int n,m,count;
int a[100];
void Print(){
    for(int i = 1; i <= m; i++) cout << a[i];
    cout << endl;
}
void Try(int k){
for(int i = a[k - 1] + 1; i <= n - m + k;i++){
    a[k] = i;
    if(k == m) Print();
    else Try(k+1);
    }
}


int main(){
    cin >> n >> m;
    Try(1);
    return 0;
}