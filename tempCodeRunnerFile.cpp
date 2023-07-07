#include <bits/stdc++.h>
using namespace std;
#define size 1e6
int a[(int)size];

int dynamicProgramming(int *a, int n)
{
    int e = a[0];
    int s = a[0];
    for (int i = 1; i <= n - 1; i++)
    {
        e = max(a[i], a[i] + e);
        s = max(e, s);
    }
    return s;
}
int main(){
    int n;
    cin >> n;
    for(int i = 0;i < n;i++)
        cin >> a[i];
    
    cout << dynamicProgramming(a,n);
    return 0;
}