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
node *findNode(node *head, int k){
    node *cur = head;
    while(cur!=NULL){
        if(cur->data == k) {
            return cur;    
        }
        cur = cur->next;
    }
    return NULL;
}
node *InsertToLast(node *head, int X){ //pass by value
    node *new_node = makeNode(X);
    if(head == NULL) head = new_node;
    else{
        node *p = findNode(head,X);
        if(p==NULL){
        node *last = head;
        while(last->next != NULL) last = last->next; //move to the last node
        last->next = new_node;
        }
    }
    return head;
}
//addfirst k


node *InsertToHead(node *head, int X){
    if(head == NULL) return makeNode(X);
    node *new_node = makeNode(X);
    new_node -> next = head;
    head = new_node;
    return head;
}
node *InsertAfter(node *head, int u,int v){
    if(head == NULL) return NULL;
    //check xem có v không
    node *p = findNode(head,v);
    if(p == NULL) return head;
    //check xem đã tồn tại u chưa
    node *q = findNode(head,u);
    if(q != NULL) return head;
    node *new_node = makeNode(u);
    new_node ->next = p->next;
    p->next = new_node;
    return head;
}
//lỗi không add được befor
node *InsertBefore2(node *head, int u, int v){
    if(head == NULL) return NULL;
    if(head ->data == v ) return InsertToHead(head,u);
    node *prev = NULL, *p = head;
    while(p!=NULL && p->data != v){
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
void addBefore(node **head,int x, int y)
{
    node *tmp = makeNode(x);
    if((*head)->data == x){
        tmp->next=(*head);
        *head = tmp;
    }
    else{
            node* tmp2 = *head;
        while(tmp2->next->data != y){
            tmp2 = tmp2->next;
        }
        tmp->next = tmp2->next;
        tmp2->next = tmp;
    }
}
//lỗi xóa hết phần tử
node *removeNode(node *head, int k){
    if(head == NULL) return NULL;
    while(head->data == k){ //vị trí k ở đầu
        node *temp = head;
        head = head ->next;
        free(temp);
    }
        node *prev = NULL;
        node *p = head;
        
        //vị trí k ở giữa hoặc cuối
        // while(p!=NULL){
        //     if(p->data == k) break;
        //     prev = p; p = p->next;
        // }
        // if(p!=NULL){
        //     prev->next = p->next;
        //     free(p);
        // }
            while (p != NULL) {
                if (p->data == k) {
                    node* temp = p;
                    prev->next = p->next;
                    p = p->next;
                    free(temp);
                } 
                else {
                    prev = p;
                    p = p->next;
                }
            }
    
    return head;
}
node *revert(node *head){
    node *before = NULL, *cur = head,*after = NULL;
    while(cur!=NULL){
        after = cur->next;
        cur->next = before;
        before = cur;
        cur = after;
    }
    head = before;
    return head;
}

void printList(node *head){
    node *cur = new node();
    for(cur = head; cur !=NULL;cur= cur->next){
        cout << cur->data <<" "; 
    }
}
void fun1(node *head){
    if(head == NULL) return;
    fun1(head->next);
    cout << head->data << " ";
}
int main(){
    int n,v,k;
    node *head;
    head = NULL;
    freopen("test3-2.txt","r",stdin);
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> v;
        head = InsertToLast(head,v);
    }
    string s;
    while(true){
        cin >> s;
        if(s == "#") 
            break;
        else if(s == "addlast"){
            cin >> k;
            if(findNode(head, k) == NULL)
                head = InsertToLast(head, k);
        }
        else if(s == "addfirst"){
            cin >> k;
            head = InsertToHead(head, k);
        }
        else if(s == "addafter"){
            int d,m;
            cin >> d >> m ;
            if(findNode(head, m) != NULL)
                head = InsertAfter(head,d,m);
        }
        else if(s == "addbefore"){
            int d,m;
            cin >> d >> m ;
            if(findNode(head, m) !=NULL)
                head = InsertBefore2(head,d,m);
        }
        else if(s == "remove"){
            cin >> k;
            if(findNode(head,k) != NULL)
            head = removeNode(head, k);
        }
        else if(s == "test"){
            fun1(head);
            cout << endl;
        }
        else if(s == "reverse"){
            if(head != NULL)
            head = revert(head);
            // Reverse(&head);
        }
        // printList(head);
    }
        // cout << 123;
    return 0;
}