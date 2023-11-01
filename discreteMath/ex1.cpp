#include <iostream>
using namespace std;
const int MAXN = 15;
int n;
int a[MAXN];
void GenNextPerm(){
    int j = n - 1;
    while(a[j] > a[j + 1]) j--;
    int k = n;
    while(a[j] > a[k]) k--;
    swap(a[j],a[k]);
    int l = j + 1, r = n;
    while(l <= r){
        swap(a[l],a[r]);
        l++; r--;
    }
}
void PrintCurPerm(){
    for(int i = 1;i<=n;i++){
        cout << a[i] << " ";
    }
    cout << endl;
}
int CheckLastPerm(){
    for(int i = 1;i <= n;i++){
        if(a[i] != n - i + 1) return 0; 
    }
    return 1;
}
void GenAllPerm(){
    for(int i = 1;i<=n;i++){
        a[i] = i;
    }
    int stop = 0;
    while(!stop){
        PrintCurPerm();
        if(!CheckLastPerm()) GenNextPerm();
        else stop = 1;
    }
}
int check(int i, int k){
    for(int j = 0;j<k;j++){
        if(a[j] == i) return 0;
    }
    if(k < 3) return 1;
    if(a[k-1] < a[k - 2]) return 1;
    return i < a[k - 1];
}
void Try(int k){
    for(int i = 1;i<=n;i++){
        if(check(i,k)){
            a[k] = i;
            if(k == n) PrintCurPerm();
            else Try(k + 1);
        }
    }
}
int main(){
    cin >> n;
    Try(1);

    return 0;
}