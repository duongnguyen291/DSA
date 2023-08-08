#include <bits/stdc++.h>
using namespace std;
typedef struct node{
    char ID[12];
    int amount;
    char date[100];
    double money;
    node *next;
}node;
node *makeNode(node *head, char ID[], int amount,char date[], double money ){
    node *p = new node();
    if(p == NULL){
        cout << "loi truy cap du lieu";
        exit(1);
    }
    strcpy(p->ID, ID); 
    strcpy(p->date,date);
    p->amount = amount; p->money = money; p->next =NULL;
    return p;
}

void addNode(node **head, char ID[], int amount,char date[], double money){
    if(*head == NULL){
        *head = makeNode(*head, ID, amount, date, money);
    }
    else{
        node *p = makeNode(*head, ID, amount, date, money);
        node *cur = *head;
        while(cur->next !=NULL) cur = cur->next;
        cur->next = p;
    }
}
void readItem(node **head){
    char ID[12], newLine[100];
    int amount;
    char date[100];
    double money;
    int count = 0;
    while(1){
        scanf("%s ",ID); 
        // cout << ID << "\n";
        if(strcmp(ID,"-1") == 0) break;
        else{
            cin >> amount;
            getchar();
            fgets(newLine, sizeof(newLine),stdin);
            newLine[strcspn(newLine,"\n")] = 0;
            strcpy(date,newLine);
            cin >> money;
            getchar();

        }
        count++;
        addNode(head, ID, amount, date,money);
    }
    cout << "Total: " << count << "\n";
}
void addNewItems(node **head){
    char ID[12],newLine[100];
    int amount;
    char date[100];
    double money;
    while(1){
        scanf("%s ",ID); 
        if(strcmp(ID,"-1") == 0) break;
        else{
            cin >> amount;
            getchar();
            fgets(newLine, sizeof(newLine),stdin);
            newLine[strcspn(newLine,"\n")] = 0;
            strcpy(date,newLine);
            cin >> money;
            getchar();
        }
        addNode(head, ID, amount, date,money);
    }
}
void printNode(node **head){
    node *p = *head;
    while(p!=NULL){
        // cout << p->ID << "+" << p->amount << "+"<<p->date<<"+"<<p->money <<endl;
        p= p->next;
    }
}
void findItem(node **head){
    char ID[12],newLine[100];
    while(1){
        node *p =NULL;
        fgets(newLine,sizeof(newLine), stdin);
        newLine[strcspn(newLine,"\n")] = 0;
        sscanf(newLine,"%s",ID);
        // cout << ID << "\n"; 
        if(strcmp(ID, "-1") == 0) break;
        else{
            node *temp = *head;
            while(temp!=NULL){
                if(strcmp(temp->ID,ID) == 0){
                    p = temp;
                    // cout<< p->date<< "\n";

                }
                temp = temp->next;
            }
            if(p !=NULL){
                cout << "Item's already added at "  << p->date << "\n";
            }
            else cout << "Item NOT FOUND\n";
        }
    }
}
double totalMoney(node **head){
    double res = 0;
    node *cur = *head;
    while(cur!=NULL){
        res = res + cur->money * cur->amount;
        cur = cur->next;
    }
    return res;
}
int reducefuntion(node **head, char ID[], int number){
    node *cur = *head;
    node *prev = NULL;
    while(cur !=NULL){
        if(strcmp(cur->ID,ID) == 0){
            if(cur->amount > number){
                cur->amount = cur->amount - number;
                return 1;
            }
            //trường hợp số lượng cần xóa lớn hơn số lượng đã có->xóa luôn
            //ID ở ngay đầu
            if(prev ==NULL){
                *head = cur->next;
            }
            else{
                prev->next = cur->next;
            }
            free(cur);
            return 1;
        }
        prev = cur;
        cur = cur->next;
    }
    return 0;
}
void reduce(node **head){
    char ID[12],newLine[100];
    int number;
    while(1){
        fgets(newLine,sizeof(newLine),stdin);
        newLine[strcspn(newLine, "\r\n")] = 0;
        sscanf(newLine,"%s %d", ID,&number);
        if(strcmp(ID,"-1") == 0) break;
        if(reducefuntion(head,ID,number)){
            cout << "DONE Remove\n"; 
        }
        else cout << "ID NOT FOUND\n";
    }
}

/*Total: 3
DONE Remove
DONE Remove
Item NOT FOUND
Total price: 57.50*/
int main(){
    freopen("test1.txt","r",stdin);
    node *head = NULL;
    int n;
    double m;
    string s;
    string k;
    while(true){
        getline(cin,s);

        if(s == "-1") break;
        else if(s == "? readCart"){
            readItem(&head);
        }
        else if(s == "? findItemsByID"){
            findItem(&head);
        }
        else if(s == "? reduceItemQuantityByIDs"){
            reduce(&head);
        }
        else if(s == "? addNewItems"){
            addNewItems(&head);
        }
        else if(s == "print"){
            printNode(&head);
        }
        else if(s == "? checkCartTotalPrice"){
            printf("Total price: %.2lf\n", totalMoney(&head));
        }
        else{
            cout <<"Loi: "<<s<<"\n"; 

        }
    }

    return 0;
}