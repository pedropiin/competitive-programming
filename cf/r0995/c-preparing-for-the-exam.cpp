#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n, m, k; cin >> n >> m >> k;
	vector<int> a(m);
	for (int i = 0; i < m; i++) cin >> a[i];
	ll t; ll missing = (ll)(n * (ll)(n+1))/2;
	for (int i = 0; i < k; i++) {
		cin >> t;
		missing -= t;
	}
	
	if (k < n-1) {
		string ans(m, '0');
		cout << ans << endl;
		return;
	} else if (k == n) {
		string ans(m, '1');
		cout << ans << endl;
		return;
	}

	string ans = "";
	for (int i = 0; i < m; i++) {
		if (a[i] == missing) ans += '1';
		else ans += '0';
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
