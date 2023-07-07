//Problem: Chapter 6. Student record management
#include <bits/stdc++.h>
using namespace std;
typedef struct node{
    string name;
    string email;
    node *left;
    node *right;
}node;
node *makeNode(string name, string email){
    node *newNode = NULL;
    // newNode = new node;
    newNode = (node *) malloc(sizeof(node )); //nếu dùng hàm malloc
    if(newNode == NULL) {cout << "Out of memory\n"; exit(1);}
    newNode->name = name;
    newNode->email = email;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
node *findNode(node *r,string name, string email){
    //find node with id = v on the 
    if(r == NULL) return NULL;
    if(r->name == name && r->email == ) return r;

    node *result = findNode(r->left,name, email);
    if(result != NULL) return result;
    return findNode(r->right,name, email);   
}
void addLeft(node *r, string name, string email){
//chen id  = u vào vị trí con trái của v(trừ u đã tồn tại, v ko tồn tại hoặc v đã có con trái)    
    if(findNode(r,name, email) != NULL) return; //check sự tồn tại của u
    node *temp = findNode(r,name, email);
    if(temp == NULL) return;
    if(temp->left !=NULL) return;
    temp->left = makeNode(name,email);
}
void add(node *r, string name, string email){
//chen id  = u vào vị trí con trái của v(trừ u đã tồn tại, v ko tồn tại hoặc v đã có con trái)    
    if(findNode(r,name, email) != NULL) return; //check sự tồn tại của u
    node *temp = findNode(r,name, email);
    if(temp == NULL) return;
    if(temp->left !=NULL) return temp->right = makeNode(name,email);;
    temp->left = makeNode(name,email);
}


int main(){
    int n;
    string name, email;
    node *head = NULL;
    while(1){
        string s;
        cin >> s;   
        if(s == "Load"){
            cin >> n;
            getline(cin,name);
            getline(cin, email);
            head = makeNode(name, email);
            for(int i = 0;i < n - 1;i++){
                getline(cin,name);
                getline(cin, email);
                add(head, name, email);
            }
        }
        else if(s =="Find" ){
            string name;
            cin >> name;

        }
        else if(s =="Insert" ){
            string name, email;
            getline(cin,name);
            getline(cin, email);

        }
        else if(s =="Remove" ){
            string name;
            cin >> name;

        }        
        else if(s =="Store" ){
            string filename;
            cin >> filename;

        }        
        else if(s =="Quit" ){
            string filename;
            cin >> filename;

        }        
    }

    return 0;
}