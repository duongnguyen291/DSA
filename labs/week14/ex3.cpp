#include <bits/stdc++.h>
using namespace std;
typedef struct node{
    string name, email;
    node *left;
    node *right;
}node;
node *makeNode(string name, string email){
    node *newNode = NULL;
    // newNode = new node;
    newNode = new node(); //nếu dùng hàm malloc
    if(newNode == NULL) {cout << "Out of memory\n"; exit(1);}
    newNode->name = name;
    newNode->email = email;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
node *findNode(node *r,string name){
    //find node with id = v on the 
    if(r == NULL) return NULL;
    if(r->name == name) return r;
    node *result = findNode(r->left,name);
    if(result != NULL) return result;
    return findNode(r->right,name);   
}
void preOrder(node *r){
    if(r == NULL) return;
    cout << r->email << " ";
    preOrder(r->left);
    preOrder(r->right);    
    cout << endl;
}
void inOrder(node *r){
    if(r == NULL) return;
    inOrder(r->left);
    cout << r->email << " ";
    inOrder(r->right);    
}
void postOrder(node *r){
    if(r == NULL) return;
    postOrder(r->left);
    postOrder(r->right);    
    cout << r->email << " ";
}
node* insertNode(node* r, string name, string email) {
    if (r == NULL) {
        return makeNode(name, email);
    } else if (r->left == NULL) {
        r->left = insertNode(r->left, name, email);
    } else if (r->right == NULL) {
        r->right = insertNode(r->right, name, email);
    } else {
        r->left = insertNode(r->left, name, email);
        r->right = insertNode(r->right, name, email);
    }
    return r;
}

node* removeNode(node* r, string name) {
    if (r == NULL) {
        return NULL;
    } else if (r->name == name) {
        delete r;
        return NULL;
    } else {
        r->left = removeNode(r->left, name);
        r->right = removeNode(r->right, name);
    }
    return r;
}

void Store1(node* r, ofstream& file) {
    if (r == NULL) return;
    file << "Name: " << r->name <<" - Email: " << r->email <<  endl;
    Store1(r->left, file);
    Store1(r->right, file);
}

void Store(const string& filename, node* root) {
    ofstream file(filename);
    if (!file) {  // Check if the file is opened successfully
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    Store1(root, file);

    file.close();
    cout << "Data stored in file: " << filename << endl;
}
int main(){
    string s;
    string name, email;
    freopen("test2.txt","r",stdin);
    node *root = NULL;
    while(true){
        cin >> s;
        if(s == "Load"){
            int n;
            cin >> n;
            for(int i = 0;i<n;i++){
                cin >> name >> email;
                // cout << name << " " << email << endl;
                root = insertNode(root,name,email);
            }
        }
        else if(s == "Find"){
            cin >> name;
            node *temp;
            temp = findNode(root,name);
            if(temp == NULL) continue;
            else{
                cout << temp->email << endl;
            }
        }
        else if(s == "Insert"){
           cin >> name >> email;
           root = insertNode(root,name,email);
        }
        else if(s == "Remove"){
           cin >> name;
           root = removeNode(root,name);
        }
        else if(s == "print"){
            inOrder(root);
        }
        else if(s == "Store"){
            string filename;
            cin >> filename;
           Store(filename,root);
        }
        else if(s == "Quit"){
            cout << "Bye\n";
            break;
        }
    }
    return 0;
}
/*•Load: Nạp dữ liệu từ bàn phím gồm n sinh viên
•Find<student_name>: Trả về hồ sơ của sinh viên có tên được nhập vào
•Insert <student_name> <email>: Chèn một hồ sơ sinh viên mới vào cuối danh sách
•Remove <student_name>: loại bỏ hồ sơ sinh viên
•Store <filename>: Lưu trữ danh sách hồ sơ lênfile văn bản
•Quit: thoát khỏi chương trình
Yêu cầu: Sử dụng cây nhị phân tìm kiếm*/