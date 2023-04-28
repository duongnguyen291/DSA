#include <stdio.h>
int date[10000][20][40];
int main(){
    char s[5][10000];
    while(1){

        for(int i=1;i<=4;i++){
            scanf("%s",s[i]);
            if(s[i][0]=='*'){
                for(int i=0;i<10000;i++){
                    for(int j=1;j<=12;j++){
                        for(int k=1;k<=31;k++){
                            if(date[i][j][k]!=0)printf("%d-%02d-%02d %d\n",i,j,k,date[i][j][k]);
                        }

                    }
                }
                return 0;
            }
        }
        int dem=0;
        int haha=0;
        int y,m,d;
        for(int j=0;j<10;j++){
//                printf("fasdf\n");
            if(s[1][j]=='-'){
                if(dem==0){
                    y=haha;
                    dem++;
                    haha=0;
                }
                else if(dem==1){
                    m=haha;
                    haha=0;
                }
                continue;
            }
            int po=s[1][j]-'0';
            haha*=10;
            haha+=po;
        }
        d=haha;
//        printf("%d %d %d\n",y,m,d);
        date[y][m][d]++;
    }
}
