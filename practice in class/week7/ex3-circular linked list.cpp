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
void printlist(node *head){
    node *cur = new node();
    for(cur  = head; cur != NULL; cur = cur ->next){
        cout << cur->data;
    }
}
int countNode(node *head){
    int count = 1;
    if(head == NULL) return 0;
    else{   
    node *cur = head;
        while(cur->next!=head) {
            cur = cur->next;
            count++;
        }
    }
    return count;
}
int main(){
    int n,v;



    return 0;
}