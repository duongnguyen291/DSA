#include <bits/stdc++.h>
#define MAXX 10000
using namespace std;
typedef struct node{
	char ID[10];
	char problem[10];
	int hour, minute,second;
	int status;
	int point;
	node *next;
}node;
node *data[MAXX] = {NULL};
int totalSub = 0;
int totalErr = 0;
node *makeNode(char *ID, char *problem, int hour, int minute,int second, int status, int point){
	node *p = new node();
	if(p==NULL){
		printf("\nMemory");exit(1);
	}
	strcpy(p->ID,ID); strcpy(p->problem,problem);
	p->hour = hour; 
	p->minute = minute;
	p->second = second;
	p->point = point;
    p->status = status;//
	p->next = NULL;
	return p;
}
void addNode(char *ID,char *problem, int  hour, int minute, int second,int status,int point){
	int k = atoi(&ID[1]);
	if(data[k%MAXX] == NULL){
		data[k%MAXX] = makeNode(ID,problem,hour,minute,second,status,point);
		totalSub++;
		totalErr+=status;
		return;
	}
		node *cur = data[k%MAXX];
		node *p = makeNode(ID,problem,hour,minute,second,status,point);
		p->next = data[k%MAXX];
		data[k%MAXX] = p;
		totalSub++;
		totalErr+=status;
	return;
}
int numberErrorID(char *ID){
	int k = atoi(&ID[1]);
	if(data[k%MAXX] == NULL) return 0;
	node *cur = data[k%MAXX];
	int res = 0;
	while(cur != NULL){
		if(cur->status == 1) res++;
		cur = cur->next;
	}
	return res;
}
int totalPoint(char *ID){
	int k = atoi(&ID[1]);
	if(data[k%MAXX] == NULL) return 0;
	//can tim so diem max cua problem
	int maxP[100] = {0};

	int res = 0;
	node *cur = data[k%MAXX];
	while(cur != NULL){
		int indexP = atoi(&cur->problem[1]);
		if(cur->point > maxP[indexP]) maxP[indexP]  = cur->point;
		cur = cur->next;
	}
	for(int i = 0; i < 100;i++){
		res += maxP[i];
	}
	return res;
}
int time(int hour, int minute, int second){
	return hour*3600 + minute*60 + second;
}
int numbertime(int h1,int m1,int s1,int h2,int m2,int s2){
	int start = time(h1,m1,s1);
	int end = time(h2,m2,s2);
	int sub = 0;
	int res = 0;
	for(int i = 0 ; i <MAXX;i++){
		node *cur = data[i%MAXX];
		while(cur!=NULL){
			sub = time(cur->hour,cur->minute, cur->second);
			if(sub >= start && sub <= end) res++;
			cur = cur->next;
		}
	}
	return res;
}
int main(){
	freopen("input_testcase_19.txt","r",stdin);
	char newLine[100];
	char ID[10];
	char problem[10], temp[10];
	int hour, minute,second;
	int status;
	int point;
	int h1,m1,s1,h2,m2,s2;
	while(1){
		fgets(newLine, sizeof(newLine),stdin);
		newLine[strcspn(newLine,"\r\n")] = 0;
		if(newLine[0] == '#') break;		
		sscanf(newLine, "%s %s %d:%d:%d %s %d", ID,problem, &hour,&minute,&second,temp,&point);
		if(strcmp(temp,"ERR") == 0) status = 1;
		else if(strcmp(temp,"OK") == 0) status = 0;
		addNode(ID,problem, hour, minute, second,status,point);
	}
	string s;
	while(1){
		cin >> s;
		if(s == "#") break;
        else if(s == "?total_number_submissions"){
            printf("%d\n",totalSub);
        }
        else if(s == "?number_error_submision"){
            printf("%d\n",totalErr);
        }
        else if(s == "?number_error_submision_of_user"){
            scanf("%s ", ID);
            int temp = numberErrorID(ID);
            printf("%d\n",temp);
        }
        else if(s == "?total_point_of_user"){
            scanf("%s ", ID);
            int temp = totalPoint(ID);
            printf("%d\n",temp);
        }
        else if(s == "?number_submission_period"){
            scanf("%d:%d:%d %d:%d:%d",&h1,&m1,&s1,&h2,&m2,&s2);
            int temp = numbertime(h1,m1,s1,h2,m2,s2);
            printf("%d\n",temp);
        }
		
	}
	return 0;
}
