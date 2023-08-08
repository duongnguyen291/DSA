#include <bits/stdc++.h>
using namespace std;

typedef struct node{
	int day;
	char regionCode[20];
	int patient;
	node *next;
}node;
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
	if(root== NULL) return 0;
	node *cur = root;
	while(cur !=NULL){
		if(cur->day == day && strcmp(cur->regionCode, region) == 0) return 1;
		cur = cur->next;
	}
	return 0;
}
node *addNode(node *root,int day, char *region, int patient){
	if(tontai(root,day,region)) root;
	if(root == NULL) return makeNode(day, region, patient);
	node *cur = root;
	while(cur->next!=NULL) cur = cur->next; //dung o nut gan cuoi cur->next =NULL
	cur->next = makeNode(day,region, patient);
	return root;
}
int numberPatient(node *root){
	if(root == NULL) return 0;
	int res = 0;
	node *cur = root;
	while(cur!=NULL){
		res += cur->patient;
		cur = cur->next;
	}
	return res;
}
int tontairegionandday(node *root, char *region, int day){
	if(root == NULL) return 0;
	node *cur = root;
	while(cur!=NULL){
			if(cur->day == day &&strcmp(cur->regionCode ,region)==0){
				return 1;
			}
			cur = cur->next;
		}
	return 0;
}
void regionAndDay(node *root, char *region,int day){
	if(root == NULL) return;
	node *cur = root;
	//check co ton tai khong ?
	if(tontairegionandday(root,region,day)){
		while(cur!=NULL){
			if(cur->day == day &&strcmp(cur->regionCode ,region)==0){
				printf("%d\n",cur->	patient);
			}
			cur = cur->next;
		}
	}
	else { printf("0\n");}
}
int patientPeriod(node *root, int s, int e){
	if(root == NULL) return 0;
	int res = 0;
	node *cur = root;
	while(cur !=NULL){
		if(cur->day >=s&&cur->	day <=e) res += cur->patient;
		cur = cur->next;
	}
	return res;
}
int patientRegion(node *root, char *region){
	if(root == NULL) return 0;
	int res = 0;
	node *cur = root;
	while(cur !=NULL){
		if(strcmp(cur->regionCode,region) == 0) res += cur->patient;
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
			root = addNode(root,day, region, patient);
		}
		else if(s == "$CountTotalPatients"){
			int temp = numberPatient(root);
			printf("%d\n",temp);
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
