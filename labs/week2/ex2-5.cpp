//Problem: Chapter 2 - Binary sequence generation 
#include <bits/stdc++.h>
using namespace std;
void generate_binary(int n, string s) {
    if (n == 0) {
        cout << s << endl;
    } else {
        generate_binary(n - 1, s + "0");
        generate_binary(n - 1, s + "1");
    }
}

int main() {
    int n;
    cin >> n;
    generate_binary(n, "");
    return 0;
}