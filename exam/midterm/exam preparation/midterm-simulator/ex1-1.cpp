/*Ex1" E-commerce*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
#define INT_MIN -999999

int month[MAX];
char cmd[15];

int main() {
	int i;
	for(i = 1; i <= 12; i++) month[i] = 0;
	while (1) {
		scanf("%s", cmd);
		int number = (cmd[5] - '0') * 10 + (cmd[6] - '0');
	//	printf("%d ", number); 
		month[number]++; 
		if (strcmp(cmd, "#") == 0) 
			break;
	}
//	for (i = 1; i <= 12; i++) printf("%d ", month[i]);
	int result = INT_MIN;
	for (i = 1; i <= 12; i++) {
		if (result < month[i]) result = month[i];
	}
	printf("%d", result);
	
	return 0;	
}