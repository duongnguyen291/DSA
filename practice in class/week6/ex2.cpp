#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *next;
};
//makeNode 
int *makeNode(int X){
    node *new_node = new node();
    new_node->data = X;
    new_node->next = NULL;
    return new_node;
}
int main(){


    return 0;
}