#include <bits/stdc++.h>
using namespace std;
#define N 1000001
char T[N];
int n;
int main() {
    freopen("test2.txt", "r", stdin);
    n = 0;
    while (!feof(stdin)) {
        char c = fgetc(stdin);
        T[n] = c;
        n += 1;
    }
    int i = 0, count = 0;
    bool in_word = false;
    while (i < n) {

        if ((T[i] == ' ' || T[i] == '\t' || T[i] == '\n' || T[i] == '\0') && (T[i+1] != ' '||T[i+1] != '\t' || T[i+1] != '\n' || T[i+1] != '\0') ||((T[i] != ' '||T[i] != '\t' || T[i] != '\n')&&(T[i+1] == '\0')) ){
            count++;
        }
        i++;
    }
    cout << count;
    return 0;
}