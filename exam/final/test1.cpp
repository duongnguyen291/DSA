//loc so nho nhat va duy nhat 
#include <bits/stdc++.h>
using namespace std;
#define MAXX 1000000
long long data[MAXX];
int main(){
    int n;
    int res;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> res;
        data[res]++;
    }
    for(int i = 0; i < n;i++){
        if(data[res] == 1) cout << res << endl;
    }
}