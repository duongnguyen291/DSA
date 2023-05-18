#include <bits/stdc++.h>
using namespace std;

int count1 = 0;
int a[14][14];

int check(int row, int col, int num)
{
    // check row
    for (int i = 1; i <= 9; i++)
    {
        if (a[row][i] == num)
            return 0;
    }
    // check col
    for (int i = 1; i <= 9; i++)
    {
        if (a[i][col] == num)
            return 0;
    }
    // check box
    if (col % 3 == 0)
        col = (col - 3);
    else
        col = col - (col % 3);
    if (row % 3 == 0)
        row = row - 3;
    else
        row = row - (row % 3);
    for (int i = row + 1; i <= row + 3; i++)
        for (int j = col + 1; j <= col + 3; j++)
            if (a[i][j] == num)
                return 0;

    return 1;
}

int solve(int x, int y)
{
    if (a[x][y] != 0)
    {
        if (x == 9 && y == 9)
            count1++;
        else if (x != 9 && y == 9)
            solve(x + 1, 1);
        else
            solve(x, y + 1);
    }
    else
    {
        for (int num = 1; num <= 9; num++)
        {
            if (check(x, y, num))
            {
                a[x][y] = num;
                if (x == 9 && y == 9)
                    count1++;
                else if (x != 9 && y == 9)
                    solve(x + 1, 1);
                else
                    solve(x, y + 1);
                a[x][y] = 0;
            }
        }
    }
}

main()
{
    freopen("test3.txt","r", stdin);
    for (int i = 1; i <= 9; i++)
        for (int j = 1; j <= 9; j++)
            cin >> a[i][j];

    solve(1, 1);
    cout << count1;
}