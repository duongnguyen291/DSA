#include <bits/stdc++.h>
using namespace std;
typedef struct node{ //Search binary tree
    int data;
    node *right,*left;
}node;
void linearSearch(int *a, int size){
    int x;
    cin >> x;
    for(int i = 0;i < size;i++){
        if(a[i] == x){
            cout <<"The element at: " <<i << endl;
            return;
        }
    }
    cout << -1 << endl;
}
int binarySearch(int *a, int l, int r, int k){
    if(l<=r){
        int mid = (r+l)/2;
        if(a[mid] == k ) return k;
        if else (a[mid] > k) return binarySearch(a,l, mid-1,k);
        else return binarySearch(a,mid+1,r,k);
    }
    return -1;
}

node* findBinarySearch(node *r, int x){
    if(r == NULL || r->data == x) return r;
    if(r->data > x) return findBinarySearch(r->left,x);
    return findBinarySearch(r->right,x);
}
int main(){

    return 0;
}