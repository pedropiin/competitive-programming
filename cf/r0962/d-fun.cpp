#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	ll n, x; cin >> n >> x;

	ll ans = 0;
	ll t1, t2;
	for (ll a = 1; a <= n && a <= x; a++) {
		for (ll b = 1; (ll)(a*b) <= n && (ll)(a + b) <= x; b++) {
			t1 = x - a - b;
			t2 = (ll)(n-(ll)a*b)/(ll)(a+b);
			ans += max((ll)0, min(t1, t2));
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

