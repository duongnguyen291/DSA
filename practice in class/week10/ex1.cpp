
#include <bits/stdc++.h>
using namespace std;
typedef struct tree{
    int data;
    tree *left;
    tree *right;
}tree;
tree *Root;
int cnt;
int countNode(tree *r){
    if(r == NULL ) return 0; 
    else{
        cnt++;
        tree *p = r->left;
        while(p!=NULL){
            preOrder(p);
            p = p ->right;
        }
    }
    return cnt;
}
int countLeaves(tree *r){//số nút không có con
    if(r == NULL ) return 0; 
    else{
        tree *p = r->left;
        if(p == NULL) cnt++;
        while(p!=NULL){
            cnt +=countLeaves(p);
            p = p ->right;
        }
    }
    return cnt;
}
int heightNode(tree *r){= // 1 + max of height node of subtree
    int result = 0;
    if(r == NULL ) return 0; 
    else{
        tree *p = r->left;
        if(p!= NULL) cnt++;
        while(p!=NULL){
            cnt +=countLeaves(p);
            p = p ->right;
        }
        result = min(result,cnt);
    }
    return result;
}
void preOrder(tree *r){
    if(r ==NULL) return;
    else{
    cout << r->data;
    tree *p = r->left;
    while(p!=NULL){
        preOrder(p);
        p = p->right;
    }
    }
}
void postOrder(tree *r){
    if(r ==NULL) return;
    else{
    tree *p = r->left;
    while(p!=NULL){
        postOrder(p);
        p = p->right;
    }
    cout << r->data;
    }
}
void inOrder(tree *r){
    if(r ==NULL) return;
    else{
    tree *p = r->left; inOrder(p);
    cout << r->data;//visit root
    if(p != NULL) p = p->right;
    while(p!=NULL){
        inOrder(p);
        p = p->right;
    }
    }
}
int main(){


    return 0;
}