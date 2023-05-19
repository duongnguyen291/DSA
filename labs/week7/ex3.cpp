//Problem: Chapter 3 - Linked list Manipulation
#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *next;
};

node *makeNode(int v){
    node *new_node = new node();
    new_node->data = v;
    new_node->next = NULL;
    return new_node;
}
node *InsertToLast(node *head, int X){ //pass by value
    node *new_node = makeNode(X);
    if(head == NULL) head = new_node;
    else{
        node *last = head;
        while(last->next != NULL) last = last->next; //move to the last node
        last->next = new_node;
    }
    return head;
}
//addfirst k

node *findNode(node *head, int k){
    node *cur = head;
    while(cur!=NULL){
        if(cur->data == k) break;
        cur = cur->next;
    }
    return cur;
}
node *InsertToHead(node *head, int X){
    if(head == NULL) return makeNode(X);
    node *new_node = makeNode(X);
    new_node -> next = head;
    return new_node;
}
node *InsertAfter(node *head, int u,int v){
    if(head == NULL) return NULL;
    node *p = findNode(head,v);
    if(p == NULL) return head;
    node *new_node = makeNode(u);
    new_node -> next = p->next;
    p->next = new_node;
    return head;
}
node *InsertBefore(node *head, int u, int v){
    if(head == NULL) return NULL;
    if(head ->data == v ) return InsertToHead(head,u);
    node *prev = NULL, *p = head;
    while(p!=NULL){ 
        if(p->data = v) break;
        prev = p;
        p = p->next;
    }   
    if(p == NULL) // tức là không tồn tại  p = v
        return head;
    node *new_node = makeNode(u);
    prev->next = new_node;
    new_node->next = p;
    return head;
}
node *removeNode(node *head, int k){
    if(head == NULL) return NULL;
    if(head->data = k){ //vị trí k ở đầu
        node *temp = head;
        head = head ->next;
        free(temp);
        return head;
    }
    else{   //vị trí k ở giữa hoặc cuối
        node *prev = NULL;
        node *p = head;
        while(p!=NULL){
            if(p->key == k) break;
            prev = p; p = p->next;
        }
        if(p!=NULL){
            prev->next = p->next;
            free(p);
        }
        return head;
    }
}
node *revert(node *head){
    node *before, *cur = head,*after = cur->next;
    while(cur!=NULL){
        after = cur->next;
        cur->next = before;
        before = cur;
        cur = after;
    }
    head = cur;
}
void printList(node *head){
    node *cur = new node();
    for(cur = head; cur !=NULL;cur= cur->next){
        cout << cur->data;
        
    }
}
int main(){
    int n,v,k;
    node *head;
    head = NULL;
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> v;
        head = InsertToLast(head,v);
    }
    string s;
    while(true){
        cin >> s;
        if(strcmp(s,"#") == 0) break;
        if(strcmp(s,"addlast") == 0){
            cin >> k;
            if(findNode(head, k) == NULL)
                head = InsertToLast(head, k);
        }
        if(strcmp(s,"addfirst") == 0){
            cin >> k;
            head = InsertToHead(head, k);
        }
        if(strcmp(s,"addAfter") == 0){
            int d,m;
            cin >> d >> m ;
            if(findNode(head, d) != NULL)
                head = InsertAfter(head,m,d);
        }
        if(strcmp(s,"addBefore") == 0){
            int d,m;
            cin >> d >> m ;
            if(findNode(head, d) != NULL)
                head = InsertBefore(head,m,d);
        }
        if(strcmp(s,"remove") == 0){
            cin >> k;
            if(findNode(head,k) != NULL)
            head = removeNode(head, k);
        }
        if(strcmp(s,"reverse") == 0){
            cin >> k;
            if(findNode(head,k) != NULL)
            head = removeNode(head, k);
        }


    }
    return 0;
}