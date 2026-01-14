#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int s, k, m; cin >> s >> k >> m;

	if ((m%k) > s) {
		cout << 0 << endl;
		return;
	}
	if (m < k) {
		cout << max(0, s-m) << endl;
		return;
	}

	if (k > s) {
		cout << max(0, s - (m%k)) << endl;
	} else {
		if ((m/k)%2 == 0) cout << max(0, s-(m%k)) << endl;
		else cout << max(0, k - (m%k)) << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while (t--) solve();

	return 0;
}

