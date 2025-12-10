#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n; cin >> n;
	vector<int> a(n); vector<int> b(n);
	int a_odd = 0; int b_odd = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] == 1) a_odd ^= 1;
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		if (b[i] == 1) b_odd ^= 1;
	} 

	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			// ajisai's turn
			if (!a_odd) {
				if ((a[i] == 1 && b[i] == 0) || (a[i] == 0 && b[i] == 1)) {
					a_odd ^= 1;
					b_odd ^= 1;
				}
			}
		} else {
			// mai's turn
			if (!b_odd) {
				if ((a[i] == 1 && b[i] == 0) || (a[i] == 0 && b[i] == 1)) {
					a_odd ^= 1;
					b_odd ^= 1;
				}
			}
		}
	}

	if (a_odd) {
		if (b_odd) cout << "Tie" << endl;
		else cout << "Ajisai" << endl;
	} else {
		if (b_odd) cout << "Mai" << endl;
		else cout << "Tie" << endl;
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
