//Chapter 6. BST - Insertion and PreOrder Traversal
#include <bits/stdc++.h> 
using namespace std;
typedef struct node{
    int data;
    node *left;
    node *right;
}node;
node* root = NULL;
node* tree[(int)1e5+10];

node *makeNode(int x){
    node *p = new node();
    if(p == NULL){
        cout << "Memory error\n";
        exit(1);
    }
    p->data = x;
    p->left = p->right = NULL;
    return p;
}
void makeRoot(int x){
    node *p = makeNode(x);
    root = p;
    tree[x] = p;
}
void preOrder(node *r){
    if(r == NULL) return;
    cout << r->data<< " ";
    preOrder(r->left);
    preOrder(r->right);    
}
node *insertNode(node *r, int x){
    //time complexity: O(h) h: the height of tree
    if(r == NULL) {
        r = makeNode(x);
    }
    if(x == r->data) return r;
    else if(x < r->data){
        r->left = insertNode(r->left, x);
        node *temp = insertNode(r->left, x);
        r->left = temp;
        return r;
    }
    else{
        node *temp = insertNode(r->right, x);
        r->right = temp;
        return r;
    }
}
int main(){
    freopen("test3.txt","r",stdin);
    string s;
    for(int i = 0; i < 100010;i++) tree[i] = NULL;
    while(true){
        cin >> s;
        if(s == "#") break;
        else if(s == "insert"){
            int k;
            cin >> k;
            root = insertNode(root,k);
        }
    }
    preOrder(root);
    
    return 0;
}