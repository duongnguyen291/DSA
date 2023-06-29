//roblem: Chapter 6. BST Creation and Query about PreOrder and PostOrder Traversal
#include <bits/stdc++.h>
using namespace std;
typedef struct node{
    int id;
    node *left;
    node *right;
}node;

node *makeNode(int u){
    node *newNode = NULL;
    newNode = new node(); 
    if(newNode == NULL) {cout << "Out of memory\n"; exit(1);}
    newNode->id  = u;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

//root->left->right
void preOrder(node *r){
    if(r == NULL) return;
    cout << r->id << " ";
    preOrder(r->left);
    preOrder(r->right);    
}
node* insertRecursive(node* root, int key) {
        if (root == nullptr) {
            return makeNode(key);
        }

        if (key < root->id) {
            root->left = insertRecursive(root->left, key);
        } else if (key > root->id){
            root->right = insertRecursive(root->right, key);
        }

        return root;
    }
void postOrder(node *r){
    if(r == NULL) return;
    postOrder(r->left);
    postOrder(r->right);
    cout << r->id << " ";
}

int main(){
    string s;
    freopen("test1.txt","r",stdin);
    node *root = NULL;
    while(true){
        cin >> s;
        if(s == "insert"){
            int id;
            cin >> id;
            //tìm vị trí để add id vào
            root = insertRecursive(root,id);
        }
        else if(s == "preorder"){
            preOrder(root);
            cout << "\n";
        }
        else if(s == "postorder"){
            postOrder(root);
            cout << "\n";   
        }
        else if(s == "#"){
            break;
        }
    }
    return 0;
}

