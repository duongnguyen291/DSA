//Problem: Chapter 2 - Binary sequences generation without consecutive 11
#include <bits/stdc++.h>
using namespace std;
void generate_binary_without11(int n, string s) {
    if (n == 0) {
        cout << s << endl;
    } 
    else if(s[s.size()-1] == '1'){
        generate_binary_without11(n - 1, s + "0");
    }
    else{
        generate_binary_without11(n - 1, s + "0");
        generate_binary_without11(n - 1, s + "1");
    }
      
}

int main() {
    int n;
    cin >> n;
    generate_binary_without11(n, "");
    return 0;
}