#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	ll n;
	cin >> n;

	ll ans = n;
	while (n > 0) {
		ans += (n >> 1);
		n = n >> 1;
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
