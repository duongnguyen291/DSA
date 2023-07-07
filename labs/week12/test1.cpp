#include <bits/stdc++.h>
using namespace std;
int cnt = 0;
int ham6(int a){
    if(a == 0) return 0;
    else {
        cnt++;
        return ham6(a - 1) + ham6(a - 1);
    }
}
void ham7(unsigned int n){
    if(n==0) return;
    else{
        ham7(--n);
    printf("%d",n);
    }
}
int ham1(unsigned int n)
{
    int i,j,s = 0;
    for(i=0;j<n;i++){
        for(j=i;j<n;j++){
            s++;// Câu lệnh cần đếm
        }
    }
    return s;
}

int main(){
// int x = 10;
// int y = 20;
// const int* ptr = &x;
// ptr = &y; // Hợp lệ, con trỏ có thể trỏ tới một vùng nhớ khác
// // *ptr = 30; // Không hợp lệ, giá trị không thể thay đổi qua con trỏ hằngs

// int x = 10;
// int y = 20;
// int* const ptr = &x;
// *ptr = 30; // Hợp lệ, giá trị của vùng nhớ có thể thay đổi qua con trỏ hằng
// ptr = &y; // Không hợp lệ, con trỏ không thể thay đổi để trỏ tới vùng nhớ khác

// cout << *ptr;
// int x = 10;
int res = ham1(10);
cout << res;
}