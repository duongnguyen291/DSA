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
int findDepth(node* root, int x){
    // Base case
    if (root == NULL)
        return -1;
    // Initialize distance as -1
    int dist = -1;
    // Check if x is current node=
    if ((root->id == x)
        // Otherwise, check if x is
        // present in the left subtree
        || (dist = findDepth(root->left, x)) >= 0
        // Otherwise, check if x is
        // present in the right subtree
        || (dist = findDepth(root->right, x)) >= 0)
        // Return depth of the node
        return dist + 1;
    return dist;
}
int findHeightUtil(node* root, int x,int& height){
    // Base Case
    if (root == NULL) {
        return -1;
    }
    // Store the maximum height of
    // the left and right subtree
    int leftHeight = findHeightUtil(
        root->left, x, height);
    int rightHeight = findHeightUtil(
            root->right, x, height);
    // Update height of the current node
    int ans = max(leftHeight, rightHeight) + 1;
    // If current node is the required node
    if (root->id == x)
        height = ans;
    return ans;
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