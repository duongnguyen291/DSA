//Problem: Chapter 2 - Linear Integer Equation - coefficent 1
#include <stdio.h>

void generate_collections(int n, int M, int* collection, int pos) {
    if (n == 1) {
        collection[pos] = M;
        for (int i = 0; i < pos; i++) {
            printf("%d ", collection[i]);
        }
        printf("%d\n", collection[pos]);
        return;
    }
    for (int i = 1; i <= M; i++) {
        collection[pos] = i;
        generate_collections(n-1, M-i, collection, pos+1);
    }
}

int main() {
    int n, M;
    scanf("%d%d", &n, &M);
    int collection[n];
    generate_collections(n, M, collection, 0);
    return 0;
}