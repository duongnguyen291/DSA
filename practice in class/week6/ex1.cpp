#include <bits/stdc++.h>
using namespace std;
// struct NoteType{
//     int math;
//     int physical;
// };
struct node{
    int data;
    node *next;
};
node *makeNode(int v) //allocate memory for a new node
{
node *p = new node();
//Node *p = new Node;
p->data = v; p->next = NULL;
return p;
}
//<create a new node new node at the beginng of the singled linked>
//new_node -> next = head
//head = new_node
node *InsertToHead(node *head, int X){
    node *new_node = makeNode(X);
    new_node -> next = head;
    head = new_node;
    return head;

}
void InsertToHead2(node **head, int X){
    node *new_node = makeNode(X);
    new_node->next = *head;
    *head = new_node;
}
void printlist(node *head){
    node *cur = new node();
    for(cur  = head; cur != NULL; cur = cur ->next){
        cout << cur->data;
    }
}
node *Insert_After(node *cur,int X){
    node *new_node = makeNode(X);
    // if(head == NULL) head = new_node;
        new_node ->next = cur->next;
        cur->next = new_node;
    
    return new_node;
}
node *Insert_Before(node *head,node *cur, int X){
    node *new_node = makeNode(X);
    if(head == NULL) head = new_node;
    else if(cur == head){
        head = new_node;
        new_node -> next = cur;
    }
    else{
        //determine the previous node of cur;
        node *prev = head;
        while(prev->next != cur) prev = prev->next;
        prev-> next = new_node;
        new_node->next = cur; 
    }
    return new_node;
}
node *Insert_Last(node *head, int X){ //pass by value
    node *new_node = makeNode(X);
    if(head == NULL) head = new_node;
    else{
        node *last = head;
        // while(last-> next != NULL) last = last->next; //move to the last node
        for(last = head; last->next!= NULL;last = last->next);
        last->next = new_node;
    }
    return head;
}
void Insert_Last2(node **head, int X){ //pass by reference 
    node *new_node = makeNode(X);
    if(*head == NULL) *head =new_node;
    else{
        node *last = *head;
        for(last = *head; last->next != NULL; last = last->next);
        last->next = new_node;
    }
}
int main(){
    // node *node1 = makeNode(1);
    // node *node2 = makeNode(2);
    // node *node3 = makeNode(3);
    // node1->next = node2;
    // node2->next = node3;
    // printlist(node1);
    int n,v;
    cout << "Enter n = "; cin >> n;
    node *head = NULL;
    for(int i = 1;i <= n; i++){
        cout << "Enter the number " << i << ":";
        cin >> v;
        //Node *insertToHead
        // head = Insert_Last(head,v);
        Insert_Last2(&head,v);
    }
    cout << "Value in the linked list: ";
    printlist(head);
    return 0;
}