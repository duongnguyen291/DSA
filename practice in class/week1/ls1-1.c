#include <stdio.h>
int bruteForce1(int *a, int n)
{
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
    return maxA;
}
int bruteForce2(int *a, int n)
{
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
    int e = a[0];
    int s = a[0];
    for (int i = 1; i <= n - 1; i++)
    {
        e = max(a[i], a[i] + e);
        s = max(e, s);
    }
    return s;
}

int main()
{
    int a[6] = {-2, 11, -4, 13, -5, 2};
    printf("\nThe max value is: %d", bruteForce1(a, 6));
    printf("\nThe max value is: %d", bruteForce2(a, 6));
    printf("\nThe max value is: %d", dynamicProgramming(a, 6));
    return 0;
}