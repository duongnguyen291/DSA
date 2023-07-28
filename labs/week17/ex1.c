//Chapter 6. Hash Over Strings
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int n,m;

int main(){
    char s[201];
    freopen("test1.txt","r",stdin);
    scanf("%d %d",&n,&m);
    int ans = 0;
    for(int k = 0; k < n;k++){
        ans = 0;
        scanf(" %s", &s);
        for(int i = 0; i < strlen(s);i++){
            ans = (ans*256 + s[i]) % m;
        }
        printf("%d\n",ans);
    }
    return 0;
}