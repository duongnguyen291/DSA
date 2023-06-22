//Sorting 
#include <bits/stdc++.h>
using namespace std;
void insertionSort(int *a, int size){
    for(int i = 1; i < size; i++){
        int j = i-1;
        int tmp = a[i];
        while(j >= 0 && a[j] > tmp){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = tmp;
    }
}
void bubbleSort(int *a, int size){
    for(int i = 0; i < size-1; i++){
        for(int j = 0; j < size-i-1; j++){
            if(a[j] > a[j+1]) swap(a[j],a[j+1]);
        }
    }
}
void selectionSort(int *a, int size){
    for(int i = 0; i < size-1; i++){
        int min = i;
        for(int j = i+1; j < size; j++){
            if(a[j] < a[min]) min = j;
        }
        swap(a[i],a[min]);
    }
}
void mergeSort(int *a, int l, int m, int r){
    int n1 = m-l+1;
    int n2 = r-m;
    int *L = new int[n1];
    int *R = new int[n2];
    for(int i = 0; i < n1; i++) L[i] = a[l+i];
    for(int i = 0; i < n2; i++) R[i] = a[m+1+i];
    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2){
        if(L[i] <= R[j]) a[k++] = L[i++];
        else a[k++] = R[j++];
    }
    while(i < n1) a[k++] = L[i++];
    while(j < n2) a[k++] = R[j++];
    delete[] L;
    delete[] R;
}
void quickSort(int *a, int size){
    if(size <= 1) return;
    int pivot = a[size/2];
    int i = 0, j = size-1;
    while(i <= j){
        while(a[i] < pivot) i++;
        while(a[j] > pivot) j--;
        if(i <= j){
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }
    quickSort(a,i);
    quickSort(a+i,size-i);
}
void heapSort(int *a, int size){
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < size; i++) pq.push(a[i]);
    for(int i = 0; i < size; i++){
        a[i] = pq.top();
        pq.pop();
    }
}
int main(){

    return 0;
}