// Dynamic Programming C implementation of LCS problem
#include <bits/stdc++.h>
using namespace std;

#include <iostream>
using namespace std;

// lcs with tabulation
int lcs(int s1[], int s2[], int m, int n)
{
	int db[n + 1] = {}; 
	
	for (int i = 1; i <= m; ++i) {
		int prev = db[0];
		for (int j = 1; j <= n; ++j) {
			int temp = db[j];
			if (s1[i - 1] == s2[j - 1])
				db[j] = 1 + prev;
			else
				db[j] = max(db[j - 1], db[j]);
			prev = temp;
		}
	}

	return db[n];
}

int main()
{
	int m, n;
	int a[10010], b[10010];
	cin >> m >> n;
	for (int i = 0; i < m; i++) cin>> a[i];
	for (int j = 0; j < n; j++) cin >> b[j];

	cout << lcs(a, b, m, n);

	return 0;
}