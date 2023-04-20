//fibonaci
#include <bits/stdc++.h>
using namespace std;
long long f(int n){
    if(n == 0||n == 1) return n;
    else
    return f(n - 1) + f(n - 2);
}

int main(){
    int n;
    cin >> n;
    cout << f(n);

    return 0;
}