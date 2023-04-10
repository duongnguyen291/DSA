#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
int bruteForce1(int *a, int n)
{
    clock_t start = clock();
    int maxA = a[0];
    
    for (int i = 0; i <= n - 1; i++)
    {
        for (int j = i; j <= n - 1; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += a[k];
                if (sum > maxA)
                {
                    maxA = sum;
                };
            }
        }
    }
    clock_t end = clock();
    double timeSpent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nBrute Force 1 took %lf seconds to execute.\n", timeSpent);
    return maxA;
}
int bruteForce2(int *a, int n)
{
    clock_t start = clock();
    int maxA = a[0];
    for (int i = 0; i <= n - 1; i++)
    {
        int sum = 0;
        for (int j = i; j <= n - 1; j++)
        {
            sum += a[j];
            if (sum > maxA)
                maxA = sum;
        }
    }
    clock_t end = clock();
    double timeSpent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nBrute Force 2 took %lf seconds to execute.\n", timeSpent);
    return maxA;
}
int max(int a, int b)
{
    if (a > b)
        return a;
    else
    return b;
}
int dynamicProgramming(int *a, int n)
{
    clock_t start = clock();
    int e = a[0];
    int s = a[0];
    for (int i = 1; i <= n - 1; i++)
    {
        e = max(a[i], a[i] + e);
        s = max(e, s);
    }
    clock_t end = clock();
    double timeSpent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nDynamic Programming took %lf seconds to execute.\n", timeSpent);
    return s;
}

int main()
{   
    int n;
    int a[6] = {-2, 11, -4, 13, -5, 2};
    printf("\nEnter size of array b: ");
    scanf("%d", &n);
    int b[n];
    srand(time(NULL));
    for(int i = 0 ;i < n; i++){
       b[i] = rand() % 100 + 1;
    }
    printf("\nThe max value is: %d", bruteForce1(a, 6));
    printf("\nThe max value is: %d", bruteForce2(a, 6));
    printf("\nThe max value is: %d", dynamicProgramming(a, 6));
    printf("\n------------------------------------------");
    printf("\nThe max value of B is: %d", bruteForce1(b, n));
    printf("\nThe max value of B is: %d", bruteForce2(b, n));
    printf("\nThe max value of Bis: %d", dynamicProgramming(b, n));
    return 0;
}
