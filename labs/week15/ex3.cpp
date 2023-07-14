//Family Tree
/*Given a family tree represented by child-parent (c,p) 
relations in which c is a child of p. 
Perform queries about the family tree:
descendants <name>: return number of descendants of the given <name>
generation <name>: return the number of generations of the descendants of the given <name>*/
#include <bits/stdc++.h> 
using namespace std;
typedef struct node{
    string data;
    node *leftmostChild;
    node *rightSibling;
}node;
node *nodeArr[(int)10e4];
int cnt = 0;
node* makeNode(string v){
    node *p = new node();
    if(p == NULL){
        cout << "Memory error\n";
        return NULL;
    }
    p->data= v;
    p->leftmostChild = p->rightSibling= NULL;
    return p;
}
//hàm find node sẽ trả về địa chỉ của 
//name bằng newman trong nodes[10e4]
//vì ta chưa thể xây dựng được tree luôn ngay tức khắc
//và có thể có nhiều gia đình
node *findNode(string v){
    for(int i = 0;i < cnt;i++){
        if(nodeArr[i]->data == v) return nodeArr[i];
    }
    return NULL;
}

void addChild(node *chilNode, node *parNode){
    node *left = parNode->leftmostChild;
    if(left == NULL) parNode->leftmostChild = chilNode;
    else{
        node *right = left;
        while(right->rightSibling != NULL) right = right->rightSibling;
        right->rightSibling = chilNode;
    }
}
int countChild(node *root){
    if(root == NULL) return 0;
    int h = 0;
    node *p = root->leftmostChild;
    while(p !=NULL){
        h = max(h,countChild(p)); 
        // h là max của h và chiều cao của cây con trái
        p = p->rightSibling;
    }
    return h;
}

int main(){
    string c,p;
    //1.read
    while(1){
        cin >> c;
        if(c == "***") break;
        cin >> p;
        node *chilNode = findNode(c);
        if(chilNode == NULL) {
            nodeArr[cnt] = makeNode(c);
            cnt++;
            chilNode = nodeArr[cnt];
        }
        node *parNode = findNode(p);
        if(parNode == NULL) {
            nodeArr[cnt] = makeNode(p);
            cnt++;
            parNode = nodeArr[cnt];
        }
        addChild(chilNode, parNode); //chèn vào cuối danh sách của parentNode

    }
    //2.Read Command
    string cmd;
    while(1){
        cin >> cmd;
        if(cmd == "***") break;
        if(cmd == "descendants"){
            cin >> c;
            node *chilNode = findNode(c);
            if(chilNode == NULL) cout << "0\n";
            else cout << countChild(chilNode) << "\n";
        }
        else if(cmd == "generation"){
            cin >> c;
            node *chilNode = findNode(c);
            if(chilNode == NULL) cout << "0\n";
            else cout << countChild(chilNode) + 1 << "\n";
        }
    }
    return 0;
}