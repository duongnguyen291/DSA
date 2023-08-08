//Chapter 6. Hash Over Integers
#include <bits/stdc++.h>
using namespace std;
#define MAX 10010
typedef struct node{
    long long data;
    node *next;
}node;
node *a[MAX];
node *makeNode(long long k){
    node *p = new node();
    if(p==NULL) {cout << "Memory!";exit(1);}
    p->data = k;
    p->next = NULL;
    return p;
}
int find(long long k ){
    if(a[k%MAX] == NULL) return 0; //ko tim thay
    node *temp = a[k%MAX];
    while(temp!=NULL){
        if(temp->data == k) return 1;
        temp = temp->next;
    }
    return 0;
}
void insert(long long k){
    if(a[k%MAX] == NULL){
        node *temp = makeNode(k);
        a[k%MAX] = temp; 
        return;
    }
    else{
        node *p = makeNode(k);
        p->next = a[k%MAX];
        a[k%MAX] = p;
        return;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    freopen("test1.txt","r",stdin);
    long long k;
    while(1){
        cin >> s;
        // cout <<"check: " <<s << endl;
        if(s == "*") break;
        else{
            long long n = stoll(s); 
            // cout << n << endl;
            insert(n);
        }
    }
    while(1){
        cin >> s;
        if(s == "***") break;
        else if(s == "find"){
            cin >> k;
            int res = find(k);
            cout << res << "\n";
        }
        else if (s == "insert"){
            cin >> k;
            if(find(k) == 1) cout << 0 << endl;
            else {
                insert(k);
                cout << 1 << endl;
            }
        }
    }

}