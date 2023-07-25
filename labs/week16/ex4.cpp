/*Problem: Chapter 6. Hash Over Integers
Description
    A database contains a sequence of key k1, k2, ..., kn which are integers (1<=n<=100000). 
    Perform a sequence of actions of two kinds:
    · find k: find and return 1 if k exists in the database, and return 0, otherwise
    · insert k: insert a key k into the database and return 1 if the insertion is successful 
    (k does not exist in the database) and return 0 if the insertion is failed (k exists in the database)
    Note that the value of any key is greater than or equal to 0 and less than or equal to 10
    17
    .
Input
    Two blocks of information. 
    The first block contains a key of (k1,k2,...,kn) in each line. 
    The first block is terminated with a line containing *. 
    The second block is a sequence of actions of two finds described above: 
    each line contains 2 string: cmd and k in which cmd = "find" or "insert" and k is the key 
    (parameter of the action). The second block is terminated with a line containing ***. 
    Note that the number of actions can be up to 100000.
Output
    Each line contains the result (0 or 1) of the corresponding action.
*/
#include <bits/stdc++.h> 
using namespace std;
#define MAX 1000000
typedef struct node{
    long long data;
    node *next;
}node;
node *database[MAX+10];
node *makeNode(long long x){
    node *p= (node*) malloc(sizeof(node ));
    if(p == NULL){
        printf("\nError memory located!");
        exit(1);
    }
    p->data = x;
    p->next = NULL;
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
    for(int i = 0;i < MAX + 10;i++) database[i] = NULL;
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