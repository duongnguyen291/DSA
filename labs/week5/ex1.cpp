//Problem: Chapter 2 - Binary sequences without containing another given binary sequence
//Problem: Chapter 2 - Binary sequence generation 
#include <bits/stdc++.h>
using namespace std;
int save[1100000][25];
bool isSubstring(std::string a, std::string b) {
    return b.find(a) != std::string::npos;
}
int cnt = 0;
void generate_binary(int n, string s, string con) {
    if (n == 0) {
        //đến đây là đã hoàn thành string và giờ đưa string vào hàm để check xem có chưa dãy con không?
        if(isSubstring(con,s) == false) {cnt++;}
        cout << s << " day con: "<< cnt << endl;
    } 
    else {
        generate_binary(n - 1, s + "0", con);
        generate_binary(n - 1, s + "1", con);
    }
}
int main() {
    int n;
    const string s = "";
     string con;
    cin >> n;
    cin >> con;
    generate_binary(n,s,con);
    cout << con<< endl;
    cout << cnt<<endl;
    return 0;
}   