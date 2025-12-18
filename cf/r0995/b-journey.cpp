#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n, a, b, c; cin >> n >> a >> b >> c;

	ll ans = (ll)(n/(a+b+c)) * 3;
	int mod = (n%(a+b+c));
	if (mod == 0) {
		cout << ans << endl;
		return;
	}

	if (a >= mod) cout << ans+1 << endl;
	else if (a+b >= mod) cout << ans+2 << endl;
	else cout << ans+3 << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while (t--) solve();

	return 0;
}
