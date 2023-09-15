#include <bits/stdc++.h>
#include <vector>
using namespace std;
void sol(string s, int k){
    vector <int> mp(26,0);
    int cnt = 0;
    for(int i = 0; i < (int)s.length();i++){
        mp[s[i] - 'a']++;
    }
    for(int i = 0;i < 26;i++){
        mp[i] = mp[i] % 2;
        if(mp[i] == 1) cnt++;
    }
    // cout << cnt;
    if(cnt <= k+1) cout << "YES\n";
    else cout << "NO\n";
}
int main(){
    string s;
    int k;
    cin >> s;
    cin >> k;
    sol(s,k);
    return 0;
}