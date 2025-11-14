#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n, j, k;
	cin >> n >> j >> k;
	vector<int> v(n);
	int maxs = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		maxs = max(maxs, v[i]);
	}

	if ((n - k + 2) <= n) {
		cout << "YES" << endl;
		return;
	}
	if (v[j-1] == maxs) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while (t--) solve();

	return 0;
}
