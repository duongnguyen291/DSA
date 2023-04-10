#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n;
    clock_t t;
    int f;
    t = clock();
    int *a;
    printf("Enter the size of array a: ");
    scanf("%d", &n);
    a = (int*) malloc(n * sizeof(int));
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        a[i] = rand();
    }
    int maxSum = a[0];
    for (int i=0; i<n; i++) {
        for (int j=i; j<n; j++) {
            int sum = 0;
            for (int k=i; k<=j; k++) {
                sum += a[k];
            }
            if (sum > maxSum) {
                maxSum = sum;
            }
        }
    }
    free(a); 
    t=clock()-t;
    printf("The maximum subarray sum is: %d \n", maxSum);
    printf("Time taken: %f seconds\n", ((double)t)/CLOCKS_PER_SEC);
    return 0;
}
void timeAlgorithm(void (*algorithm)(void), const char* algorithmName) {
    // Bắt đầu tính thời gian
    clock_t start = clock();
    // Gọi hàm tính toán
    (*algorithm)();
    // Kết thúc tính thời gian
    clock_t end = clock();
    // Tính thời gian trôi qua và đưa ra kết quả
    double timeSpent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("%s took %f seconds to execute.\n", algorithmName, timeSpent);
}