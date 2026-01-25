#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n; cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];

	sort(a.begin(), a.end());
	ll sm = 0;
	int max_i = 0;
	for (int i = 0; i < n; i++) {
		if ((sm + (ll)b[i]) > (ll)n) break;
		sm += (ll)b[i];
		max_i = i;
	}
	int sword_idx = 0;
	if (n > sm) {
		sword_idx += (n-sm);
	}

	ll ans = (ll)(max_i+1)*((ll)a[sword_idx]);
	int i = max_i;
	while (i >= 0) {
		sword_idx += b[i];
		if (sword_idx > n) break;
		ans = max(ans, (ll)i*((ll)a[sword_idx]));
		i--;
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

