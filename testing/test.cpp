#include <bits/stdc++.h>
using namespace std;
typedef struct node{
    int id;
  node *next;
}node;
void fun1(node *head){
    if(head == NULL) return;
    fun1(head->next);
    cout << head->id << " ";
}

int main(){ 
 
}
