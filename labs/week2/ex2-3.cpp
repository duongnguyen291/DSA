// Problem: Chapter 1 - Multiplication of 2 matrices
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c, d;
    cin >> a >> b;
    int arr[a][b];
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            cin >> arr[i][j];
        }
    }
    cin >> c >> d;
    int brr[c][d];
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < d; j++)
        {
            cin >> brr[i][j];
        }
    }
    int result[a][d];

    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < d; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < c; k++)
            {
                result[i][j] += ((arr[i][k] * brr[k][j]) );
            }
        }
    }
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < d; j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}