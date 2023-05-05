//Problem: Chapter 2 - Binary sequences without containing another given binary sequence
//Problem: Chapter 2 - Binary sequence generation 
#include <bits/stdc++.h>
using namespace std;
int save[1100000][25];
void generate_binary(int n, string s, string con) {
    if (n == 0) {
        //đến đây là đã hoàn thành string và giờ đưa string vào hàm để check xem có chưa dãy con không?
        if(check(int s))
         
        
    } else {
        generate_binary(n - 1, s + "0", con);
        generate_binary(n - 1, s + "1", con);
    }
}
int main() {
    int n;
    string s = "";
    string con;
    cin >> n;
    cin >> con;
    generate_binary(n, "");
    return 0;
}   