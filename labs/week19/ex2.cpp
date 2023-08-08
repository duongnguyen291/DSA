#include <bits/stdc++.h>
using namespace std;
#define MAXX 10000
typedef struct node{
	int day;
	char regionCode[20];
	int patient;
	node *next;
}node;
node *data[MAXX];
int total = 0;
node *makeNode(int day, char *r,int patient){
	node *p = new node();
	if(p == NULL){
		printf("Memory error!"); exit(1);
	}
	p->day = day;
	p->patient = patient;
	strcpy(p->regionCode,r);
	p->next = NULL; 
	return p;
}
int tontai(node *root, int day, char *region){
    int k = atoi(&region[2]);
	if( data[k%MAXX] == NULL) return 0;
	node *cur = data[k%MAXX];
	while(cur !=NULL){
		if(cur->day == day && strcmp(cur->regionCode, region) == 0) return 1;
		cur = cur->next;
	}
	return 0;
}
void addNode(node *root,int day, char *region, int patient){
    int k = atoi(&region[2]);
	if(tontai(root,day,region)) return;
	if(data[k%MAXX] == NULL) {
        data[k%MAXX] = makeNode(day, region, patient);
        total +=patient;
        return;
    }
	node *cur = data[k%MAXX];
    node *p = makeNode(day, region, patient);
    p->next = data[k%MAXX];
    data[k%MAXX] = p;
    total+=patient;
}

int tontairegionandday(node *root, char *region, int day){
    int k = atoi(&region[2]);
	if(data[k%MAXX] == NULL) return 0;
	node *cur = data[k%MAXX];
	while(cur!=NULL){
			if(cur->day == day && strcmp(cur->regionCode ,region) == 0){
				return 1;
			}
		cur = cur->next;
		}
	return 0;
}
void regionAndDay(node *root, char *region,int day){
    int k = atoi(&region[2]);
	if(data[k%MAXX] == NULL) {return;}
	node *cur = data[k%MAXX];
	//check co ton tai khong ?
	if(tontairegionandday(root,region,day)){
		while(cur!=NULL){
			if(cur->day == day &&strcmp(cur->regionCode ,region)==0){
				printf("%d\n",cur->patient);
			}
			cur = cur->next;
		}
	}
	else {printf("0\n");}
}
int patientPeriod(node *root, int s, int e){
    int res = 0;
    for(int i = 0;i <MAXX;i++){
        if(data[i%MAXX] == NULL) continue;
        node *cur = data[i%MAXX];
        while(cur !=NULL){
            if(cur->day >=s&&cur->day <=e) res += cur->patient;
            cur = cur->next;
        }
    }
    return res;
}
int patientRegion(node *root, char *region){
    int k = atoi(&region[2]);
	if(data[k%MAXX] == NULL) return 0;
	int res = 0;
	node *cur = data[k%MAXX];
	while(cur !=NULL){
		res += cur->patient;
		cur = cur->next;
	}
	return res;
}

int main(){
	freopen("test1.txt","r",stdin);
	string s;
	int day, patient;
	char region[20];
	node *root = NULL;
	int start,end;
	while(1){
		cin >> s;
		if(s == "***") break;
		else if(s == "$Update"){
			scanf("%s %d %d",region, &day,&patient);
			// printf("%s %d %d",region, day,patient);
			addNode(root,day, region, patient);
		}
		else if(s == "$CountTotalPatients"){
			printf("%d\n",total);
		}
		else if(s == "$FindNumberPatients"){
			scanf("%s %d",region, &day);
			regionAndDay(root,region,day);	
		}
		else if(s == "$CountNumberPatientsOfPeriod"){
			scanf("%d %d",&start,&day);
			int temp = patientPeriod(root, start,day);
			printf("%d\n",temp);
		}	
		else if(s == "$CountNumberPatientsOfRegion"){
			scanf("%s",region);
			int temp = patientRegion(root,region);
			printf("%d\n",temp);
		}	
	}		
	return 0;
}
