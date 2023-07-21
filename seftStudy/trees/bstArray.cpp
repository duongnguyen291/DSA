//Chapter 6. Check if a given binary tree is a BST
/*note: dùng mảng node tree[10e5] để lưu địa chỉ các node
với index chính là data của node luôn*/
#include <bits/stdc++.h> 
using namespace std;
typedef struct node{
    int data;
    node *left;
    node *right;
}node;
node* root = NULL;
node* tree[(int)1e5+10];
long long sum1 = 0;
int check = 1;
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
void addRight(int child, int parent){
    //check xem node parent có tồn tại không
    if(tree[parent] == NULL) return;
    //check xem node child đã tồn tại chưa
    if(tree[child] != NULL) return;
    node *p = tree[parent];
    if(p->right != NULL){
        //p đã có con phải rồi
        if(p->data > child) check = 0;
        sum1+=child;
        node *newNode = makeNode(child);
        newNode->right = p->right;
        p->right = newNode;
        tree[child] = newNode;
    }
    else{
        //p chưa có con phải
        if(p->data > child) check = 0;
        sum1+=child;
        node *newNode = makeNode(child);
        p->right = newNode;
        tree[child] = newNode;
    }
}
void addLeft(int child, int parent){
    if(tree[parent] == NULL) return;
    //check xem node child đã tồn tại chưa
    if(tree[child] != NULL) return;
    node *p = tree[parent];
    if(p->left != NULL){
        //p đã có con trái rồi
        if(p->data < child) check = 0;
        sum1+=child;
        node *newNode = makeNode(child);
        newNode->left = p->left;
        p->left = newNode;
        tree[child] = newNode;
    }
    else{
        //p chưa có con trái
        if(p->data < child) check = 0;
        sum1+=child;
        node *newNode = makeNode(child);
        p->left = newNode;
        tree[child] = newNode;
    }
}

int main(){
    // freopen("test1.txt","r",stdin);
    string s;
    for(int i = 0; i < 100010;i++) tree[i] = NULL;
    while(true){
        cin >> s;
        if(s == "*") break;
        else if(s == "MakeRoot"){
            int x;
            cin >> x;
            sum1+=x;
            makeRoot(x);
            
        }
        else if(s == "AddRight"){
            int u,v;
            cin >> u >> v;
            addRight(u,v);
        }
        else if(s == "AddLeft"){
            int u,v;
            cin >> u >> v;
            addLeft(u,v);
        }
    }
    cout << check << " " << sum1 << "\n";
    return 0;
}