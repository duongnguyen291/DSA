#include <stdio.h>
#define maxn 1000000
int a[maxn];
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void printArray(int *a, int size){
    for(int i = 0;i < size;i++) printf("%d ", a[i]);
    printf("\n");
}
void bubbleSort(int *a, int size){
    for(int i = 0;i < size;i++){
        for(int j =  0;j < size - i-1;j++){
            if(a[j] > a[j+1]) swap(&a[j], &a[j+1]);
        }
    }
}
void selectionSort(int *a, int size){
    int min;
    for(int i = 0;i < size - 1;i++){
        min = i;
        for(int j = i+1; j < size;j++){
            if(a[min] > a[j]){ 
                min = j;
            }
        }
        swap(&a[i], &a[min]);
    }
}
void insertionSort(int *a, int size){
    for(int i = 1;i <size;i++){
        int pos = i;
        int temp = a[pos];
        while(pos>0 && temp < a[pos-1]){
            a[pos] = a[pos-1];
            pos--;
            a[pos] = temp;
        }
    }
}
int main(){
    freopen("test1.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for(int i = 0;i < n;i++) scanf("%d", &a[i]);
    insertionSort(a,n);
    printArray(a,n);
    printf("test\n");
    return 0;
}