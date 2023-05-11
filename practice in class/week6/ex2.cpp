#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *next;
};
//<create a new node new node at the begging of the singled linked>
//new_node -> next = head
//head = new_node
node *InsertToHead(node *head, int X){
    node *new_node = 
}
void printlist(node *head){
    node *cur = new node();
    for(cur  = head; cur != NULL; cur = cur ->next){
        cout << cur->data;
    }
}
int main(){


    return 0;
}