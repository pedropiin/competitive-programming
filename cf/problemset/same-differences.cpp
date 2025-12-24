#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n; cin >> n;
	vector<int> v(n);
	unordered_map<int, int> m;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		m[v[i]-i]++;
	} 

	ll ans = 0;
	for (auto it : m) {
		if (it.second > 1) {
			ll chooses = (ll)((ll)it.second * (ll)(it.second-1))/2;
			ans += chooses;
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

