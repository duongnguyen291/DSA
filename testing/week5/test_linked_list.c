#include <stdio.h>
typedef struct{
    char id[10];
    char name[30];
    double math;
    double physical;
}NoteType;
xstruct node{
    NoteType data;
    struct node *next;
};


int main(){

    return 0;
}