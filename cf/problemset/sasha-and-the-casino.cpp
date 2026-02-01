#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int k, x, a; cin >> k >> x >> a;

	ll curr = 1;
	ll sm = 0;
	for (int i = 0; i <= x; i++) {
		sm += curr;
		if (a - sm < 0) {
			cout << "NO" << endl;
			return;
		}
		curr = sm/(k-1) + 1;
	}
	cout << "YES" << endl;
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while (t--) solve();

	return 0;
}

