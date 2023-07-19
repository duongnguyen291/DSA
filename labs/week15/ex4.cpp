//Chapter 6. Hash Over Integers
#include <bits/stdc++.h> 
using namespace std;
typedef struct node{
    int data;
    node *left, *right;
}node; 
node *makeNode(int v){
    node *p = new node();
    if(p == NULL){
        cout << "Memory allocation failed\n";
        exit(1);
    }
    p->data = v;
    p->left = p->right = NULL;
    return p;
}
node* findNode(node* r, int v) {
    if (r == NULL) return NULL;
    if (r->data == v) return r;
    node* p = findNode(r->left, v);
    if (p != NULL) return p;
    return findNode(r->right, v);
}


node* insertNode(node* r, int v) {
    node* p = findNode(r, v);
    if (p != NULL) return NULL; // Value already exists, return NULL
    if (r == NULL) {
        return makeNode(v); // Insert as root if tree is empty
    } else if (r->left == NULL) {
        r->left = insertNode(r->left, v); // Insert as left child if left child is null
    } else if (r->right == NULL) {
        r->right = insertNode(r->right, v); // Insert as right child if right child is null
    } else {
        r->left = insertNode(r->left, v); // Insert recursively into left subtree
        r->right = insertNode(r->right, v); // Insert recursively into right subtree
    }
    return r;
}
int main(){
    string s;
    node *r = NULL; //LƯU Ý, PHẢI KHAI BÁO *R = NULL, NẾU KHÔNG SẼ LỖI
    int k;
    freopen("test4.txt","r",stdin);
    //1.Read data
    while(true){
        cin >> s;
        if(s == "*") {
            break;
        }
        else{
            int k = stoi(s);
            r = insertNode(r, k); //lỗi ở đây
        }
    }
    //2.Command
    while(1){
        cin >> s;
        if(s == "***") break;
        else if(s == "find"){
            cin >> k;
            node *temp = findNode(r,k);
            if(temp == NULL) cout << "0\n";
            else cout << "1\n";
        }
        else if(s == "insert"){
            cin >> k;
            if(findNode(r, k) == NULL){
                r = insertNode(r,k);
                if(findNode(r,k) != NULL) cout << "1\n";
            }
            else cout << "0\n";
        }
    }


    return 0;
}