// Problem: Chapter 3 - Linked list Manipulation
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *next;
};

node *makeNode(int v)
{
    node *new_node = new node();
    new_node->data = v;
    new_node->next = NULL;
    return new_node;
}
node *findNode(node *head, int k)
{
    node *cur = head;
    while (cur != NULL)
    {
        if (cur->data == k)
        {
            return cur;
        }
        cur = cur->next;
    }
    return NULL;
}
node *InsertToLast(node *head, int X)
{ // pass by value
    node *new_node = makeNode(X);
    if (head == NULL)
        head = new_node;
    else
    {       
        node *last = head;
        while (last->next != NULL)
                last = last->next; // move to the last node
        last->next = new_node;
        
    }
    return head;
}
node *sortLinkedList(node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    node *sortedList = NULL;
    node *current = head;

    while (current != NULL)
    {
        node *nextNode = current->next;
        if (sortedList == NULL || current->data < sortedList->data)
        {
            current->next = sortedList;
            sortedList = current;
        }
        else
        {
            node *temp = sortedList;
            while (temp->next != NULL && current->data >= temp->next->data)
            {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = nextNode;
    }

    return sortedList;
}

node *removeKthNode(node *head, int k)
{
    if(head == nullptr || k <= 0)
        return head;
    else if(k == 1){
        node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    node *current = head;
    int count = 1;
    while (current != nullptr && count < k - 1)
    {
        current = current->next;
        count++;
    }

    if (current != nullptr && current->next != nullptr)
    {
        node *temp = current->next;
        current->next = temp->next;
        free(temp);
    }

    return head;
}
void printList(node *head)
{
    node *cur = new node();
    for (cur = head; cur != NULL; cur = cur->next)
    {
        cout << cur->data << " ";
    }
    cout << endl;
}

node *p[5];
int main()
{
    int check, id, number;
    freopen("test3.txt", "r", stdin);
    for (int i = 0; i <= 3; i++)
    {
        p[i] == NULL;
    }
    while (true)
    {
        cin >> check;
        if (check == -1)
            break;
        p[1] = InsertToLast(p[1], check);
    }
    p[1] = sortLinkedList(p[1]);
    while (true)
    {
        cin >> check;
        if (check == -1)
            break;
        p[2] = InsertToLast(p[2], check);
    }
    p[2] = sortLinkedList(p[2]);

    // cout << "xong";
    string s;
    while (true)
    {
        cin >> s;
        if (s == "insert")
        {
            cin >> id >> number;
            p[id] = InsertToLast(p[id], number);
            p[id] = sortLinkedList(p[id]);
// printList(p[id]);
        }
        else if (s == "merge")
        {
            while (p[1] != NULL)
            {
                p[3] = InsertToLast(p[3], p[1]->data);
                p[1] = p[1]->next;
            }
            while (p[2] != NULL)
            {
                p[3] = InsertToLast(p[3], p[2]->data);
                p[2] = p[2]->next;
            }
            p[3] = sortLinkedList(p[3]);
            // merge xong dung
            printList(p[3]);
            break;
        }
        else if (s == "remove")
        {
            cin >> id >> number;
            number = number + 1;
            // if(number == 1) cout <<"O vcl: " <<number << endl;
            p[id] = removeKthNode(p[id], number);
            p[id] = sortLinkedList(p[id]);
// printList(p[id]);

        }
        else if (s == "print")
        {
            cin >> id;
            printList(p[id]);
        }
    }
    return 0;
}