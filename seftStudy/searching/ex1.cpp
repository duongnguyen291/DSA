#include <bits/stdc++.h>
using namespace std;
void linearSearh(int *a, int size){
    int x;
    cin >> x;
    for(int i = 0 ; i < size;i++){
        if(a[i] == x){
            cout << "The element is in the array: " << i << "\n";
            break;
        }
    }
    cout << "The element is not in the array\n";
}
int binarySearch(int *a, int l, int r, int key){
    if(l <= r){
        int mid = (r - l)/2;
        if(a[mid] == key) return mid;
        if(a[mid] > key) return binarySearch(a,l ,mid - 1, key);
        else binarySearch(a,mid+1,r,key);
    }
    else -1;
}
void binaryString(string s, int k, int n){
    if(k == n) cout << s << endl;
    else {
        binaryString(s + "1",k+1,n);
        binaryString(s + "0",k+1,n);
    }
}
int main(){
    int a[] = {4,2,3,2,56,1,6,66,7,78};
    binaryString("",0,4);



}