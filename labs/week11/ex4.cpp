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
void preOrder(int *head){
    if(head == NULL) return;
    cout << head->data << " ";
    node p = head->mostLeftChild;
    while(p!=NULL){
        postOrder(p);
        p = p->rightSibling;
    }
}
int height(int *head){
    if(head == NULL) return 0;
    int h = 0;
    node *p = head->mostLeftChild; 
    while(p!=NULL){
        h = max(h,height(p));
        p = p -> rightSibling;
    }
    return h+1;
}

int calculateHeight(node* p) {
    if (p == NULL) {
        return 0;
    } else {
        int leftHeight = calculateHeight(p->mostLeftChild);
        int rightHeight = calculateHeight(p->rightSibling);

        return 1 + max(leftHeight, rightHeight);
    }
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
int main(){
    string s;
    //freopen("test4.txt","r",stdin);
+
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


}