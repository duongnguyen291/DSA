#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* next;
};

Node* makeNode(int x)
{
    Node* tmp = (Node*)(malloc(sizeof(Node)));
    tmp->data = x;
    tmp->next = NULL;
    return tmp;
}

void addFirst(Node** head, int x)
{
    Node* tmp = makeNode(x);
    if(*head == NULL){
        *head = tmp;
    }
    else{
        tmp->next = *head;
        *head = tmp;
    }
}
void addLast(Node **head,int x)
{
    Node *tmp = makeNode(x);
    Node *tmp2 = *head;
    if(*head == NULL){
        *head = tmp;
    }
    else{
        while(tmp2->next != NULL)
        {
            tmp2 = tmp2->next;
        }
        tmp2->next = tmp;
    }

}

void addAfter(Node *head,int x,int y)
{
    Node *tmp = makeNode(x);
    while(head->data != y){
        head=head->next;
    }
    tmp->next = head->next;
    head->next = tmp;
}

void addBefore(Node **head,int x, int y)
{
    Node *tmp = makeNode(x);
    if((*head)->data == x){
        tmp->next=(*head);
        *head = tmp;
    }
    else{
            Node* tmp2 = *head;
        while(tmp2->next->data != y){
            tmp2 = tmp2->next;
        }
        tmp->next = tmp2->next;
        tmp2->next = tmp;
    }
}
void Remove(Node **head, int x)
{
    Node* tmp = *head;
    if((*head) == NULL) return ;
    if((*head) -> data == x){
        (*head) = (*head)->next;
        free(tmp);
    }
    else{
        while(tmp->next->data != x){
            tmp = tmp->next;
        }
    Node* tmp2= tmp->next;
        tmp->next = tmp->next->next;
        free(tmp2);
    }
}

void printList(Node *head)
{
    while(head != NULL)
    {
        cout << head->data << ' ';
        head = head->next;
    }
}
int cntNode(Node* head)
{
    int cnt=0;
    while(head->next!=NULL){
        ++cnt;
        head=head->next;
    }
    ++cnt;
    return cnt;
}
int findNode(Node *head, int x)
{
    int n = cntNode(head);
    for(int i=1;i<=n;i++){
        if(head->data == x) return 0;
        head = head->next;
    }
    return 1;
}
void Reverse(Node **head)
{
    Node* cur = *head;
    Node* next = NULL;
    Node* prev = NULL;
    while(cur != NULL){
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    *head = prev;
}
int main()
{
    Node* head = NULL;
    int n;
    freopen("test3-2.txt","r",stdin);
    cin >> n;
    for(int i=1;i<=n;i++){
        int x; cin>>x;
        addLast(&head,x);
    }
    while(1)
    {
        char cmd[30];
        int num1,num2;
        cin >> cmd ;
        if(strcmp(cmd,"#")==0) break;
        if(strcmp(cmd,"addlast")==0){
                cin >> num1;
            if(findNode(head,num1)){
                addLast(&head,num1);
            }
        }
        else if(strcmp(cmd,"addfirst")==0){
                cin >> num1;
            if(findNode(head,num1)){
                addFirst(&head,num1);
            }
        }
        else if(strcmp(cmd,"addbefore")==0){
            cin >> num1 >> num2;
            if(findNode(head,num1)){
                addBefore(&head,num1,num2);
            }
        }
        else if(strcmp(cmd,"addafter")==0){
            cin >> num1 >> num2;
            if(findNode(head,num1)){
                addAfter(head,num1,num2);
            }
        }
        else if(strcmp(cmd,"remove")==0){
                cin >> num1 ;
            if(findNode(head,num1)==0){
                Remove(&head,num1);
            }
        }
        else if(strcmp(cmd,"reverse")==0){
            Reverse(&head);
        }
    printList(head);
    cout << endl;
    }
    return 0;
}
