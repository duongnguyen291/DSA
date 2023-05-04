#include <stdio.h>
typedef struct Node{
    int data;
    struct Node *next; // pointer to successor
}Node;

Node *makeNode(int n){
    //alocate memory for a new node
    Node *p = (Node*) malloc(sizeof(Node));
    //Node *p = New Node
    p->data = n;
    p->next = NULL;
    return p;
}
int main(){
    Node *head; //pointer to the first elenment of the list
    printf("%d", sizeof(Node));
    return 0;
}