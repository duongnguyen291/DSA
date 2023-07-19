#include <iostream>
#include <string>

struct node {
    int data;
    node* left;
    node* right;
};

node* makeNode(int v) {
    node* p = new node();
    if (p == NULL) {
        std::cout << "Memory allocation failed\n";
        exit(1);
    }
    p->data = v;
    p->left = p->right = NULL;
    return p;
}

node* findNode(node* r, int v) {
    if (r == NULL) return NULL;
    if (r->data == v) return r;
    node* p = findNode(r->left, v);
    if (p != NULL) return p;
    return findNode(r->right, v);
}

node* insertNode(node* r, int v) {
    node* p = findNode(r, v);
    if (p != NULL) return NULL; // Value already exists, return NULL
    if (r == NULL) {
        return makeNode(v); // Insert as root if tree is empty
    } else if (r->left == NULL) {
        r->left = insertNode(r->left, v); // Insert as left child if left child is null
    } else if (r->right == NULL) {
        r->right = insertNode(r->right, v); // Insert as right child if right child is null
    } else {
        r->left = insertNode(r->left, v); // Insert recursively into left subtree
        r->right = insertNode(r->right, v); // Insert recursively into right subtree
    }
    return r;
}

int findKey(node* r, int key) {
    node* p = findNode(r, key);
    if (p != NULL) {
        return 1; // Key found, return 1
    } else {
        return 0; // Key not found, return 0
    }
}

int insertKey(node* r, int key) {
    node* p = insertNode(r, key);
    if (p != NULL) {
        return 1; // Insertion successful, return 1
    } else {
        return 0; // Insertion failed, return 0
    }
}

int main() {
    std::string s;
    node* r = NULL;
    int k;
    freopen("test4.txt","r",stdin);
    // Read keys into the binary tree
    while (true) {
        std::cin >> s;
        if (s == "*") {
            break; // Terminate first block on encountering "*"
        } else {
            int key = std::stoi(s);
            r = insertNode(r, key);
        }
    }

    // Process actions
    while (true) {
        std::cin >> s;
        if (s == "***") {
            break; // Terminate second block on encountering "***"
        } else {
            std::cin >> k;
            if (s == "find") {
                std::cout << findKey(r, k) << std::endl;
            } else if (s == "insert") {
                std::cout << insertKey(r, k) << std::endl;
            }
        }
    }

    return 0;
}
