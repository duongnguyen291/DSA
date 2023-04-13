#include <bits/stdc++.h>
using namespace std;
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
    cout << "\nThe max value is: "<< bruteForce1(a, 6);
    cout  <<"\nThe max value is: " << bruteForce2(a, 6);
    cout << "\nThe max value is: "<<  dynamicProgramming(a, 6);
    return 0;
}
