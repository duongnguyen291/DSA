#include <stdio.h>
typedef struct{
    char id[10];
    char name[30];
    double math;
    double physical;
}NoteType;
typedef struct node{
    NoteType data;
    node *next;
};


int main(){

    return 0;
}