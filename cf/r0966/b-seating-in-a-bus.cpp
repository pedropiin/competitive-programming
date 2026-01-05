#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n; cin >> n;
	vector<int> order(n); vector<int> bus(n, 0);
	int t, empty = 1;
	int ok = 1;
	for (int i = 0; i < n; i++) {
		cin >> t; t--;
		bus[t] = 1;
		if (empty) empty = 0;
		else {
			if (t == 0) {
				if (!bus[t+1]) ok = 0;	
			} else if (t == n-1) {
				if (!bus[t-1]) ok = 0;
			} else {
				if (bus[t-1] == 0 && bus[t+1] == 0) ok = 0;
			}
		}
	}

	if (ok) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while (t--) solve();

	return 0;
}
