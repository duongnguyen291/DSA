/*A = [1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89]
B = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 13, 100]
viết function C tạo ra mảng chỉ chứa các phần tử chung của A và B
List D chưa các phần tử có trong A nhưng không có trong B*/
#include <bits/stdc++.h>
using namespace std;
int c[100];
int d[100];
void printArr(int *a, int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}
int n = 11, m = 15, k = 0, p = 0;
void Arr(int *a, int *b, int *c, int *d)
{   
   int i = 0, j = 0;
    // tạo mảng C chứa các phần tử chung của A và B
    while (i <= n && j <= m){
        if (a[i] == b[j]){
            c[k] = a[i];
            k++; i++; j++;
        }
        else if (a[i] < b[j] && i <= n){
            if(a[i] != c[k-1]){
                d[p++] = a[i];
            }
            i++;
        }
        else if (a[i] > b[j] && j <= m)
            j++;
    }
    //xu ly not mang A con lai cho vao mang D
    while (i < n){
        d[p++] = a[i];
        i++;
    }
}
int main()
{
    int a[11] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
    int b[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 13, 100};
    Arr(a, b, c, d);
    printArr(c, k);
    printArr(d, p);
}