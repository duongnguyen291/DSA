#include <bits/stdc++.h>
using namespace std;
typedef struct node{
    int id;
    node *leftMostChild;
    node *rightSibling;
}node;

node *makeRoot(int u){
    node *newNode = new node();
    if(newNode == NULL){ cout << "Out of memory\n"; exit(1);}
    newNode->id = u;
    newNode->leftMostChild = newNode->rightSibling = NULL;
    return newNode;
    } 
node *findNode(node *head, int u){
    if(head == NULL) return NULL;
    if(head->id == u) return head;
    node *p = findNode(head->leftMostChild,u);
    if(p != NULL) return p;
    return findNode(head->rightSibling,u);
}
void insertNode(node *head, int u, int v){
    if(findNode(head,u) != NULL) return;
    node *p = findNode(head,v);
    if(p == NULL) return;

    node *left = p->leftMostChild;
    if(left == NULL) p->leftMostChild = makeRoot(u);
    else{
        node *right = left;
        while(right->rightSibling != NULL) right = right->rightSibling; \
        right->rightSibling = makeRoot(u);
    }
}
int CountLeaves(node *head){
    if(head == NULL) return 0;
    if(head->leftMostChild == NULL){ 
        // head = head ->rightSibling;
        return 1;
    }
    int cnt = 0;
    node *child = head->leftMostChild;
    while(child != NULL){
        cnt += CountLeaves(child);
        child = child->rightSibling;
    }
    return cnt;
}
int CountKChildren(node *head, int k, int result){
    if(head == NULL) return 0;
    int cnt = 0;
    node *p = head->leftMostChild;
    node *cur = p;  
    while(cur!=NULL){
        cnt++;
        cur = cur ->rightSibling;
    }
    if(cnt == k) 
        result++;
    while(p != NULL){
        result = CountKChildren(p,k,result);
        p = p->rightSibling;
    }
    return result;
}
int main(){
    
    freopen("test5.txt","r",stdin);
    node *head;
    string s;
    int u , v, k;
    while(1){
        cin >> s;
        if(s == "*") break;
        else if(s == "MakeRoot"){
            cin >> u;
            head = makeRoot(u);
        }
        else if(s == "Insert"){
            cin >> u >> v;
            insertNode(head,u,v);
        }
        else if(s == "CountLeaves"){
            cin >> u;
            cout << CountLeaves(findNode(head,u)) << "\n";
        }
        else if(s == "CountKChildren"){
            cin >> u >> k;
            cout << CountKChildren(findNode(head,u),k,0) << "\n";

        }
    }
    return 0;
}
/*
1
1
2
7
3
*/