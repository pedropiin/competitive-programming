#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n; cin >> n;
	vector<vector<int>> v(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) 
			cin >> v[i][j];
	}

	ll ans = 0;
	// upper half
	for (int j = n-1; j >= 0; j--) {
		int mn = 0;
		for (int i = 0; i < n, i+j < n; i++) {
			if (v[i][j+i] < 0) mn = min(mn, v[i][j+i]);
		}
		ans += abs(mn);
	}
	//lower half
	for (int i = 1; i < n; i++) {
		int mn = 0;
		for (int j = 0; j < n, i+j < n; j++) {
			if (v[i+j][j] < 0) mn = min(mn, v[i+j][j]);
		}
		ans += abs(mn);
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

