#include <bits/stdc++.h>
using namespace std;
//-------------------INSERTION SORT----------------------------------------
//insertion sort tốt nhất là khi mảng đã được sắp xếp từ bé đến lớn. Lúc này độ phức tạo là O(n)
//insertion sort tệ nhất là khi mảng sắp xếp từ lớn đến bé
void insertionSort1(int *a, int size){
    for(int k = 1; k < size;k++){
        int pos = k - 1;
        int temp = a[k];
        while(pos >= 0 && a[pos] > temp){
            a[pos + 1] = a[pos];
            pos--;
        }
        a[pos+1] = temp;
    }   
}
void insertionSort2(int *a, int size){
    for(int k = 1; k <size;k++){
        int pos = k; int temp = a[pos];
        while(pos > 0 && temp < a[pos- 1]){
            a[pos] = a[pos - 1];
            pos--;
        }
        a[pos] = temp;
    }
}
//-------------------------------------------------------------------------
//-------------------SELECTION SORT----------------------------------------
//nên áp dụng selection sort khi cần phải liên tục hoán đổi dữ liệu có kích thước lớn

void selectionSort(int *a, int size){
    for(int i = 0; i < size - 1;i++){
        int min = i;
        for(int j = i + 1;j < size;j++){
            if(a[j] < a[min] ) min = j;
        }
        swap(a[i], a[min]);
    }
}
//-------------------------------------------------------------------------
//----------------------BUBBLE SORT----------------------------------------
void bubbleSort(int *a, int size){
    for(int i = 0; i< size - 1;i++){
        for(int j = 0;j < size - i - 1;j++){
            if(a[j] > a[j+1]) swap(a[j], a[j+1]);
        }
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
    insertionSort2(a,10);
    print(a,10);
    return 0;
}