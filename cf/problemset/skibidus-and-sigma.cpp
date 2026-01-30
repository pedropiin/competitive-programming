#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n, m; cin >> n >> m;
	vector<vector<ll>> arrs(n, vector<ll>(m));
	vector<pair<ll, ll>> sums(n);
	for (int i = 0; i < n; i++) {
		ll sm = 0;
		for (int j = 0; j < m; j++) {
			cin >> arrs[i][j];
			sm += (ll)arrs[i][j];			
		}
		sums[i] = {sm, i}; 
	}

	sort(sums.begin(), sums.end(), [](const pair<ll, ll> &a, const pair<ll, ll> &b) {
				return a.first > b.first;
			});

	ll ans = 0;
	ll sz = n*m;
	for (int i = 0; i < n; i++) {
		ll curr_vec_idx = sums[i].second;
		for (int j = 0; j < m; j++) {
			ans += (ll)arrs[curr_vec_idx][j]*(ll)(sz-(i*m+j));
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

