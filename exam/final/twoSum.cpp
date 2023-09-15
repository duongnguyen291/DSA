#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    vector <int> a;
    while(cin >> n && n != -1){
        a.push_back(n);
    }
    int target;
    cin >>target;
    for(int i = 0; i < a.size();i++){
        for(int j = i; j < a.size();j++){
            if(a[i] + a[j] == target){
                cout << "[" << i << "," << j << "]";ms ;
            }
        }
    }
    return 0;
}