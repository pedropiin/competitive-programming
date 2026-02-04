#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n, k; cin >> n >> k;
	string s, t; cin >> s >> t;

	vector<int> sfreq(26, 0), tfreq(26, 0);
	for (int i = 0; i < n; i++) {
		sfreq[s[i]-'a']++;
		tfreq[t[i]-'a']++;
	}
	for (int i = 0; i < 26; i++) {
		if (sfreq[i] != tfreq[i]) {
			cout << "NO" << endl;
			return;
		}
	}

	for (int i = 0; i < n; i++) {
		if (s[i] != t[i]) {
			if (i - k < 0 && i + k >= n) {
				cout << "NO" << endl;
				return;
			}
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

