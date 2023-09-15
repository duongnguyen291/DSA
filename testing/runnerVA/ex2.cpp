#include <iostream>
#include <string>
using namespace std;

const int MAXX = 10;  
int check(int *a, int n) {
    for (int j = 0; j < MAXX; j++) {
        if (a[j] && a[j] != n)
            return 0;
    }
    return 1;
}

int sol(string s, int k) {
    int cnt = 0;
    int n = s.length();
    for (int i = 0; i < n ; i++) {
        int data[MAXX] = {0};
        for (int j = i; j < n; j++) {
            int index = s[j] - '0';
            data[index]++;
            if (data[index] > k)
                break;
            else if (data[index] == k && check(data, k))
                cnt++;
        }
    }
    return cnt;
}

int main() {
    string s;
    int k;
    cin >> s >> k;

    int result = sol(s, k);
    cout << result << endl;

    return 0;
}
