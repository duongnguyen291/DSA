#include <iostream>
using namespace std;

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
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        // Tìm điểm chính giữa
        int mid = left + (right - left) / 2; 
        // Sắp xếp các nửa đầu và nửa sau
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        // Hợp nhất các nửa đã sắp xếp
        merge(arr, left, mid, right);
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Mang ban dau: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    mergeSort(arr, 0, size - 1);

    cout << "Mang sau khi sap xep: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
