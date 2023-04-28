#include<stdio.h>
#define N 1000001

char T[N];
int n;

int main() {
	freopen("test.txt", "r", stdin);
	n = 0;
	char s[1000];
	while (!feof(stdin)) {
		char c = fgetc(stdin);
		T[n] = c;
		n += 1;
	}
	int i = 0, cnt = 0, flag = 0;
	while (i < n) {
		if (T[i] == ' ' || T[i] == '\t' || T[i] == '\n' || T[i] == -1)
			flag = 0;
		else if (flag == 0) {
			cnt++;
			flag = 1;
		}
		i++;
	}
	printf("%d", cnt);
}