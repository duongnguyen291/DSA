//yêu cầu nhập vào kí tự. liệt kê các chữ cái và số lần lặp lại
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define alphabet_len 26

int main(){
    int count[alphabet_len] = {0};
    char c[100];
    printf("\nEnter character: ");
    scanf(" %[^\n]%*c", c);
    // printf("\nPrintf: %s",c);
    for(int i = 0 ; i < strlen(c);i++){
        if(c[i] >= 'a' && c[i] <= 'z'){
            count[c[i] - 'a']++;
        }
    }
    for(int i = 0; i < 26;i++){
        if(count[i] > 0) printf("\nThe letter %c appears %d time \n",i + 'a', count[i] );
    }

    return 0;
}