#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int x; cin >> x;

	int ans = 10;
	int div = 10;
	while (x > 0) {
		ans = min(ans, x % div);
		x = x / div;
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
