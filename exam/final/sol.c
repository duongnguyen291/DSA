#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define P 10 // max number problems
#define LEN 10 // max length of userID
#define M 100000 // length of hash table
#define N 100000
typedef struct Node{
	char userID[LEN];
	int submissionErr;
	int point[P];// point[p] is the point of problem p got
	int totalPoint;
	struct Node* left;
	struct Node* right;
}Node;

Node* T[M]; // T[i] is the root of the BST i
int nbSubmissions;
int nbErrSubmissions;
int a[N]; // a[i] is the number of submission at time-point i
int t[N]; // t[i] = a[0] + a[2] + ... + a[i]
// sum a[i] + a[i+1] + . . . + a[j] = t[j] - t[i-1]
Node* makeNode(char* userID,int indexProblem, int point, int err){
	Node* p = (Node*)malloc(sizeof(Node));
	strcpy(p->userID,userID);
	for(int i = 0; i < P; i++) p->point[i] = 0;
	p->point[indexProblem-1] = point;
	p->totalPoint = point;
	p->submissionErr = err;
	p->left = NULL; p->right = NULL;
	return p;
}
Node* findBST(char* userID, Node* r){
	if(r == NULL) return NULL;
	int c = strcmp(userID, r->userID);
	if(c == 0) return r;
	if(c < 0) return findBST(userID, r->left);
	return findBST(userID, r->right);
}
void printUser(Node* p){
	printf("info user %s: ",p->userID);
	for(int i = 0; i < P; i++) printf("%d ",p->point[i]);
	printf("total point = %d\n",p->totalPoint);
}
int h(char* s){
	int c = 0;
	for(int i = 0; i < strlen(s); i++){
		c = (c*256 + s[i])%M;
	}
	return c;
}
int hashTime(char* d){
	int hour = (d[0]-'0')*10 + (d[1]-'0');
	int minute = (d[3]-'0')*10 + (d[4]-'0');
	int second = (d[6]-'0')*10 + (d[7]-'0');

	return hour*3600 + minute*60 + second;
}
Node* insertBST(char* userID, Node* r, int indexProblem, int point,int err){
	if(r == NULL) return makeNode(userID,indexProblem,point,err);
	int c = strcmp(userID,r->userID);
	if(c == 0) return r;
	if(c < 0) r->left = insertBST(userID, r->left,indexProblem,point,err);
	else r->right = insertBST(userID,r->right,indexProblem,point,err);
	return r;
}
void updatePoint(char* userID, int indexProblem, int point,int err){
	//printf("updatePoint %s, indexProblem %d, point %d, err %d\n",userID, indexProblem,point,err);
	int i = h(userID);
	Node* p = findBST(userID, T[i]);
	if(p == NULL){
		T[i] = insertBST(userID,T[i],indexProblem,point,err);
	}else{
		if(p->point[indexProblem-1] < point){
			p->totalPoint = p->totalPoint - p->point[indexProblem-1] + point;
			p->point[indexProblem-1] = point;
			//printf("updatePoint happen"); printUser(p);
		}
		p->submissionErr += err;
	}
}
void run(){
	for(int i = 0; i < M; i++) T[i] = NULL;
	for(int i = 0; i < N; i++) a[i] = 0;
	char cmd[50];
	char userID[11];  char problem[10]; int indexProblem; char sub_time[10]; char status[10];
	int point;
	nbSubmissions= 0;
	nbErrSubmissions = 0;
	while(1){
		scanf("%s",cmd);
		if(strcmp(cmd,"#")==0) break;
		scanf("%s",problem);
		indexProblem = (problem[1]-'0')*10 + problem[2]-'0';
		scanf("%s %s %d",sub_time,status,&point);
		int err = (strcmp(status,"ERR") == 0 ? 1 : 0);
		updatePoint(cmd,indexProblem,point,err);
		nbSubmissions++;
		nbErrSubmissions += err;
		int t = hashTime(sub_time);
		a[t] += 1;
	}
	t[0] = 0;
	for(int i = 1; i < N; i++) t[i] = t[i-1] + a[i];
	char startTime[10], endTime[10];
	while(1){
		scanf("%s",cmd);
		if(strcmp(cmd,"#")==0) break;
		else if(strcmp(cmd,"?total_number_submissions")==0){
			printf("%d\n",nbSubmissions);
		}else if(strcmp(cmd,"?number_error_submision")==0){
			printf("%d\n",nbErrSubmissions);
		}else if(strcmp(cmd,"?number_error_submision_of_user")==0){
			scanf("%s",userID);
			int i = h(userID);
			Node* p = findBST(userID,T[i]);
			int ans = 0;
			if(p != NULL){
				ans = p->submissionErr;
			}
			printf("%d\n",ans);
		}else if(strcmp(cmd,"?total_point_of_user")==0){
			scanf("%s",userID);
			int i = h(userID);
			Node* p = findBST(userID,T[i]);
			int ans = 0;
			if(p != NULL){
				ans = p->totalPoint;
			}
			printf("%d\n",ans);
		}else if(strcmp(cmd,"?number_submission_period")==0){
			scanf("%s",startTime);
			scanf("%s",endTime);
			int s = hashTime(startTime);
			int e = hashTime(endTime);
			int ans = t[e] - t[s-1];
			printf("%d\n",ans);
		}
	}
}
int main(){
	freopen("input_testcase_20.txt","r",stdin);
	//freopen("test/5-number_submission_period.txt","r",stdin);
	run();
	return 0;
}
