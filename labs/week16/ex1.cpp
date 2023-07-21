#include <bits/stdc++.h>
using namespace std;
long long sum1 = 0;
int check = 1;
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
node *findNode(node *r,int v){
    //find node with id = v on the 
    if(r == NULL) return NULL;
    if(r->data == v) return r;
    node *result = findNode(r->left,v);
    if(result != NULL) return result;
    return findNode(r->right,v);   
}

node *addRight(node *r, int u, int v){
    if(findNode(r, u) != NULL) return r;
    node *p = findNode(r,v);
    if(p == NULL) return r;
    node *newNode = makeNode(u);
    if(p->right != NULL){
        if(p->data > u) check = 0;
        sum1+=u;
        newNode->right = p->right;
        p->right->parent = newNode;
        p->right = newNode;
    }else{
        if(p->data > u) check = 0;
        sum1+=u;
        p->right = newNode;
    }
    return r;
}
node *addLeft(node *r, int u, int v){
    if(findNode(r, u) != NULL) return r;
    node *p = findNode(r,v);
    if(p == NULL) return r;
    node *newNode = makeNode(u);
    if(p->left != NULL){
        if(p->data < u) check = 0;
        sum1+=u;
        newNode->left = p->left;
        p->left->parent = newNode;
        p->left = newNode;
    }else{
        if(p->data < u) check = 0;
        sum1+=u;
        p->left = newNode;
    }
    return r;
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
int main(){
    node *root = NULL;
    freopen("test1.txt","r",stdin);
    string s;
    int cnt = 0;
    while(true){
        cin >> s;
        cnt++;
        if(s == "*") break;
        else if(s == "MakeRoot"){
            int x;
            cin >> x;
            sum1+=x;
            root = insertNode(root,x);
        }
        else if(s == "AddRight"){
            int u,v;
            cin >> u >> v;
            root = addRight(root,u,v);
        }
        else if(s == "AddLeft"){
            int u,v;
            cin >> u >> v;
            root = addLeft(root,u,v);

        }
    }
    cout << check << " " << sum1 << "\n";
    return 0;
}