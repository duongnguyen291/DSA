#include <iostream>
#include <vector>
using namespace std;
int checkNonDecreasing(int *b, int size){
    int res = 0;
    for (int i = 0; i < size - 1; i++) {
        if (b[i] > b[i + 1]) {
            res = 1;
            break;
        }
    }
    return res;
}
int checkNonIncreasing(int *c, int size){
    int res = 0;
    for (int i = 0; i < size - 1; i++) {
            if (c[i] < c[i + 1]) {
                res = 1;
                break;
            }
    }
    return res;
}
int main() {
    int n, sizeB, sizeC, flag1, flag2, flag3;
    /* Read information for array arr */
    cin >> n;
    int arr[n];
    for (int j = 0; j < n; j++){
        cin >> arr[j];
    }
    /* Read information for array b */
    cin >> sizeB;
    int b[sizeB];
    for (int i = 0; i < sizeB; i++) {
        cin >> b[i];
    }
    /* Read information for array c */
    cin >> sizeC;
    int c[sizeC];
    for (int i = 0; i < sizeC; i++) {
        cin >> c[i];
    }
     flag1 = flag2 = flag3 = 0;

    /* First check if length of both array b and array c are n */
    if (sizeB == n && sizeC == n) {
        /* Check if array b are in non-decreasing order */
        flag1 = checkNonDecreasing(b, sizeB);
        /* Check if array a are in non-increasing order */
        flag2 = checkNonIncreasing(c, sizeC);
        /* Check if both array b and array c follow the given order */
        if (flag1 == 0 && flag2 == 0) {
            /* To check for the next condition: b[i] >=0 && c[i] >= 0 && b[i] + c[i] == arr[i] */
            for (int i = 0; i < n; i++) {
                if (b[i] >= 0 && c[i] >= 0 && b[i] + c[i] == arr[i]) {
                    continue;
                } else {
                    flag3 = 1;
                    break;
                }
            }
            /* Check if the two given arrays b and c are the perfect break of array arr or not */
            if (flag3 == 1) {
                cout << "The two given arrays b and c are not the perfect break of array arr!" << endl;
            } else {
                cout << "The two given arrays b and c are the perfect break of array arr!" << endl;
            }
        }

    } else {
        cout << "The two given arrays b and c are not the perfect break of array arr!" << endl;
    }

    return 0;
}
