#include <iostream>
#include <algorithm>
using namespace std;

int n, k, m;
int a[20];
int cnt = 0;

void solve(int idx, int cur_k, int cur_sum) {
    if (cur_k == 0 && cur_sum == m) {
        cnt++;
        return;
    }
    if (idx >= n || cur_k <= 0 || cur_sum > m) {
        return;
    }
    // không chọn a[idx]
    solve(idx + 1, cur_k, cur_sum);
    // chọn a[idx]
    solve(idx + 1, cur_k - 1, cur_sum + a[idx]);
}

int main() {
    cin >> n >> k >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    solve(0, k, 0);
    cout << cnt << endl;
    return 0;
}
