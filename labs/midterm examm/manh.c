#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    struct node *next;
    int gt;
}node;
node p[3];
void add(node *po, int value){
    if(po->next==0){
        node *neww=(node*)malloc(sizeof(node));
        neww->next=0;
        neww->gt=value;
        po->next=neww;
        return;
    }
    node *child=po->next;
    int giatri=child->gt;
    if(giatri>value){
        node *neww=(node*)malloc(sizeof(node));
        neww->next=child;
        neww->gt=value;
        po->next=neww;
        return;
    }
    add(po->next,value);
}

 

void print(node *po){
    printf("%d ",po->gt);
    if(po->next!=0)print(po->next);
}

 

void Remove(node *po, int vt, int now){
//    printf("re%d ",po->gt);
    if(now==vt-1){
        if(po->next==0)return;
        node *zui=po->next;
        if(zui->next!=0)po->next=zui->next;
        return;
    }
    if(po->next!=0)Remove(po->next,vt,now+1);
}

 

void Merge(){
    node *run=p[1].next;
    node *neww=(node*)malloc(sizeof(node));
    neww->next=0;
    while(run!=0){
        add(neww,run->gt);
        run=run->next;
    }
    run=p[2].next;
    while(run!=0){
        add(neww,run->gt);
        run=run->next;
    }
    print(neww->next);
}

 

int main(){
    p[1].next=0;
    p[2].next=0;
        freopen("test3.txt","r",stdin);

    while(1){
        int k;
        scanf("%d",&k);
        if(k==-1)break;
        add(&p[1],k);
    }
    while(1){
        int k;
        scanf("%d",&k);
        if(k==-1)break;
        add(&p[2],k);
    }
    while(1){
//            printf("asdfas");
        char dv[15];
        scanf("%s",dv);
        int stt,nu;
        switch(dv[0]){
        case 'i':
            scanf("%d%d",&stt,&nu);
            add(&p[stt],nu);
            break;
        case 'r':
            scanf("%d%d",&stt,&nu);
            Remove(&p[stt],nu,-1);
//            printf("\n");
            break;
        case 'p':
            scanf("%d",&stt);
            if(p[stt].next==0)break;
            print(p[stt].next);
            printf("\n");
            break;
        case 'm':
            Merge();
            return;

 

    }
    }
}

