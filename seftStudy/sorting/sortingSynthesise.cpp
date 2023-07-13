#include <bits/stdc++.h>
using namespace std;
void bubbleSort(int *a, int size);
void insertionSort(int *a, int size);
void selectionSort(int *a, int size);
void mergeSort(int a[], int left, int right);
void quickSort(int a[], int low, int high);
int partition(int a[], int low, int high);
void heapify(int arr[], int n, int i);
void heapSort(int arr[], int n);
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

  
// To heapify a subtree rooted with node i which is: để heapify một cây con gốc với nút i là
// an index in arr[]. n is size of heap 
void heapify(int arr[], int n, int i) 
{ 
    int largest = i; // Initialize largest as root 
    int l = 2*i + 1; // left = 2*i + 1 
    int r = 2*i + 2; // right = 2*i + 2 
  
    // If left child is larger than root 
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
  
    // If right child is larger than largest so far 
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
  
    // If largest is not root 
    if (largest != i) 
    { 
        swap(arr[i], arr[largest]); 
  
        // Recursively heapify the affected sub-tree 
        heapify(arr, n, largest); 
    } 
} 
  
// main function to do heap sort 
void heapSort(int arr[], int n) 
{ 
    // Build heap (rearrange array): xây dựng heap (sắp xếp lại mảng)
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 
  
    // trích xuất từng phần từ một từ heap
    for (int i=n-1; i>0; i--) 
    { 
        // Move current root to end : di truyển gốc hiện tại đến cuối
        swap(arr[0], arr[i]); 
  
        // call max heapify on the reduced heap : gọi max heapify trên heap đã giảm
        heapify(arr, i, 0); 
    } 
} 