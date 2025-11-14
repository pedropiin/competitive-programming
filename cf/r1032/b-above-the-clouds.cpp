#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n; cin >> n;
	string s; cin >> s;

	vector<int> freq(26, 0);
	for (int i = 0; i < n; i++) freq[s[i]-'a']++;
	for (int i = 1; i < n-1; i++) {
		freq[s[i]-'a']--;
		if (freq[s[i]-'a'] > 0) {
			cout << "Yes" << endl;
			return;
		}
	}
	cout << "No" << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}
