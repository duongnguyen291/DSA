#include <bits/stdc++.h>
using namespace std;
typedef struct node{
    int data;
    node *left,*right, *parent;
}node;
node* makeNode(int v){
    node *p = new node();
    if(p == NULL){
        cout << "Memory error\n";
        return NULL;
    }
    p->data = v;
    p->left = p->right = p->parent =NULL;
    return p;
}
void preOrder(node *r){
    if(r == NULL) return;
    cout << r->data<< " ";
    preOrder(r->left);
    preOrder(r->right);    
}
node *findNode(node *r,int v){
    //find node with id = v on the 
    if(r == NULL) return NULL;
    if(r->data == v) return r;
    node *result = findNode(r->left,v);
    if(result != NULL) return result;
    return findNode(r->right,v);   
}
node *findMax(node *r){
    if(r == NULL) return NULL;
    node *p = r->right;
    while(p->right !=NULL){
        p = p->right;
    }
    return p;
}
node *findMin(node *r){
    if(r == NULL) return NULL;
    node *p = r->left;
    while(p->left !=NULL){
        p = p->left;
    }
    return p;
}
node *predecessor(node *r, node *x){
    if(x->left != NULL) return findMax(x->left);
    node *p = x->parent;
    while(p!=NULL && x == p->left){
        x = p;
        p = p->parent;
    }
    return p;
}
node *successor(node *r, node *x){
    if(x->right != NULL) return findMax(x->right);
    node *p = x->parent;
    while(p!=NULL && x == p->right){
        x = p;
        p = p->parent;
    }
    return p;
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
        temp->parent = r;
        return r;
    }
    else{
        node *temp = insertNode(r->right, x);
        r->right = temp;
        temp->parent = r;
        return r;
    }
}
node *insertNode2(node *r, int x){
    node *p = NULL; //p point to parent of root
    while(r !=NULL){
        if(x< r ->data){p = r;r = r->left;}
        else if(x > r->data){p = r;r = r->right;}
        else return r;
    }
    node *temp = makeNode(x);
    if(x < p->data) p->left = temp;
    else p->right = temp;   
    temp->parent = p;
    return temp;
}
node *deleteNode(node* root, int k){
    // Base case
    if (root == NULL)
        return root;
    // Recursive calls for ancestors of
    // node to be deleted
    if (root->data> k){
        root->left = deleteNode(root->left, k);
        return root;
    }
    else if (root->data < k) {
        root->right = deleteNode(root->right, k);
        return root;
    }
    // We reach here when root is the node to be deleted.
    // If one of the children is empty
    if (root->left == NULL) {
        node* temp = root->right;
        delete root;
        return temp;
    }
    else if (root->right == NULL) {
        node* temp = root->left;
        delete root;
        return temp;
    }
    // If both children exist
    else {
        node* succParent = root;
        // Find successor
        node* succ = root->right;
        while (succ->left != NULL) {
            succParent = succ;
            succ = succ->left;
        }
        // Delete successor.  Since successor
        // is always left child of its parent
        // we can safely make successor's right
        // right child as left of its parent.
        // If there is no succ, then assign
        // succ->right to succParent->right
        if (succParent != root)
            succParent->left = succ->right;
        else
            succParent->right = succ->right;
        // Copy Successor Data to root
        root->data = succ->data;
        // Delete Successor and return root
        delete succ;
        return root;
    }
}
int main(){
    node *root = NULL;
    freopen("test1.txt","r",stdin);
    string s;
    while(true){
        cin >> s;
        if(s == "*") break;
        else if(s == "insert"){
            int x;
            cin >> x;
            root = insertNode(root,x);
        }
        else if(s == "delete"){
            int x;
            cin >> x;
            root = deleteNode(root,x); //đang lỗi

        }
        else if(s == "print"){
            preOrder(root);
            cout << "\n";
        }
        else if(s == "findMax"){
            node *max = findMax(root);
            cout <<"\nMax of tree: "<< max->data << endl;
        }
        else if(s == "findMin"){
            node *min = findMin(root);
            cout <<"\nMin of tree:" <<min->data << endl;
        }
        else if(s == "predecessor"){
            int x;
            cin >> x;
            node *temp = findNode(root,x);
            node *pre = predecessor(root, temp);
            cout <<"\nPredecessor of node "<<x << ": "<<pre->data << endl;
        }
        else if(s == "successor"){
            int x;
            cin >> x;
            node *temp = findNode(root,x);
            node *suc = successor(root, temp);
            cout <<"\nSuccessor of node "<<x << ": "<<suc->data << endl;
        }
    }
    return 0;
}