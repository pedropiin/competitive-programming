#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n; cin >> n;
	string s, t;
	cin >> s >> t;

	int freq[26] = {};
	for (int i = 0; i < 26; i++) freq[i] = 0;

	for (int i = 0; i < n; i++) freq[s[i]-'a']++;
	for (int i = 0; i < n; i++) freq[t[i]-'a']--;

	for (int i = 0; i < 26; i++) {
		if (freq[i] != 0) {
			cout << "NO" << endl;
			return;
		}
	}

	cout << "YES" << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while (t--) solve();

	return 0;
}
