#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n; cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];

	int limit = 0;
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		if (!limit) {
			int diff = v[i] - (i+1);
			if (diff >= 0) {
				ans += i+1;
				continue;
			} else {
				ans += v[i];
				limit = v[i]+1;
			}
		} else {
			if (v[i] >= limit) ans += limit-1;
			else {
				ans += v[i];
				limit = v[i]+1;
			}
		}
		if (limit) limit++;
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

