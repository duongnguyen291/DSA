//binary Search
#include <bits/stdc++.h>
using namespace std;
void sapXep(int s[], int n){
    int temp;
    for(int i = 0; i < n;i++){
        for(int j = 0;i < n - 1;j++){
            if(s[i] > s[j]) {
                s[i] = temp;
                s[i] = s[j];
                s[j] = temp;
                
            }
        }
    }
}
int binsearch(int low, int high, int s[], int key){
    //find the key appears s[low] s[high]
    if(low > high ) return -1;
    else {
        int mid = (low + high) /2;
        if(s[mid] == key) return mid;
        else if(s[mid] < key) return binsearch( mid + 1,high,s,key);
        else if(s[mid] > key) return binsearch( low,mid - 1,s,key);
    }
}
int binarySearch2( int low, int high, int s[], int key){
    if(low > high) return -1;
    else{
        int mid = (low + high)/2;
        if(s[mid] == key) return mid;
        else if(s[mid] < key ) return binarySearch2(mid + 1, high,s,key);
        else if(s[mid] > key) return binarySearch2(low, mid - 1 ,s,key);
    }
}
int main(){
    int n,k ;
    cin >> n >>k;
    int a[n+5] ;
    for(int i = 0 ; i < n ; i++) cin >> a[i] ;
    sort(a,a+n) ;
    cout << binsearch(0, n - 1 , a, k ) << endl;    
    cout << binarySearch2(0,n - 1, a, k) << endl;
    return 0;
}