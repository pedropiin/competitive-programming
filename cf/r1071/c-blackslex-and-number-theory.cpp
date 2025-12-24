#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n; cin >> n;
	vector<int> v(n);
	int mn = 1000000005;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		mn = min(mn, v[i]);
	}

	int smn = 1000000005;
	for (int i = 0; i < n; i++) {
		if (v[i] == mn) continue;

		int t = v[i] - mn;
		smn = min(smn, t);
	}
	cout << max(mn, smn) << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while (t--) solve();

	return 0;
}

