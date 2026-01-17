#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n, m; cin >> n >> m;
	string a; cin >> a;
	vector<int> freq(7, 0);
	for (char c : a) freq[c-'A']++;

	int ans = 0;
	for (int i = 0; i < 7; i++) {
		if (freq[i] < m) ans += m-freq[i];
	}

	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while (t--) solve();

	return 0;
}

