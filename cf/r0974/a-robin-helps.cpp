#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n, k; cin >> n >> k;
	int t;
	int ans = 0; int gold = 0;
	for (int i = 0; i < n; i++) {
		cin >> t;
		if (t >= k) gold += t;
		else if (gold > 0 && t == 0) {
			ans++;
			gold--;
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

