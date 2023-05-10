//hoán vị
#include <stdio.h>
int out[30],n,luu[30];

void zui(int p){
    if(p==n+1){
        for(int i=1;i<=n;i++)printf("%d ",out[i]);
        printf("\n");
        return;
    }
    for(int i=1;i<=n;i++){
        if(luu[i]==0){
            luu[i]=1;
            out[p]=i;
            zui(p+1);
            luu[i]=0;
        }
    }
}

int main(){
    scanf("%d",&n);
    zui(1);
}