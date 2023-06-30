//quick sort
#include <bits/stdc++.h>
using namespace std;
int n;
int partition(int* arr, int low, int high) {
    int pivot = arr[high];  // Choose the rightmost element as the pivot
    int i = low - 1;  // Index of the smaller element

    for (int j = low; j <= high - 1; j++) {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            i++;  // Increment the index of the smaller element
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Quicksort function
void quicksort(int* arr, int low, int high) {
    if (low < high) {
        // Partition the array
        int pivot = partition(arr, low, high);

        // Recursive call to sort the sub-arrays
        quicksort(arr, low, pivot - 1);
        quicksort(arr, pivot + 1, high);
    }
}

int main(){
    cin >> n;
    int a[n];
    for(int i = 0; i < n;i++){
        cin >> a[i];
    }
    //quick sort
    quicksort(a, 0, n-1);
    for(int i = 0; i < n;i++){
        cout << a[i] << " ";
    }
}