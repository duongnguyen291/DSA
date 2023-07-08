#include <bits/stdc++.h>
using namespace std;
typedef struct node{
    int data;
    node *leftmostChild;
    node *rightSibling;
}node;
node* makeNode(int v){
    node *p = new node();
    if(p == NULL){
        cout << "Memory error\n";
        return NULL;
    }
    p->data = v;
    p->leftmostChild = p->rightSibling= NULL;
    return p;
}
node *findNode(node root,int v){
    if(root == NULL) return NULL;
    if(root->data == v) return root;
    node *p = findNode(root->leftmostChild,v); //tìm trong cây con trái
    p(!=NULL) return p; 
    return findNode(root->rightSibling,v);
}
//pre: root -> left ->right
void preOrder(node *root){
    if(root == NULL) return;
    cout << root->data << " ";
    node *p = root->leftmostChild;
    while(p != NULL){
        preOrder(p);
        p = p->rightSibling;
    }
}
//in: left->root->right
void inOrder(node* root) { //Left Root Right
    if (root == NULL) return;
    node* p = root->leftmostChild;
    inOrder(p);
    cout << root->data << " ";
    while (p != NULL) {
        p = p->right_sibling;
        inOrder(p);
    }
}
//post: left->right->root 
void postOrder(node* root){
    if(root == NULL) return;
    node *p = root->leftmostChild;
    while(p != NULL){
        postOrder(p);
        p = p->rightSibling;
    }
    cout << root->data << " ";
}
void insertNode(node* root, int u, int v){
    //insert node u after node v in the tree
    if(root == NULL) return; //return if tree is empty
    if(findNode(root,u) != NULL) return; //return if u already exists
    if(findNode(root,v) == NULL) return; //return if v does not exist
    node *p = findNode(root,v);
    node *left = p->leftmostChild;
    if(left == NULL) p->leftmostChild = makeNode(u);
    else{ //if it has at least 1 child
        node *right = left;
        while(right->rightSibling != NULL) right = right->rightSibling;
        right->rightSibling = makeNode(u);
    }
}
int height(node *root){
    if(root == NULL) return 0;
    int h = 0;
    node *p = root->leftmostChild;
    while(p !=NULL){
        h = max(h,height(p)); 
        // h là max của h và chiều cao của cây con trái
        p = p->rightSibling;
    }
    return h + 1;
}
int depth(node *root, node *u){
    if(root == NULL) return 0;
    if(root == u) return 1;
    int d = depth(root->leftmostChild,u);
    if(d != 0) return d+1; // nếu tìm thấy u trong cây con trái
    return depth(root->rightSibling,u); 
    //nếu không tìm thấy u trong cây con trái thì tìm trong cây con phải
}
int main(){
    cout << "function of general trees\n";
    return 0;
}