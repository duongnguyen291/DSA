//khung sườn C++
#include <bits/stdc++.h>
using namespace std;
typedef struct node{
    int id;
    node *left;
    node *right;
}
void quickSort(int a[], int size){
    if(size <= 1) return;
    int pivot = a[size - 1];
    int i = 0;
    for(int j = 0; j < size - 1; j++){
        if(a[j] < pivot){
            swap(a[i], a[j]);
            i++;
        }
    }
    swap(a[i], a[size - 1]);
    quickSort(a, i);
    quickSort(a + i + 1, size - i - 1);
}
void selectionSort(int a[], int n){
    for(int i = 0; i < n - 1; i++){
        int min = i;
        for(int j = i + 1; j < n; j++){
            if(a[j] < a[min]) min = j;
        }
        swap(a[i], a[min]);
    }
}
//mày có hiểu tao nói gì không ?
//t thấy mày nói vậy là tao nói vậy
//mày nghĩ tao đang code gì ở trên file này?
//t thấy mày đang code hàm main

int main(){


    return 0;
}