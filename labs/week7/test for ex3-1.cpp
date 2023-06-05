#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct NODE{
    int value;
    struct NODE *next;
};

typedef struct NODE node;

node *makenode(int Value)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->value = Value;
    newnode->next = NULL;
    return newnode;
}

int check(int Value,node* *head)
{
    node* curr = *head;
    
        while(curr != NULL)
        {
            if(curr->value == Value) return 1;
            curr = curr->next;
        }

        return 0;
}

void addtotail(int Value, node* *a)
{
    if(check(Value,a)==1)
    {
        return;
    }
    node* newnode = makenode(Value);
    if(*a == NULL) 
    {
        *a = newnode;
        return;
    }

    node* i;
    i= *a;
    while(i->next != NULL)
    {
        i=i->next;
    }

    i->next = newnode;

}

void addToHead(int Value,node* *head)
{
    // them node có giá trị Value vào head
    if(check(Value,head)==1)
    {
        return;
    }
    node *newnode = makenode(Value);

    if(*head==NULL) *head= newnode;
    else
    {
        newnode->next = *head; 
        *head = newnode;
    }

}

void addAfter(int Value,int preValue,node* *head)
{
    if(check(preValue,head) == 0)
    {
        // printf("Invalid");
        return;
    }

    if(check(Value,head)== 1)
    {
        // printf("Invalid");
        return;
    }

    node* curr= *head;

    while(curr->value != preValue)
    {
       curr = curr->next;
    }
    node* newnode = makenode(Value);

    newnode->next = curr->next;
    curr->next = newnode;
}

void addBefore(int Value,int nextValue,node* *head)
{
    if(check(nextValue,head) == 0)
    {
        printf("Invalid");
        return;
    }

    if(check(Value,head)== 1)
    {
        printf("Invalid");
        return;
    }

    node* curr= *head;

    while(curr->next->value != nextValue)
    {
       curr = curr->next;
    }
    node* newnode = makenode(Value);

    newnode->next = curr->next;
    curr->next = newnode;
}

void print(node *a)
{
    node *temp = a;
    printf("\n");
    while(temp != NULL)
    {
        printf("%d ",temp->value);
        temp = temp->next;
    }

}

void reverse(node* *head)
{
    node* pre;
    node* curr;
    node* next;
    pre = NULL;
    curr = (*head);
    next = (*head)->next;
    

    while(curr != NULL)
    {
        curr->next = pre;
        pre = curr;
        curr = next;
        if(next != NULL)
        next = next->next;
    }

 *head = pre;
}

void delett(int Value, node* *head)
{
    if(check(Value,head) == 0){
        // printf("chua co");
        return;
    }

    if((*head)->value == Value)
    {
        node* del = *head;
        *head = (*head)->next;
        free(del);
        return;
    }
    
    node *curr = *head,*del;
    while(curr != NULL)
    {
        if(curr->next->value == Value) break;
        curr = curr->next;
    }

    del = curr->next;
    curr->next = curr->next->next;
    free(del);
}


int main()
{
    node *head = NULL;
    char request[1000];

    int n,num;
    scanf("%d",&n);
    int i;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&num);
        addtotail(num,&head);
    }

    // print(head);


    do
    {   
        // printf("Nhap lua chon:");
        fflush(stdin);
        scanf("%s",request);

        if(strcmp(request,"addlast") == 0)
        {
            // printf("1\n");
            int value;
            scanf("%d",&value);
            addtotail(value,&head);
        }

        if(strcmp(request,"addfirst") == 0)
        {
            // printf("2\n");
            int value;
            scanf("%d",&value);
            addToHead(value,&head);
        }


        if(strcmp(request,"addafter") == 0)
        {
            // printf("3\n");
            int value,prevalue;
            scanf("%d %d",&value,&prevalue);
            addAfter(value,prevalue,&head);
        }

        if(strcmp(request,"addbefore") == 0)
        {
            // printf("4\n");
            int value,nextvalue;
            scanf("%d %d",&value,&nextvalue);
            addBefore(value,nextvalue,&head);
        }

         if(strcmp(request,"remove") == 0)
        {
            int value;
            scanf("%d",&value);
            delett(value,&head);
        }

        if(strcmp(request,"reverse") == 0)
        {
            reverse(&head);
        }





    }while(strcmp(request,"#") != 0);


    print(head);
}