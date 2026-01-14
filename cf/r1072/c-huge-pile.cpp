#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n, k; cin >> n >> k;

	int ans = 0;
	int l = n, r = n;
	while (r > 1) {
		if (k >= l && k <= r) break;
		l = l/2; r = r/2 + r%2;
		ans++;
	}

	if (k >= l && k <= r) cout << ans << endl;
	else cout << -1 << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while (t--) solve();

	return 0;
}

