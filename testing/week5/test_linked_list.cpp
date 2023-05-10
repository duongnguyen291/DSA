#include <bits/stdc++.h>
using namespace std;
struct NoteType{
    char id[10];
    char name[30];
    double math;
    double physical;
};
struct node{
    NoteType data;
    node *next;
};


int main(){
    node *head = new node();
    strcpy(head->data.id,"20225966");
    cout << head->data.id << endl;
    delete head;
    return 0;
}