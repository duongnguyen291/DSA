
#include <bits/stdc++.h>
using namespace std;

int getCount(int N, vector<string>& s)
{
	// Stores frequency array
	// and its count
	map<vector<int>, int> mp;
	int ans = 0;
	for (int i = 0; i < N; i++) {
		vector<int> a(26, 0);
		for (int j = 0; j < s[i].size(); j++) {
			a[s[i][j] - 'a']++;
		}
		for (int j = 0; j < 26; j++) {
			a[j] = (a[j] % 2);
		}

		ans += mp[a];

		// Frequency of single character
		// can be possibly changed,
		// so change its parity
		for (int j = 0; j < 26; j++) {

			vector<int> changedCount = a;
			if (a[j] == 0)
				changedCount[j] = 1;
			else
				changedCount[j] = 0;

			ans += mp[changedCount];
		}

		mp[a]++;
	}

	return ans;
}

int main()
{
    freopen("test1.txt","r",stdin);
	int N;
    cin >> N;
    vector<string> A;
    string s;
    for(int i = 0; i < N; i++) {
        cin >> s;
        A.push_back(s);
    }
	cout << getCount(N, A);

	return 0;
}
