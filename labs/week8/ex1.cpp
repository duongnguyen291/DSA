#include <bits/stdc++.h>
using namespace std;
struct Polnynom{
    int coef;
    int exp;
    struct Polnynom *next;
};
Polnynom *p[10001];
Polnynom *makeNode(int c, int e){
    Polnynom *p = new Polnynom();
    p->coef = c; p->exp = e; 
    p->next = NULL;
    return p;
}
Polnynom *destroy(Polnynom *head){
    if(head != NULL){
        Polnynom *del = head;
        while(del != NULL){
            head = head ->next;
            free(del);
            del = head;
        }
    }
    return NULL;
}
void printList(Polnynom *head){
    Polnynom *cur = head;
    while(cur!=NULL){
        cout << cur-> coef  <<" " <<cur->exp <<" " ;
        cur = cur ->next;
    }
    cout << endl;
}
void evaluatePoly(Polnynom *head, int x){
    if(head == NULL) cout << 0;
    else{
        Polnynom *cur = head;
        int result = 0;
        while(cur!=NULL){
            result +=(cur->coef * (int)pow(x,cur->exp));
            cur = cur->next;
        }
        cout << result;
    }
}
Polnynom *addTermRecursive(Polnynom *head,int c, int e){
    if(head == NULL) return makeNode(c,e);
    if(head ->exp == e){head->coef += c; return head;}
    if(head ->exp < e){
        Polnynom *newNode = makeNode(c,e);
        newNode->next = head;
        return newNode;
    }
        head ->next = addTermRecursive(head->next,c,e);
        return head;
    }
Polnynom *addTerm(Polnynom *head,int c, int e){

    //-------------------------------------------------------
    Polnynom *p1 = NULL,*p2 = head;
    while(p1!=NULL){
        if(p2->exp = e){
            p2->coef+=c;
            return head;
        }
        else if(p2->exp <e){
            if(p1==NULL){
                Polnynom *newNode = makeNode(c,e);
                newNode->next = head;
                return newNode;
            }
            else{
                Polnynom *newNode = makeNode(c,e);
                p1->next = newNode;
                newNode->next = p2;
                break;
            }
        }
        else{
            p1= p2; p2 = p2->next;
        }
    }
    if(p2==NULL){
        Polnynom *newNode = makeNode(c,e);
        p1->next = newNode;
    }
    return head;
}

Polnynom *addPoly(Polnynom *head1, Polnynom *head2, Polnynom *headR){
    if(headR != NULL) headR = destroy(headR);
    //step 1: copy all nodes ò list head1 to list headR
    Polnynom *cur = head1;
    while(cur != NULL){
        headR = addTermRecursive(headR, cur->coef, cur->exp);
        cur = cur->next;
    }
    cur = head2;
    while(cur != NULL){
        headR = addTermRecursive(headR, cur->coef, cur->exp);
        cur = cur->next;
    }
    return headR;
}
int main(){
    for(int i = 1; i <= 10000;i++) {p[i] == NULL;}
    string s;
    int id, coef, exp;
    freopen("test1.txt","r",stdin);
    while(true){
        cin >> s;
        if(s == "*"){break;}
        if(s == "AddTerm"){
            cin >> id >> coef >> exp;
            p[id] = addTermRecursive(p[id], coef, exp);
        }
        else if(s == "AddPoly"){
            int id1,id2,idR;
            cin >> id1 >> id2 >> idR;
            p[idR] = addPoly(p[id1],p[id2],p[idR]);
        }
        else if(s == "EvaluatePoly"){
            int idE, val;
            cin >> idE >> val;
            evaluatePoly(p[idE], val);
        }
        else if(s == "PrintPoly"){
            int polID1;
            cin >> polID1;
            printList(p[polID1]);
        }
        else if(s == "Destroy"){
            int polID2;
            cin >> polID2;
            p[polID2] = destroy(p[polID2]);
        }
    }



}