#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1000000007;

ll binpow(ll v) {
	ll ans = 1;
	ll p = mod-2;
	while (p > 0) {
		if (p & 1) ans = (ans*v) % mod;
		v = (v*v) % mod;
		p = p >> 1;
	}
	return ans;
}

void solve() {
	int n; cin >> n;
	vector<ll> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];

	vector<ll> psum(n); psum[0] = v[0];
	for (int i = 1; i < n; i++) psum[i] = v[i] + psum[i-1];

	ll numerator = 0;
	for (int i = 0; i < n; i++) {
		ll t = (ll)((ll)(v[i] % mod) * (ll)((psum[n-1] - psum[i]) % mod)) % mod;
		numerator += t % mod; 
		numerator = numerator % mod;
	}

	ll d1 = (ll)n * (ll)(n-1); d1 = d1 % mod;
	ll d2 = binpow(2);
	ll d = binpow((d1 * d2) % mod);

	cout << ((ll)(numerator * d)) % mod << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while (t--) solve();

	return 0;
}

