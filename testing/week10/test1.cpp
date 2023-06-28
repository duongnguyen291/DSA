//khung sườn C++
#include <bits/stdc++.h>
using namespace std;

int main(){
    int value = 10;
    int *ptr = &value;
    int *ptr_ptr = ptr;
    cout << value << "\n";
    cout << *ptr << "\n";
    cout << *ptr_ptr << "\n";
    

    return 0;
}