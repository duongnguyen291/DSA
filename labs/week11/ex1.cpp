//chapter4: binary tree manipulation & traversal
#include <bits/stdc++.h>
using namespace std;
typedef struct node{
    int id;
    node *left;
    node *right;
}node;
node *makeNode(int id){
    node *newNode = NULL;
    // newNode = new node;
    newNode = (node *) malloc(sizeof(node )); //nếu dùng hàm malloc
    if(newNode == NULL) {cout << "Out of memory\n"; exit(1);}
    newNode->id  = id;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
void preOrder(node *r){
    if(r == NULL) return;
    cout << r->id << " ";
    preOrder(r->left);
    preOrder(r->right);    
}
void inOrder(node *r){
    if(r == NULL) return;
    inOrder(r->left);
    cout << r->id << " ";
    inOrder(r->right);    
}
void postOrder(node *r){
    if(r == NULL) return;
    postOrder(r->left);
    postOrder(r->right);    
    cout << r->id << " ";
}
node *findNode(node *r,int v){
    //find node with id = v on the 
    if(r == NULL) return NULL;
    if(r->id == v) return r;
    node *result = findNode(r->left,v);
    if(result != NULL) return result;
    return findNode(r->right,v);   
}
void addLeft(node *r, int u , int v){
//chen id  = u vào vị trí con trái của v(trừ u đã tồn tại, v ko tồn tại hoặc v đã có con trái)    
    if(findNode(r,u) != NULL) return; //check sự tồn tại của u
    node *temp = findNode(r,v);
    if(temp == NULL) return;
    if(temp->left !=NULL) return;
    temp->left = makeNode(u);
}
void addRight(node *r, int u , int v){
//chen id  = u vào vị trí con trái của v(trừ u đã tồn tại, v ko tồn tại hoặc v đã có con phải)    
    if(findNode(r,u) != NULL) return; //check sự tồn tại của u
    node *temp = findNode(r,v);
    if(temp == NULL) return;
    if(temp->right !=NULL) return;
    temp->right = makeNode(u);
}
int main(){
    string s;
    freopen("test1.txt","r",stdin);
    node *root = NULL;
    while(true){
        cin >> s;
        if(s == "MakeRoot"){
            int id;
            cin >> id;
            root = makeNode(id);
        }
        else if(s == "AddLeft"){
            int u,v;
            cin >> u >> v;
            addLeft(root, u, v);
        }
        else if(s == "AddRight"){
            int u,v;
            cin >> u >> v;
            addRight(root, u, v);
        }
        else if(s == "PreOrder"){
            preOrder(root);
            cout << endl;
        }
        else if(s == "InOrder"){
            inOrder(root);
            cout << endl;
        }
        else if(s == "PostOrder"){
            postOrder(root);
            cout << endl;
        }
        else if(s == "*"){
            break;
        }
    }


    return 0;
}