#include <bits/stdc++.h>
using namespace std;
void bubbleSort(int *a, int size);
void insertionSort(int *a, int size);
void selectionSort(int *a, int size);
void mergeSort(int a[], int left, int right);
void quickSort(int a[], int low, int high);
int partition(int a[], int low, int high);
void heapSort(int *a, int size);
void merge(int arr[], int left, int mid, int right);
int main(){
    freopen("test1.txt","r",stdin);
    int a[10000];
    int n;
    cin >> n;
    for(int i = 0 ; i < n;i++) cin >> a[i];
    quickSort(a,0,n);
    for(int i = 0 ; i < n;i++) cout << a[i] << " ";

    return 0;
}
void bubbleSort(int *a, int size){
    for(int i=0;i<size;i++){
        for(int j=0;j<size-i-1;j++){
            if(a[j]>a[j + 1]) swap(a[j],a[j + 1]);
        }
    }
}
void insertionSort(int *a, int size){
    for(int i = 1;i < size;i++){
        int pos = i;
        int temp  = a[pos];
        while(pos>0 && temp < a[pos-1]){
            a[pos] = a[pos-1];
            pos--;
            a[pos] = temp;
        }
    }
}
void selectionSort(int *a, int size){
    for(int i = 0;i < size - 1;i++){
        int min = i;
        for(int j = i+1; j < size;j++){
            if(a[j] < a[min]){
                min = j;
            }
        }
        swap(a[i], a[min]);
    }
}
void mergeSort(int a[], int left, int right){
    if(left<right){
        int mid = left+(right-left)/2;
        mergeSort(a,left,mid);
        mergeSort(a,mid+1,right);
        merge(a,left,mid,right);
    }
}
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    // Tạo các mảng tạm để lưu các phần tử con
    int LeftArr[n1], RightArr[n2];
    // Sao chép dữ liệu vào các mảng tạm
    for (i = 0; i < n1; i++)
        LeftArr[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        RightArr[j] = arr[mid + 1 + j];
    // Hợp nhất các mảng tạm thành mảng ban đầu
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (LeftArr[i] <= RightArr[j]) {
            arr[k] = LeftArr[i];
            i++;
        } else {
            arr[k] = RightArr[j];
            j++;
        }
        k++;
    }
    // Sao chép các phần tử còn lại của mảng LeftArr (nếu có)
    while (i < n1) {
        arr[k] = LeftArr[i];
        i++;
        k++;
    }
    // Sao chép các phần tử còn lại của mảng RightArr (nếu có)
    while (j < n2) {
        arr[k] = RightArr[j];
        j++;
        k++;
    }
}
void quickSort(int a[], int low, int high){
    if(low < high){
        int pivot = partition(a, low, high);
        quickSort(a,low,pivot-1);
        quickSort(a,pivot+1,high);
    }
}   
int partition(int a[], int low, int high){
    int pivot = a[high];
    int i = low-1;
    for(int j=low;j<high;j++){
        if(a[j] <= pivot){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[high]);
    return i+1;
}