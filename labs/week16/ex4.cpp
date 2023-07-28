//Problem: Chapter 6. Hash Over Integers

#include <bits/stdc++.h> 
using namespace std;
#define MAX 100000000
typedef struct node{
    long long data;
    node *left;
    node *right;
}node;
node *database[MAX+10];
node *makeNode(long long x){
    node *p= (node*) malloc(sizeof(node ));
    if(p == NULL){
        printf("\nError memory located!");
        exit(1);
    }
    p->data = x;
    p->left = p->right = NULL;
    return p;
}


int findNode(long long k){
    if(database[k%MAX] == NULL) return 1;
    else{
        node *p = database[k%MAX];
        while(p != NULL){
            if(p->data == k){
                return 0; //đã có r
                break;
            }
            p = p->next;
        }
        if(p == NULL) return 1; // chưa có
    }
}
int main(){
    freopen("test4.txt","r",stdin);
    string s;
    long long k;
    for(int i = 0;i < MAX+ 10;i++) database[i] = NULL;
    while(1){
        cin >> s;
        if(s == "*") break;
        else{
            k = stoll(s);
            if(database[k%MAX] == NULL) {
                node *p = makeNode(k);
                database[k%MAX] = p;
            }
            else{
                node *p = makeNode(k);
                node *temp = database[k%MAX];
                database[k%MAX] = p;
                p->next = temp;
            }
        }
    }
    while(1){
        cin >> s;
        if(s == "***") break;
        else if(s == "find"){
            cin >> k;
            int result = findNode(k) > 0 ? 0 :1; // trả về 1 khi chưa có và 0 khi đã có

            cout << result << endl;
        }
        else if(s == "insert"){
            cin >> k;
            if(findNode(k) == 0) cout << 0 << endl;
            else{

                node *p = makeNode(k);
                node *temp = database[k%MAX];
                database[k%MAX] = p;
                p->next = temp;
             
                cout << 1 << endl;
            }          
        }
    }
    
    return 0;    
}
/*
0
0
1
1
1
*/