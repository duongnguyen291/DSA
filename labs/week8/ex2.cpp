#include<bits/stdc++.h>
using namespace std;

char x[1000];
stack<char> s;

int isPair(char x, char y) {
	if (x == '(' && y == ')') return 1;
	if (x == '{' && y == '}') return 1;
	if (x == '[' && y == ']') return 1;
	return 0;
}

int solve(char *X) {
	for (int i = 0; i < strlen(X); i++) {
		if (X[i] == '(' || X[i] == '{' || X[i] == '[') {
			s.push(X[i]);
		} else if (X[i] == ')' || X[i] == '}' || X[i] == ']') {
			if (s.empty()) return 0;
			else {
				char temp = s.top();
				s.pop();
				if (isPair(temp, X[i]) == 0) {
				//	printf("%d ", isPair(temp, X[i]));
					return 0;
				}
			}
		}
	}	
	if (s.empty()) return 1;
	else return 0;
}

int main() {
	scanf("%s", x);
	if (solve(x) == 1) printf("%d", 1);
	else printf("%d", 0);
	return 0;
}