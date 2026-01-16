#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<vector<int>> chooses(31, vector<int>(31, 0));

void solve() {
	int n, k; cin >> n >> k;
	int d = 0;
	while (n != 1) {
		n = n >> 1;
		d++;
	}
	int comb;
	ll ans = 0;
	for (int dtemp = d; dtemp > 0; dtemp--) {
		for (int zcnt = 0; zcnt < dtemp; zcnt++) {
			if (dtemp + (dtemp-1)-zcnt <= k) break;
			comb = chooses[dtemp-1][zcnt];
			if (comb <= 0) break;
			ans += comb;
		}
	}
	if (d+1 > k) ans++;
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 30; j++) {
			if (i < j) chooses[i][j] = 0;
			else if (j == 0) chooses[i][j] = 1;
			else chooses[i][j] = chooses[i-1][j] + chooses[i-1][j-1];
		}
	}

	int t; cin >> t;
	while (t--) solve();

	return 0;
}

