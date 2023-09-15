#include <stdio.h>
#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};
 
struct ListNode *makeNode(int v){
    struct ListNode *p = (struct ListNode*) malloc(sizeof(struct ListNode));
    p->val = v;
    p->next = NULL;
    return p;
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int temp = 0;
    struct ListNode *data = NULL;
    while(l1 != NULL || l2 != NULL){
    if(temp == 1 &&l1->val + l2->val >= 10){
        data->val = l1->val + l2->val + 1;
        temp = 1;
    }
    else if( temp == 0 && l1->val +l2->val >=10){
        data->val = l1->val + l2->val;
        temp = 1;    
    }
    else if(temp == 1 && l1->val + l2->val < 10){
        data->val = l1->val + l2->val +1;
        temp = 0;
    }
    else if(temp == 0 && l1->val + l2->val < 10){
         data->val = l1->val + l2->val;
         temp = 0;
    }
    l1 =  l1->next;
    l2 = l2->next;
    data->next= makeNode(0);
    }
    return data;
}
int main(){

    return 0;
}