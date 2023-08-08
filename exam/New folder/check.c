#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include<bits/stdc++.h>

typedef struct TNode
{
    int key;
    struct TNode *left, *right;
} TN;

// tao nut moi
TN* makeNewNode(int key)
{
    TN* newNode = (TN*)malloc(sizeof(TN));
    newNode->left = newNode->right = NULL;
    newNode->key = key;
    return newNode;
}
// then nut moi vao cay
// root la nut cha va nNode la nut moi them
// tham so rtype = L --> them vao con trai va R thi them vao con phai
void addNodeToTree(TN* root, TN* nNode, char rtype)
{
    if (rtype == 'L')
        root->left = nNode;
    else
        root->right = nNode;
}

// duyet cay theo thu tu giua
void inOrderTravel(const TN* root)
{
    if (NULL == root) return;
    inOrderTravel(root->left);
    printf("%d ", root->key);
    inOrderTravel(root->right);
}

void printInOrderTravel(const TN* root)
{
    inOrderTravel(root);
    printf("\n");
}

TN* buildTree()
{
    TN* root = NULL, * nNode, * parent;
    int level, i, key;
    char path[20], nextLine[100];
    while (1) {
        fgets(nextLine, sizeof(nextLine), stdin);
        nextLine[strcspn(nextLine, "\r\n")] = 0;
        if (strstr(nextLine, "-1") != NULL) break;
        sscanf(nextLine, "%d %s %d", &level, path, &key);
        if (level == 0) {
            root = makeNewNode(key);
            continue;
        }

        // add decendent nodes
        nNode = makeNewNode(key);
        parent = root;
        for (i = 0; i < strlen(path) - 1; i++)
            if (path[i] == 'R')parent = parent->right;
            else parent = parent->left;
        addNodeToTree(parent, nNode, path[i]);
    }
    return root;
}
/*
==========================================
Pháº§n viáº¿t code cá»§a sinh viÃªn
===========================================
*/
int countSpecialNodes(const TN* root, int k) {
	if(root == NULL) return 0;
	if(root->key >= k) {
		return 1 + countSpecialNodes(root->left, k) + countSpecialNodes(root->right, k);
	}
	else {
		return countSpecialNodes(root->left, k) + countSpecialNodes(root->right, k);
	}
}

TN* get_min(TN* u, TN* v) {
	if(u == NULL) return v;
	if(v == NULL) return u;
	if(u->key < v->key) return u;
	return v;
}

TN* smallestLeaf(TN* root) {
	if(root == NULL) return NULL;
	if(root->left == NULL && root->right == NULL) {
		return root;
	}
	return get_min(smallestLeaf(root->left), smallestLeaf(root->right));
}

int a[1000005], n;

void dfs1(TN* root) {
	if(root == NULL) return;
	a[n++] = root->key;
	dfs1(root->left);
	dfs1(root->right);
}

void dfs2(TN* root, int* cnt) {
	if(root == NULL) return;
	dfs2(root->left, cnt);
	root->key = a[(*cnt)];
	++(*cnt);
	dfs2(root->right, cnt);
}

int hasDuplicateItem(TN* root) {
	int i = 0, j = 0;
	n = 0;
	dfs1(root);
	for(i = 0; i < n; ++i) {
		for(j = i + 1; j < n; ++j) {
			if(a[i] == a[j]) {
				return 1;
			}
		}
	}
	return 0;
}

void convertToBinarySearchTree(TN* root) {
	int m = 0, i, j, k, t;
	n = 0;
	dfs1(root);
	
	for(i = 0; i < n; ++i) {
		k = i;
		for(j = i + 1; j < n; ++j) {
			if(a[j] < a[k]) {
				k = j;
			}
		}
		t = a[i];
		a[i] = a[k];
		a[k] = t;
	}
	dfs2(root, &m);
}

/*
=====================================
Háº¿t pháº§n viáº¿t code
===============================
*/

void checkDuplicateItemonTree(TN* root)
{
    if (hasDuplicateItem(root)) printf("Tree has some duplicate items!\n");
    else printf("There is no dulplicate item on the tree!\n");
}
void countListSpecialNodes(const TN* root)
{
    char nextLine[100];
    int k;
    while (1) {
        fgets(nextLine, sizeof(nextLine), stdin);
        nextLine[strcspn(nextLine, "\r\n")] = 0;
        if (strstr(nextLine, "-1") != NULL) break;
        sscanf(nextLine, "%d", &k);
        printf("Total special nodes >=%d: %d\n", k, countSpecialNodes(root,k));
    }
}

void printSmallestLeaf(TN* root)
{
    TN* smLeaf = smallestLeaf(root);
    if (smLeaf != NULL)
        printf("Smallest Leaf : %d\n", smLeaf->key);
    else
        printf("There is no leaf on the tree!\n");
}
int main()
{
    freopen("test1.txt","r",stdin);
    TN* root = NULL;
    char nextCommand[100];
    while (1)
    {
        fgets(nextCommand, sizeof(nextCommand), stdin);
        nextCommand[strcspn(nextCommand, "\r\n")] = 0;
        if (nextCommand[0] != '?') break;
        if (strcmp(&nextCommand[2], "buildTree") == 0)
            root = buildTree();
        else if (strcmp(&nextCommand[2], "printInOrderTravel") == 0)
            printInOrderTravel(root);
        else if (strcmp(&nextCommand[2], "countSpecialNodes") == 0)
            countListSpecialNodes(root);
        else if (strcmp(&nextCommand[2], "printSmallestLeaf") == 0)
            printSmallestLeaf(root);
        else if (strcmp(&nextCommand[2], "hasDuplicateItem") == 0)
            checkDuplicateItemonTree(root);            
        else if (strcmp(&nextCommand[2], "convertToBinarySearchTree") == 0)
            convertToBinarySearchTree(root);
    }

    return 0;
}