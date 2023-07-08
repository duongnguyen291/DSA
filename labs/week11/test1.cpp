/*Chapter 4: General Tree manipulation query and Traversal*/
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct Node {
    int id;
    struct Node* leftmost_child;
    struct Node* right_sibling;
} Node;

Node* head;
char cmd[20];
   
Node* makeTreeNode(int data) {
    Node* new_node = NULL;
    new_node = (Node*)(malloc(sizeof(Node)));
    if (new_node == NULL) {
        printf("Out of memory\n");
        exit(1);
    } 
    new_node->id = data;
    new_node->leftmost_child = NULL;
    new_node->right_sibling = NULL;
    
    return new_node;
}

void preOrder(Node* root) { //Root Left Child
    //Base case
    if (root == NULL) return;
    printf("%d ", root->id);
    Node* p = root->leftmost_child;
    while (p != NULL) {
        preOrder(p);
        p = p->right_sibling;
    }
    /*for(Node* p = root->leftmost_child; p != NULL; p = p->right_sibling) preOrder(p);*/
}

void inOrder(Node* root) { //Left Root Right
    //Base case
    if (root == NULL) return;
    // 1. Leftmost subtree of root
    Node* p = root->leftmost_child;
    inOrder(p);
    //2. Root
    printf("%d ", root->id);
    //3. Right subtree of roots (from left to right)
    while (p != NULL) {
        p = p->right_sibling;
        inOrder(p);
    }
}

void postOrder(Node* root) { //Left Right Root
    //Base case
    if (root == NULL) return;
    //1.Leftmost subtree of root
    Node* p = root->leftmost_child;
    while(p != NULL) {
        postOrder(p);
        p = p->right_sibling;
    }
    //2. Root
    printf("%d ", root->id);
}

Node* find_Node(Node* root, int idFind) {
    //Find node with id = idFind
    //if exist return to the founded node
    //otherwise return NULL
    if (root == NULL) return NULL;
    if (root->id == idFind) return root;
    Node* result = find_Node(root->leftmost_child, idFind);
    if (result != NULL) return result;
    return find_Node(root->right_sibling, idFind);
}

void insertNode(Node* root, int u, int v) {
    if (find_Node(root, u) != NULL) return;
    Node* p = find_Node(root, v);
    if (p == NULL) return;
    
    //Node* new_node = makeTreeNode(u);
    Node* left = p->leftmost_child;
    if (left == NULL) { //If the node hasn't have any child
        p->leftmost_child = makeTreeNode(u);
    } else { //If it has at least 1 child
        Node* right = left;
        while (right->right_sibling != NULL) right = right->right_sibling;
        right->right_sibling = makeTreeNode(u);
    } 
}

int main() {
//	freopen("input.txt", "r", stdin);
    while (1) {
        scanf("%s", cmd);
        int u, v;
        if (strcmp(cmd, "*") == 0) break;
        else if (strcmp(cmd, "MakeRoot") == 0) {
            int id1;
            scanf("%d", &id1);
            head = makeTreeNode(id1);
        } else if (strcmp(cmd, "Insert") == 0) {
            scanf("%d %d", &u, &v);
            insertNode(head, u, v);
        } else if (strcmp(cmd, "PreOrder") == 0) {
            preOrder(head);
            printf("\n");
        } else if (strcmp(cmd, "InOrder") == 0) {
            inOrder(head);
        	printf("\n");
		} else if (strcmp(cmd, "PostOrder") == 0) {
            postOrder(head);
            printf("\n");
        }
    }

    return 0;
}