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
int depth(int *head){
    if(head == NULL) return 0;
    int h = 0;
    node *p = head->mostLeftChild; 
    while(p!=NULL){
        h = max(h,height(p));
        p = p -> rightSibling;
    }
    return h+1;
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