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
    while(p != NULL){
        // h = max(h,countChild(p)); 
        h+=1+countChild(p);
        // h là max của h và chiều cao của cây con trái
        p = p->rightSibling;
    }
    return h;
}

int genderation(node *root) {
    if (root == NULL) return 0;
    int maxGeneration = 0;
    node *p = root->leftmostChild;
    while (p != NULL) {
        maxGeneration = max(maxGeneration, 1 + genderation(p));
        p = p->rightSibling;
    }
    return maxGeneration;
}
int main(){

    freopen("test3.txt","r",stdin);
    //1.read
    string c,p;
    while(true){
        cin >> c;
        // cout << "c = " << c << "\n";
        if(c == "***") break;
        cin >> p;
        // cout << "p = " << p << "\n";
        node *chilNode = findNode(c);
        if(chilNode == NULL) {
            nodeArr[cnt] = makeNode(c);
            chilNode = nodeArr[cnt];
            cnt++;
        }
        node *parNode = findNode(p);
        if(parNode == NULL) {
            nodeArr[cnt] = makeNode(p);
            parNode = nodeArr[cnt];
            cnt++;
        }
        addChild(chilNode, parNode); //chèn vào cuối danh sách của parentNode       
    }
    // cout << "Done reading\n";
    //2.Read Command
    string cmd;
    while(1){
        cin >> cmd;
        if(cmd == "***") break;
        if(cmd == "descendants"){
            cin >> c;
            // cout << "c = " << c << "\n";
            node *chilNode = findNode(c);
            if(chilNode == NULL) cout << "0\n";
            else cout << countChild(chilNode) << "\n";
        }
        else if(cmd == "generation"){
            cin >> c;
            // cout << "c = " << c << "\n";
            node *chilNode = findNode(c);
            if(chilNode == NULL) cout << "0\n";
            else cout << genderation(chilNode) << "\n";
        }
    }
    return 0;
}