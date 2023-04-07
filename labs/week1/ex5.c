#include <stdio.h>
#include <string.h>
#define n 1000

int check(char *a,char *b, char *c, int i){
    if(i + strlen(a) > strlen(c)) return 0;
    for(int j = 0; j < strlen(a); j++){
        if(a[j] != c[j+i]) return 0;
    }
    return 1;
}
int main(){
    char a[n], b[n], c[n];
    scanf(" %[^\n]%*c", a);
    scanf(" %[^\n]%*c", b);
    scanf(" %[^\n]%*c", c);
    printf("\n%s ", a);
    printf("\n%s ", b);
    printf("\n%s ",c );

    int k = 0;
    char temp[n];
    for(int i = 0; i < strlen(c) ; i++){
        if(check(a,b,c,i)){
            for(int j = 0; j < strlen(b); j++){
                temp[j + k] = b[j];
            }
            k = k + strlen(b);
            i += strlen(b) - 1;
        }
        else {
            temp[k] = c[i]; 
            k++;
        }
    }
    printf("\n%s ", temp);
    return 0;
}