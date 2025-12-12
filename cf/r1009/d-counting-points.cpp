#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n, m; cin >> n >> m;
	vector<int> centers(n), radius(n);
	for (int i = 0; i < n; i++) cin >> centers[i];
	for (int i = 0; i < n; i++) cin >> radius[i];

	map<int, ll> longest_y_span;

	for (int i = 0; i < n; i++) {
		int xi = centers[i]; int ri = radius[i];
		int left_limit = xi-ri, right_limit = xi+ri;

		for (int j = left_limit; j <= right_limit; j++) {
			int offset = j - xi;
			ll half = (ll)floor(sqrt((ll)((ll)ri * ri) - ((ll)offset * offset)));
			longest_y_span[j] = max(longest_y_span[j], (ll)(2*half + 1));
		}
	}

	ll ans = 0;
	map<int, ll>::iterator it;
	for (it = longest_y_span.begin(); it != longest_y_span.end(); it++) {
		ans += it->second;
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
