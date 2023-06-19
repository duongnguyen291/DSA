//Problem: Chapter 4. General Tree manipulation query depth - height
#include <bits/stdc++.h>
using namespace std;
typedef struct node{
    int id;
    node *mostLeftChild;
    node *rightSibling;
}node;

node *makeNode(int id){
    node *newNode = NULL;
    // newNode = new node;
    newNode = (node *) malloc(sizeof(node )); //nếu dùng hàm malloc
    if(newNode == NULL) {cout << "Out of memory\n"; exit(1);}
    newNode->id  = id;
    newNode->mostLeftChild = NULL;
    newNode->rightSibling = NULL;
    return newNode;
}
//gốc-> trái ->phải
void preOrder(node *head){
    if(head == NULL) return;
    cout << head->id<< " ";
    node *p = head->mostLeftChild;
    while(p!=NULL){
        preOrder(p);
        p = p->rightSibling;
    }
}
int height(node *head){
    if(head == NULL) return 0;
    int h = 0;
    node *p = head->mostLeftChild; 
    while(p != nullptr){
        h = max(h,height(p));
        p = p -> rightSibling;
    }
    return h+1;
}

int calculateDepthLCRS(node* root, node* u) {
    if (root == NULL || u == NULL) {
        return 0;
    }
    
    if (root == u) {
        return 0;
    }
    
    int depth = calculateDepthLCRS(root->mostLeftChild, u);
    if (depth != -1) {
        return depth + 1;
    }
    
    return calculateDepthLCRS(root->rightSibling, u);
}
node *findNode(node *head,int v){
    if(head == NULL) return NULL;
    if(head->id == v) return head;
    node *p = findNode(head->mostLeftChild,v);
    if(p != NULL) return p;
    return findNode(head->rightSibling,v);
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
    string s;
    //freopen("test4.txt","r",stdin);
    node *root = NULL;
    while(true){
        cin >> s;
        if(s == "MakeRoot"){
            int id;
            cin >> id;
            root = makeNode(id);
        }
        else if(s == "Insert"){
            int u,v;
            cin >> u >> v;
            insertNode(root,u,v);
        }
        else if(s == "Height"){
            int u;
            cin >> u;
            cout << height(findNode(root,u)) << "\n";
        }
        else if(s == "Depth"){
            int u;
            cin >> u;
            cout << height(findNode(root,u)) << "\n";
        }
        else if(s == "*"){
            break;
        }
    }

    return 0;
}