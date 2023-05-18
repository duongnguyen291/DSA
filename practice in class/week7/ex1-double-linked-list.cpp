#include <bits/stdc++.h>
using namespace std;
//double linked list
struct node{
    int data;
    node *prev;
    node *next;
};
void DeletaNode(node *p, node *head, node *tail){
    if(head == NULL) cout << "Empty list" << endl;
    else{
        if(p == head) head = head->next;//first element
        else p->prev->next =  p ->next;
        if(p->next != NULL ) p->next->prev = p->prev;
        else tail p = p->prev;
        free(p)
    }
}
void InsertNode(int X, node *p, node *head, node *tail){
    if(head == NULL){
        head = new node(); //list is empty
        head->data = X;
        head->prev = NULL;
        head->next = NULL;
    }
    else{
        node *new_node; new_node = new node();
        new_node->data = X;
        new_node->prev = p;
        new_node->next = p->next;
        if(p->next  != NULL){
            p->next->prev = new_node;
            p->next = new_node;
        }
    }
}
int main(){
    node *head, *tail, *p;
    *head = new node();
    *tail = new node();
    *p = new node();


}