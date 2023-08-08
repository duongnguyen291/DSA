//Problem: Bank Transaction
#include <bits/stdc++.h> 
using namespace std;
#define MAXX 100010
typedef struct node{
    char fromAcc[20];
    char toAcc[20];
    int money;
    char time[10];
    char atm[10];
    bool visited;
    node *next;
}node;
node *data[MAXX]; //luu dia chi cac cay
char accountName[MAXX][20];
node *makeNode(char fromAcc[], char toAcc[],int money, char time[],char atm[]){
    node *p = new node();
    if(p==NULL){cout << "Memory!";exit(1);}
    strcpy(p->fromAcc,fromAcc); strcpy(p->toAcc,toAcc); strcpy(p->time,time); strcpy(p->atm,atm);
    p->money = money;
    p->visited = false;
    p->next = NULL;
    return p;
}
void addNode(node *root, char fromAcc[], char toAcc[],int money, char time[],char atm[]){
    int k  = stoll(&fromAcc[5]);
    int p = stoll(&toAcc[5]);
    if(data[k%MAXX] == NULL) {
        data[k%MAXX] = makeNode(fromAcc,toAcc,money, time, atm);
        return;
    }
    node *newNode = makeNode(fromAcc,toAcc,money, time,atm);
    newNode->next= data[k%MAXX];
    data[k%MAXX]= newNode;
    return;    
}
char bientoancuc[20];
int cycle(char *s, int k, int step){
    int account = stoi(&s[5]);
    if (step == k && strcmp(s,bientoancuc) == 0) {
        return 1; // A cycle of length k is found
    }
    for (node *temp = data[account % MAXX]; temp != NULL; temp = temp->next){
        if (temp->visited == false) {
            temp->visited = true;
            int found = cycle(temp->toAcc, k, step + 1);
            temp->visited = false; // Reset visited status for the next iteration
            if (found) {
                return 1; // Found a cycle in the current branch
            }
        }
    }
    return 0; // No cycle found in this branch
}
char sortList[MAXX][20];
void sortListbyName(){
    for(int i = 0; i < MAXX;i++){
        if(data[i%MAXX] != NULL) strcpy(sortList[i%MAXX],data[i%MAXX]->fromAcc);
            for(node *temp = data[i%MAXX]; temp!=NULL;temp = temp->next){
                int l = stoi(&temp->toAcc[5]);
                if(data[l%MAXX] == NULL) strcpy(sortList[l%MAXX],temp->toAcc);
            }
    }
}
int main(){
    char fromAcc[20];
    char toAcc[20];
    int money;
    char time[10];
    char atm[10];
    char newLine[100];
    node *root = NULL;
    int count = 0;
    int total = 0;
    freopen("test4.txt","r",stdin);
    while(1){
        fgets(newLine,sizeof(newLine),stdin);
        newLine[strcspn(newLine,"\n")] = 0;
        if(newLine[0] == '#') break;
        sscanf(newLine, "%s %s %d %s %s", fromAcc,toAcc,&money, time, atm);
        // cout << fromAcc << "+" << toAcc << "+" << money << "+" << time<<"+" << atm << endl;
           
        addNode(root,fromAcc,toAcc,money, time, atm);

        total += money;
        count++;
    }
    char s[20];

    while(1){
        scanf("%s",newLine);
        if(newLine[0] == '#') break;
        else if(strcmp(newLine,"?number_transactions") == 0){
            printf("%d\n",count);
        }
        else if(strcmp(newLine,"?total_money_transaction") == 0){
            printf("%d\n",total);
        }
        else if(strcmp(newLine,"?list_sorted_accounts") == 0){
            sortListbyName();
            for(int i= 0;i<MAXX;i++){
                if(strcmp(sortList[i],"")!=0) printf("%s ",sortList[i]);
            }
            printf("\n");
        }
        else if(strcmp(newLine,"?total_money_transaction_from") == 0){
            scanf("%s", s); 
            int k = stoi(&s[5]);
            int tienAcc = 0;
            for(node *temp = data[k%MAXX]; temp!=NULL;temp = temp->next){
                tienAcc+=temp->money;
            }
            printf("%d\n",tienAcc);

        }
        else if(strcmp(newLine,"?inspect_cycle") == 0){
            int check;
            scanf("%s %d", s, &check); 
            int k = stoi(&s[5]);
            strcpy(bientoancuc,s);
            for(int i = 0;i <MAXX;i++){
                for (node *temp = data[i % MAXX]; temp != NULL; temp = temp->next){
                    temp->visited=false;
                }
            }
            int temp = cycle(s,check,0); 
            printf("%d\n",temp);
        }
    }
    return 0;
}