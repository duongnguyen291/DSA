//Problem: Chapter 6 - BST Creation and Query about PreOrder and PostOrder Traversal
#include <bits/stdc++.h>
using namespace std;
typedef struct node{
    int data;
    node *left,*right;
}node;
node *makeNode(int v){
    node *p = new node();
    if(p ==NULL) {
        cout << "memory error!";
        exit(1);
    }
    p->data=v; 
    p->left = p->right =NULL;
    return p;
}
node *insert(node *r, int v){
    if(r==NULL) return makeNode(v);
    if(v > r->data) {
        r->right = insert(r->right,v);
    }
    else if(v < r->data){
        r->left = insert(r->left,v);
    }
    return r;
}
void preOrder(nod   e *r){
    if(r==NULL) return;
    cout << r->data << " ";
    preOrder(r->left);
    preOrder(r->right);
}
void postOrder(node *r){
    if(r==NULL) return;
    postOrder(r->left);
    postOrder(r->right);
    cout << r->data << " ";
}
int main(){
    //freopen("test3.txt","r",stdin);
    node *root = NULL;
    string s;
    while(1){
        cin >> s;
        if(s == "#") break;
        else if(s=="insert"){
            int k;
            cin >> k;
            // cout <<"da vao insert";
            root = insert(root,k);
        }
        else if(s == "preorder"){
            // cout << "da vao";
            preOrder(root);
            cout <<"\n";
        }
        else if(s =="postorder"){
            postOrder(root);
            cout <<"\n";

        }
    }
    return 0;
}