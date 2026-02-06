#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n; cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];

	ll ans = 0;
	for (int i = 0; i < n; i++) {
		int b = ((2*i+2)/v[i]) + 1;
		int idx = v[i]*b - i - 2;
		while (idx < n) {
			if (v[idx] == b) ans++;
			idx += v[i];
			b++;
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

