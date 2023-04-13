//Problem: Chapter 1 - Add two integers
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string add(string a, string b) {
    string result = "";
    int carry = 0;
    int i = a.size() - 1, j = b.size() - 1;
    
    while (i >= 0 || j >= 0 || carry > 0) {
        int x = i >= 0 ? a[i--] - '0' : 0;
        int y = j >= 0 ? b[j--] - '0' : 0;
        int sum = x + y + carry;
        carry = sum / 10;
        sum %= 10;
        result += to_string(sum);
    }
    
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    string a, b;
    cin >> a >> b;
    
    string result = add(a, b);
    cout << result << endl;
    
    return 0;
}
