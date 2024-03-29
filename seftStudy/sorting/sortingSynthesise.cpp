#include <bits/stdc++.h>
using namespace std;
void bubbleSort(int *a, int size);
void insertionSort(int *a, int size);
void selectionSort(int *a, int size);
void mergeSort(int a[], int left, int right);
void quickSort(int a[], int low, int high);
int partition(int a[], int low, int high);
void heapify(int *a, int n, int i);
void heapSort(int *a, int n);
void merge(int arr[], int left, int mid, int right);

int main(){
    freopen("test1.txt","r",stdin);
    int a[10000];
    int n;
    cin >> n;
    for(int i = 0 ; i < n;i++) cin >> a[i];
    heapSort(a,n);
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
    // Create temp arrays to save child elements
    int LeftArr[n1], RightArr[n2];
    //copy the data into the temporary arrays
    for (i = 0; i < n1; i++)
        LeftArr[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        RightArr[j] = arr[mid + 1 + j];
    // Initial index of first subarray
    i = 0; j = 0; k = left;
    while (i < n1 && j < n2) {
        if (LeftArr[i] <= RightArr[j]) {
            arr[k] = LeftArr[i];
            i++;
        } else {
            arr[k] = RightArr[j];
            j++;
        } k++;
    }
    // Copy the remaining elements of LeftArr (if any)
    while (i < n1) {
        arr[k] = LeftArr[i];
        i++; k++;
    }
    // Copy the remaining elements of RightArr (if any)
    while (j < n2) {
        arr[k] = RightArr[j];
        j++; k++;
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
  
// To heapify a subtree rooted with node i which is: để heapify một cây con gốc với nút i là
// an index in arr[]. n is size of heap 
  
// main function to do heap sort 
void heapify(int *a, int n, int i){
    int largest = i;
    int left = 2*i+1, right = 2*i+2;
    if(left < n && a[left] > a[largest] ) 
        largest = left;
    if(right < n && a[right] > a[largest])
        largest = right;
    if(largest !=i){
        swap(a[i],a[largest]);
        heapify(a,n,largest);
    }
}
void heapSort(int *a, int n){
    for(int i = i/2 - 1;i>=0;i--){
        heapify(a,n,i);
    }
    for(int i = n - 1;i >0;i--){
        swap(a[0],a[i]);
        heapify(a,i,0);
    }
}