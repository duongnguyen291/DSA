#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *next;
};
//makeNode 
int makeNode(int x){
    node *new_node = new node();
    new_node->data = x;
    new_node->next = NULL;
    return new_node;
}
//insert node at the head 
node *InsertToHead(node *head, int X){
    node *new_node = makeNode(X);
    new_node->next = head;
    head = new_node;
    return head;
}
//insert node after 
node *InsertAfter(node *cur, int X){
    node *new_node = makeNode(X);
    new_node->next = cur->next;
    cur-> next = new_node;
    return new_node;
}
//insert node before
node *InsertBefore(node *cur, int X){
    node *new_node = makenode(X);
    if(head == NULL) head = new_node;
    else if(cur == head){
        head = new_node;
        new_node->next = cur;
    }    
    else{
        node *prev = head;
        while(prev->next != cur) prev = prev->next;
        prev->next = new_node;
        new_node-> next =  cur; 
    }
    return new_node;
}
node *InsertToLast(node *head, int X){
    node *new_node = makeNode(X);
    if(head == NULL) head = new_node;
    else{
        node *last = head;
        while(last->next!=NULL) last = last->next;
        last->next = new_node;
    }
    return head;
}
void printlist(node *head){
    node *cur = new node();
    for(cur  = head; cur != NULL; cur = cur ->next){
        cout << cur->data;
    }
}
node *deleteFristNode(node *head,node *del){
    if(head == del) //del is the pointer of the first node of the list
    {
        head = del->next;
        free(del);
    }
    else{ //del is the pointer of the middle/last node of the list
    node *prev = head;
    while(prev->next!= del) prev = prev->next;
        prev->next = del->next;
        free(del);
    }
    return head;
}
int main(){
    int n,v;
    cout << "Enter n = ";
    cin >> n;
    node *head = NULL;
    for(int i = 1; i<=n ;i++){
        cout << "Enter the number " <<i<< ": ";
        cin >> v;

    }
    cout << "Value in the linked list: ";
    printlist(head);


    return 0;
}