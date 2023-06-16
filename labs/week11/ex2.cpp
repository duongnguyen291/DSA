//Problem: Chapter 4 - Check balanced binary tree and compute the height
#include <bits/stdc++.h>
using namespace std;
typedef struct node{
    int id;
    node *left;
    node *right;
}node;
typedef struct res{
    int h,z;
}res;
node *Node[50001];

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
void addLeftOptimize( int u, int v){
    if(Node[u] != NULL) return;
    if(Node[v] == NULL) return;
    if(Node[v]->left != NULL) return;
    Node[u] = makeNode(u);
    Node[v]->left = Node[u];
}
void addRightOptimize( int u, int v){
    if(Node[u] != NULL) return;
    if(Node[v] == NULL) return;
    if(Node[v]->right != NULL) return;
    Node[u] = makeNode(u);
    Node[v]->right = Node[u];
}
void addRight(node *r, int u , int v){
//chen id  = u vào vị trí con trái của v(trừ u đã tồn tại, v ko tồn tại hoặc v đã có con phải)    
    if(findNode(r,u) != NULL) return; //check sự tồn tại của u
    node *temp = findNode(r,v);
    if(temp == NULL) return;
    if(temp->right !=NULL) return;
    temp->right = makeNode(u);
}
res check1(node *root){
    //base case...
    res result; // store the result 
    if(root == NULL){
        result.h = 0;
        result.z = 1;
        return result;
    }
    res leftR = check1(root->left);
    res rightR = check1(root->right);
    result.h = max(leftR.h, rightR.h)+1;
    if(leftR.z==0) 
	{
		result.z=0; 
		return result;
	}
	if(rightR.z==0) 
	{
		result.z=0; 
		return result;
	}
    if(abs(leftR.h - rightR.h) > 1){
        result.z = 0; 
        return result;
    }
    else result.z = 1;
    return result;
}

int main(){
    string s;
    freopen("test2.txt","r",stdin);
    node *root = NULL;
    for(int i = 0;i < 50000;i++){
        Node[i] = NULL;
    }
    while(true){
        cin >> s;
        if(s == "MakeRoot"){
            int id;
            cin >> id;
            root = makeNode(id);
            Node[id] = root;

        }
        else if(s == "AddLeft"){
            int u,v;
            cin >> u >> v;
            // addLeft(root, u, v);
            addLeftOptimize(u,v);
        }
        else if(s == "AddRight"){
            int u,v;
            cin >> u >> v;
            // addRight(root, u, v);
            addRightOptimize(u,v);
        }
        else if(s == "*"){
            res ans = check1(root);
            cout << ans.z << " "<<ans.h;
            break;
        }
    }
   

    return 0;
}