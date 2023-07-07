#include <bits/stdc++.h> 
using namespace std;
int par(int *a, int  l, int r){
    int pivot = a[r];
    int i = l - 1;
    for(int j = l, j < r;j++){
        if(a[j]<= pivot){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1], a[r]);
    return i+1;
}
void quickSort(int *a, int l, int r){
    if(l<r){
        int pivot = par(a,l,r);
        quickSort(a,l,pivot - 1);
        quickSort(a,pivot+1,r);
    }
}
int main(){
    // x = 1;
    //     cout << "x: "<< x << endl;
    // cout << "y: " << y << endl;
    // for(int i = 0;i < 10;i++){
    //     for(int j  = 1;j<10;j++){
    //         if(j == 2  ){
    //             break;
    //         }
    //         cout << j << endl;
    //     }
    // }
    char name[] = "Nguyendinhduong";
    strupr(name);
    cout << name << "\n";
    strlwr(name);
    cout << name << "\n";
    return 0;
}