#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n; cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];

	ll c2 = (ll)(((ll)(2 * v[0]) - v[1]) / (n+1));
	ll c1 = (ll)(v[1] + c2) - v[0];
	
	if (c1 < 0 || c2 < 0) {
		cout << "NO" << endl;
		return;
	}

	for (int i = 1; i <= n; i++) {
		ll t = (ll)(c1 * i) + (ll)(c2 * (n - i + 1));
		if (v[i-1] != t) {
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
