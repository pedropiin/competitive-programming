#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n, m, k; cin >> n >> m >> k;
	string river; cin >> river;
	river = "B" + river; n++;

	int log = 0;
	int water = 0, next_water = 0;
	int pos = 0;
	while (pos < n) {
		log = 0; water = 0; next_water = 0;

		if (pos + m >= n) {
			cout << "YES" << endl; 
			return;
		}

		for (int i = m; i > 0; i--) {
			if (river[pos+i] == 'L') {
				log = 1; pos = pos+i; break;
			}
			if (river[pos+i] == 'W') {
				water = 1; next_water = max(next_water, pos+i);
			}
		}

		if (log) continue;
		if (water) {
			k--; pos = next_water + 1;
			while (pos < n && river[pos] == 'W' && k >= 0) {
				pos++;
				k--;
			}

			if (k < 0 || river[pos] == 'C') {
				cout << "NO" << endl; return;
			}
			if (pos >= n) {
				cout << "YES" << endl; return;
			} 
		}
		if (!water && !log) {
			cout << "NO" << endl; return;
		}
	}
	cout << "YES" << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while (t--) solve();

	return 0;
}

