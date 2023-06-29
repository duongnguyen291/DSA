#include <bits/stdc++.h>
using namespace std;
void insertionSort(int *a, int size){
    for(int i = 0;i < size;i++){
        int pos = i;
        int temp = a[pos];
        while(pos >0 && temp < a[pos-1]){
            a[pos] = a[pos - 1];
            pos--;
            a[pos] = temp;
        }
    }
}
void selectionSort(int *a, int size ){
    for(int i = 0; i < size -1 ;i++){
        int min = i;
        for(int j = i+1;j < size;j++){
            if(a[j] < a[min]) min = j;
        }
        swap(a[i],a[min]);
    }
}
void print(int *a, int size){
    for(int i = 0;i < size;i++){
        cout << a[i] << " ";
    }
    cout << "\n";
}
int main(){
    int a[] = {0,12,43,3,21,25,56,23,124,99};
    selectionSort(a,10);
    print(a,10);


    return 0;
}