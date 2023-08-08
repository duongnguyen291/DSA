#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct TNode
{
    int key;
    struct TNode* left, * right;
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
Phần viết code của sinh viên
===========================================
*/
// Hàm đếm và trả về số lượng có giá trị khóa lớn hơn hoặc bằng k trên cây
int countSpecialNodes(const TN* root, int k)
{
    if (NULL == root) return 0;
    if (root->key >=k) return 1 + countSpecialNodes(root->right,k) + countSpecialNodes(root->left,k);
    else return countSpecialNodes(root->right,k) + countSpecialNodes(root->left,k);
}


// hàm tìm và trả về nút lá có giá trị nhỏ nhất trên cây
TN* smallestLeaf(TN* root) {
    if (root == NULL) {
        return NULL; // Không có cây hoặc nút trống, trả về NULL
    }

    if (root->left == NULL && root->right == NULL) {
        return root; // Nếu gặp nút lá, trả về nút đó
    }

    // Gọi đệ quy để tìm nút lá nhỏ nhất trong cây con trái và cây con phải
    TN* leftSmallest = smallestLeaf(root->left);
    TN* rightSmallest = smallestLeaf(root->right);

    // So sánh giá trị của nút lá nhỏ nhất trong cây con trái và cây con phải
    // Trả về nút có giá trị nhỏ nhất trong cả hai cây con
    if (leftSmallest != NULL && rightSmallest != NULL) {
        return (leftSmallest->key < rightSmallest->key) ? leftSmallest : rightSmallest;
    }
    else if (leftSmallest != NULL) {
        return leftSmallest;
    }
    else {
        return rightSmallest;
    }
}



void inOrderToArr(const TN* root, int *keyList, int *size)
{
    if (NULL == root) return;
    inOrderToArr(root->left, keyList, size);
    keyList[*size] = root->key;
    (*size)++;
    inOrderToArr(root->right, keyList, size);
}

void ArrToinOrder(TN* root, int* keyList, int* size)
{
    if (NULL == root) return;
    ArrToinOrder(root->left, keyList, size);
    root->key = keyList[*size];
    (*size)++;
    ArrToinOrder(root->right, keyList, size);
}

// viết hàm kiểm tra xem có khóa bị trùng trên cây hay không
// nếu có trả về 1, ngược lại trả về 0
int hasDuplicateItem(TN* root)
{
    // nếu cây rỗng hoặc cây chỉ có 1 nút thì ko cần làm gì
    if (root == NULL || (root->left == NULL && root->right == NULL)) return 0;
    int keyList[200], size = 0;
    inOrderToArr(root, keyList, &size);

    int tmp;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < i; j++)
            if (keyList[j] == keyList[i]) return 1;
    return 0;            
}

// Viết hàm biến cây nhị phân ban đầu thành cây nhị phân tìm kiếm mà vẫn giữ nguyên hình dáng của cây
// hàm sẽ được dùng để chuyển cây khi chắc chăn trên cây không có khóa bị trùng
// con trỏ gốc sau khi biến đổi sang cây nhị phân tìm kiếm vẫn là root
void convertToBinarySearchTree(TN* root)
{
    // nếu cây rỗng hoặc cây chỉ có 1 nút thì ko cần làm gì
    if (root == NULL || (root->left == NULL && root->right == NULL)) return;
    int keyList[200], size = 0;
    inOrderToArr(root, keyList, &size);

    // sort the Arr
    int tmp;
    for(int i=size; i>1; i--)
        for(int j=1; j<i; j++)
            if (keyList[j - 1] > keyList[j])
            {
                tmp = keyList[j];
                keyList[j] = keyList[j - 1];
                keyList[j - 1] = tmp;
            }
    // map back to tree
    size = 0;
    ArrToinOrder(root, keyList, &size);
}

/*
=====================================
Hết phần viết code
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
    freopen("test2.txt","r",stdin);
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