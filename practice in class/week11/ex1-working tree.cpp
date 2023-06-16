#include <bits/stdc++.h>
using namespace std;
typedef struct node{
    char word[20];
    int data;
    node *left;
    node *right;
}node;
void preorder(node *a){
    if(a == NULL) return;
    cout << a->data;
    preorder(a->left);
    preorder(a->right);
}
void inorder(node *a){
    if(a == NULL) return;
    inorder(a->left);
    cout << a->data;
    inorder(a->right);
}
void postorder(node *a){
    if(a == NULL) return;
    postorder(a->left);
    postorder(a->right);
    cout << a->data;
}
void freeNode(node *a){
    if(a == NULL) return;
    freeNode(a->left);
    freeNode(a->right);
    delete a;
}
node *makeTreeNode(char *word, int a){
    node *newNode = NULL;
    newNode = new node;
    if(newNode == NULL){
        cout << "Out of memory" << endl;
        exit(1);
    }
    else{
        strcpy(newNode->word,word);
        newNode->data = a;
        newNode->left = NULL;
        newNode->right = NULL;
    }
}
int countNode(node *root){
    if(root == NULL) return 0;
    return 1 + countNode(root->left)+ countNode(root->right);
}
int depth(node *a){
    if(a == NULL) return 0;
    return max(depth(a->left),depth(a->right)) + 1;
}

node *insertNode(node *root, char *word, int data,bool LEFT){
    node *newNode, *p;
    newNode = makeTreeNode(word,data);
    if(root == NULL) return newNode;
    if(LEFT) //insert node on the leftmost of the tree
    {
        p = root;
        while(p->left !=NULL)p = p->left;
        p->left = newNode;
        cout << word ;//
    }
    else{
        p = root;
        while(p->right != NULL) p = p->right;
        p->right = newNode;
        cout << word; // 
    }
}
int main(){


    return 0;
}