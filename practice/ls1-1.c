#include <stdio.h>
int main()
{
    int a[6] = {-2, 11, -4, 13, -5, 2};
    int maxA = a[0];
    for (int i = 0; i < 5; i++)
    {
        for (int j = i; j < 5; j++)
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

    printf("\nThe max value is: %d", maxA);
    return 0;
}