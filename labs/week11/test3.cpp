//Problem: Chapter 4. General Tree manipulation and traversal
#include <bits/stdc++.h>
using namespace std;
typedef struct node{
    int data; 
    node *mostLeftChild;
    node *rightSibling;
}node;
node* head;
node *makeNode(int u){
    node *new_node = new node();
    if(new_node == NULL){
        cout << "Memory allocation failed\n";
        exit(1);
    }
    new_node->data = u;
    new_node->mostLeftChild = new_node->rightSibling = NULL;
    return new_node;
}
//viết hàm findNode tìm node có giá trị v trong cây
node *findNode(node *head,int v){
    if(head == NULL) return NULL;
    if(head->data == v) return head;
    node *p = findNode(head->mostLeftChild,v);
    if(p != NULL) return p;
    return findNode(head->rightSibling,v);
}
//root->leftmost_child->righ
void preOrder(node *root){
    if(root == NULL) return;
    cout << root -> data;
    node *p = root->mostLeftChild;
    while(p!=NULL){
        preOrder(p);
        p = p->rightSibling;
    }
}
//leftmost->right->root
void postOrder(node *root){
    //Base case
    if(root == NULL) return;
    //1.Leftmost subtree of root
    node *p = root->mostLeftChild;
    while(p!=NULL){
        postOrder(p);
        p = p->rightSibling;
    }
    //2.Root 
    cout << root->data;
}
//left->root->right
void inOrder(node *root){
    //Base case 
    if(root == NULL) return;
    node *p = root->mostLeftChild;
    inOrder(p);
    cout << root->data;
    while(p!=NULL){
        p = p->rightSibling;
        inOrder(p);
    }
}
void insertNode(node *root, int u, int v){
    if(findNode(root,u) != NULL) return;
    node *p = findNode(root,v);
    if(p == NULL) return;
    
    node *left = p->mostLeftChild;
    if(left == NULL){ //nếu như p ko có con nào
        p->mostLeftChild = makeNode(u);
    }
    else{
        // nếu như p có ít nhất 1 con
        node *right = left;
        while(right->rightSibling != NULL) right =  right->rightSibling;
        right->rightSibling = makeNode(u);

    }  
}


int main(){
    freopen("test3.txt","r",stdin);
    string s;
    int u , v;
    while(1){
        cin >> s;
        if(s == "*") break;
        else if(s == "MakeRoot"){
            int id1;
            cin >> id1;
            head = makeNode(id1);
        }
        else if(s == "Insert"){
            cin >> u >> v;
            insertNode(head,u,v);
        }
        else if(s == "PreOrder"){
            preOrder(head);
            cout << "\n";
        }
        else if(s == "PostOrder"){
            postOrder(head);
            cout << "\n";
        }
        else if(s == "InOrder"){
            inOrder(head);
            cout << "\n";
        }
    }
    return 0;
}