#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n; cin >> n;
	int t;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> t;
		if (i % 2 == 0) ans += t;
		else ans -= t;
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

