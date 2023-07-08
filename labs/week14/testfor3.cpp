#include <bits/stdc++.h>
using namespace std;

typedef struct node{
    char name[50];
    char email[50];
    node *left;
    node *right;
} node;

node* makeNode(const char* name, const char* email) {
    node* newNode = new node;
    strcpy(newNode->name, name);
    strcpy(newNode->email, email);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

node* findNode(node* r, const char* name) {
    if (r == NULL) return NULL;
    if (strcmp(r->name, name) == 0) return r;
    node* result = findNode(r->left, name);
    if (result != NULL) return result;
    return findNode(r->right, name);
}

void preOrder(node* r) {
    if (r == NULL) return;
    cout << r->email << " ";
    preOrder(r->left);
    preOrder(r->right);
}

void inOrder(node* r) {
    if (r == NULL) return;
    inOrder(r->left);
    cout << r->email << " ";
    inOrder(r->right);
}

void postOrder(node* r) {
    if (r == NULL) return;
    postOrder(r->left);
    postOrder(r->right);
    cout << r->email << " ";
}

void insertNode(node* r, const char* name, const char* email) {
    if (r == NULL) return;
    if (r->left == NULL) {
        r->left = makeNode(name, email);
        return;
    }
    else if (r->right == NULL) {
        r->right = makeNode(name, email);
        return;
    }
    else {
        insertNode(r->left, name, email);
        insertNode(r->right, name, email);
    }
}

void removeNode(node* r, const char* name) {
    if (r == NULL) return;
    if (strcmp(r->name, name) == 0) {
        delete r;
    }
    else {
        removeNode(r->left, name);
        removeNode(r->right, name);
    }
}

void Store1(node* r, ofstream& file) {
    if (r == NULL) return;
    file << "Name: " << r->name << " - Email: " << r->email << endl;
    Store1(r->left, file);
    Store1(r->right, file);
}

void Store(const string& filename, node* root) {
    ofstream file(filename);
    if (!file) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    Store1(root, file);

    file.close();
    cout << "Data stored in file: " << filename << endl;
}

int main() {
    string s;
    char name[50], email[50];
    node* root = NULL;
    //freopen("test2.txt", "r", stdin);
    while (true) {
        cin >> s;
        if (s == "Load") {
            int n;
            cin >> n;
            for (int i = 0; i < n; i++) {
                cin >> name >> email;
                insertNode(root, name, email);
                cout << root->name << " " << root->email << endl;
            }
        }
        else if (s == "Find") {
            cin >> name;
            node* temp = findNode(root, name);
            cout << temp->email << endl;
        }
        else if (s == "Insert") {
            cin >> name >> email;
            insertNode(root, name, email);
        }
        else if (s == "Remove") {
            cin >> name;
            removeNode(root, name);
        }
        else if (s == "print") {
            preOrder(root);
        }
        else if (s == "Store") {
            string filename;
            cin >> filename;
            Store(filename, root);
        }
        else if (s == "Quit") {
            break;
        }
    }
    return 0;
}
