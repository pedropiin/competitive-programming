#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7;

void solve() {
	ll n, m; cin >> n >> m;
	vector<ll> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];

	vector<vector<ll>> dp(n, vector<ll>(m, 0));
	if (v[0] == 0) {
		for (int j = 0; j < m; j++) dp[0][j] = 1;
	} else dp[0][v[0]-1] = 1;

	ll t = 0;
	for (ll i = 1; i < n; i++) {
		if (v[i] != 0) {
			ll fixed = v[i];
			t = 0;
			for (ll k = max((ll)0, fixed-2); k <= min(m-1, fixed); k++) {
				t += (dp[i-1][k] % mod) % mod;
			}
			dp[i][fixed-1] = t % mod;
			continue;
		}
		for (ll j = 0; j < m; j++) {
			t = 0;
			for (ll k = max((ll)0, j-1); k <= min(m-1, j+1); k++) {
				t += (dp[i-1][k] % mod) % mod;
			}
			dp[i][j] = t % mod;
		}
	}

	ll ans = 0;
	for (int j = 0; j < m; j++) ans += (dp[n-1][j] % mod) % mod;
	cout << ans % mod << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	solve();

	return 0;
}

