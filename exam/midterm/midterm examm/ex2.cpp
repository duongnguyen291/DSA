#include <bits/stdc++.h>
using namespace std;
typedef struct library{
    char id[10];
    char book[20];
    char day[15];
}library;
library data[101];
typedef struct numberBook{
    char book[20];
    int count;
}numberBook;
int main(){
    int i = 0;
    freopen("test2.txt","r",stdin);
    do{
        scanf("%s %s %s",data[i].id,data[i].book,data[i].day);
        i++;
    }while(strcmp(data[i-1].id,"*"));
    //tạo mảng lưu số sách
    



}