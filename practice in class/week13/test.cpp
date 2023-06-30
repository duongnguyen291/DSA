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
//quicksort
//----------------------------------------------------//
int partition(int *a, int low, int high){
    int pivot = a[high];
    int i = low - 1;
    for(int j = low; j < high;j++){
        if(a[j] <= pivot){
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i+1], a[high]);
    return i+1;
    // {12342,12,43,3,21,25,56,23,124,99,4};
}
void quickSort(int *a, int low, int high){
    if(low< high){
        int pos = partition(a,low, high);
        quickSort(a, low, pos -1 );
        quickSort(a, pos + 1, high);
    }
}
void print(int *a, int size){
    for(int i = 0;i < size;i++){
        cout << a[i] << " ";
    }
    cout << "\n";
}
int main(){
    int a[] = {12342,12,43,3,21,25,56,23,124,99,4};
    quickSort(a,0,10);
    print(a,11);


    return 0;
}