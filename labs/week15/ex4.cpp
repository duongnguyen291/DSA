//Chapter 6. Hash Over Integers
#include <bits/stdc++.h> 
using namespace std;
typedef struct node{
    long long data;
    node *left, *right;
}node; 

vector <node> *data;
node *makeNode(int v){
    node *p = new node();
    if(p == NULL){
        cout << "Memory allocation failed\n";
        exit(1);
    }
    p->data = v;
    p->left = p->right = NULL;
    return p;
}
node* add(node *root,int x){
    if(data[x]!= NULL) return 0;
    if(x > root->data){
        if(root->right == NULL){
            node *temp = makeNode(x);
            root->right = temp;
            data[x] = temp;
        }
        else{
            root = add(root->right, x);
        }
    }
    else if(x < root->data){
        if(root->left == NULL){
            node *temp = makeNode(x);
            root->left = temp;
            data[x] = temp;            
        }
        else{
        root = add(root->left, x);
        }
    }
    return root;
}
node *insertNode(node *r, int x){
    //time complexity: O(h) h: the height of tree
    if(r == NULL) {
        r = makeNode(x);
        data[x] = r;
    }
    if(x == r->data) return r;
    else if(x < r->data){
        r->left = insertNode(r->left, x);
        node *temp = insertNode(r->left, x);
        r->left = temp;
        data[x] = temp;
        return r;
    }
    else{
        node *temp = insertNode(r->right, x);
        r->right = temp;
        data[x] = temp;
        return r;
    }
}

int main(){
    string s;
    long long k;
    node *root = NULL;
    freopen("test4.txt","r",stdin);
    for(int i = 0; i < 100010;i++) data[i] = NULL;
    //1.Read data
    while(true){
        cin >> s;
        if(s == "*") {
            break;
        }
        else{
            k = stoll(s);
            cout << "Enter : " << k << "\n";
            root = insertNode(root,k);
        }
    }
    //2.Command
    while(1){
        cin >> s;
        if(s == "***") break;
        else if(s == "find"){
            cin >> k;
            if(data[k] == NULL) cout << "0\n";
            else cout << "1\n";
        }
        else if(s == "insert"){
            cin >> k;
            if(data[k] == NULL){
                root = add(root,k);
                if(data[k] !=NULL) cout << "1\n";
            }
            else cout << "0\n";
        }
    }


    return 0;
}