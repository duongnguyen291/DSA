#include <bits/stdc++.h>
using namespace std;

#define N 25
#define M 25

int n, k, r, c;
int a[N][M];



int main() {
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        cin >> r >> c;
        a[r][c] = 1;
    }
    cout << solve(1) << endl;
    return 0;
}
