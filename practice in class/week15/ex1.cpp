#include <bits/stdc++.h>
using namespace std;
void maxheapify(int *a, int size, int i){//array start from 0
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;
    if(left < size && a[left] > a[largest]) 
        largest = left;
    if(right < size && a[right] > a[largest]) 
        largest = right;
    if(largest != i){
        swap(a[i], a[largest]);
        maxheapify(a,size,largest);
    }

}
void heapSort(int *a, int size){
    for(int i = size/2 - 1;i >= 0;i--){
        maxheapify(a,size,i);
    }
    for(int i = size - 1;i >= 0;i--){
        swap(a[0],a[i]);
        maxheapify(a,i,0);
    }
}
void print(int *a, int size){
    for(int i = 0;i < size;i++){
        cout << a[i] << " ";
    }
    cout << endl;
}
int main(){
    int a[]= {1,4,2,3,6,10,9,8,7,5};
    heapSort(a,10);
    print(a,10);

}