#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	ll n, x, y; cin >> n >> x >> y;
	vector<int> v(n);
	ll s = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		s += v[i];
	}
	if (s <= x+1) {
		cout << 0 << endl;
		return;
	}

	sort(v.begin(), v.end());
	ll upper = s - x;
	ll lower = s - y;

	ll ans = 0;
	vector<int>::iterator l;
	vector<int>::iterator r;
	for (auto it = v.begin(); it != v.end(); it++) {
		ll val = *it;

		if (val >= upper) break;
		else if (upper - val < val) break;
		
		vector<int>::iterator next_it = next(it);
		if (next_it == v.end()) break;

		l = lower_bound(next_it, v.end(), lower-val);
		r = upper_bound(next_it, v.end(), upper-val);

		ans += distance(l, r);
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
