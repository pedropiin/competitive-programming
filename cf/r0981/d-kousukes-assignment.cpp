#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n; cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];

	int ans = 0;
	set<ll> m; m.insert(0);
	ll curr = 0;
	for (int i = 0; i < n; i++) {
		curr += (ll)v[i];
		if (m.find(curr) != m.end()) {
			ans++;
			m.clear();
			m.insert(0);
			curr = 0;
		} else {
			m.insert(curr);
		}
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

