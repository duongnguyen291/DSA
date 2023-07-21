#include<bits/stdc++.h>
using namespace std;

struct treeNode
{
    int id;
    struct treeNode* left_child;
    struct treeNode* right_child;
};

treeNode* Root = NULL;
treeNode* rootArr[100001];
long long sum = 0;
int check = 1;

treeNode* makeNode(int x)
{
    treeNode* tmp = (treeNode*)(malloc(sizeof(treeNode)));
    tmp->id = x;
    tmp->left_child = NULL;
    tmp->right_child = NULL;
    return tmp;
}

void makeRoot(int x)
{
    treeNode* tmp = makeNode(x);
    Root = tmp;
    rootArr[x] = tmp;
}

void addLeft(int child, int parent)
{
    treeNode* tmp = rootArr[parent];
    treeNode* tmp2 = makeNode(child);
    tmp->left_child = tmp2;
    rootArr[child] = tmp2;
}

void addRight( int child, int parent)
{
    treeNode* tmp = rootArr[parent];
    treeNode* tmp2 = makeNode(child);
    tmp->right_child = tmp2;
    rootArr[child] = tmp2;
}

void checkTree(treeNode* root)
{
      if(root == NULL) return;
      treeNode* left = root->left_child;
      if(left != NULL)
      {
         if(left->id > root->id )
         {
            check = 0;
            return;
         }
        checkTree(left);
      }
      treeNode* right = root->right_child;
      if(right != NULL)
      {
         if(right->id < root->id )
         {
            check = 0;
            return;
         }
      }
      checkTree(right);

}




int main()
{
    freopen("test1.txt","r",stdin);
    char c[20];
    while(1)
    {
        cin >> c;
        if(strcmp(c,"*") == 0)
        {
            break;
        }
        else if(strcmp(c,"MakeRoot") == 0)
        {
            int x ; cin >> x;
            makeRoot(x);
            sum += x;
        }
        else if(strcmp(c,"AddRight") == 0)
        {
            int x,y; cin >> x >> y;
            addRight(x,y);
            sum += x;
        }
        else if(strcmp(c,"AddLeft") == 0)
        {
            int x,y; cin >> x >> y;
            addLeft(x,y);
            sum += x;
        }
    }
    checkTree(Root);
    cout << check << ' ' << sum << '\n';
    return 0;
}