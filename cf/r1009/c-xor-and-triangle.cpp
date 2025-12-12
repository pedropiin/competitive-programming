#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int x; cin >> x;

	int shift = 1; int looking_for_zero = 1; int lz = __builtin_clz(x);
	int y = 0;
	int poss = 0;
	for (int i = 0; i < (31 - lz); i++) {
		if (looking_for_zero) {
			if (!(x & shift)) {
				y += 1 << i;
				looking_for_zero = 0;
			}
		} else {
			if (x & shift) {
				y += 1 << i;
				poss = 1;
				break;
			}
		}
		shift = shift << 1;
	}

	if (!poss) {
		int looking_for_one = 1, shift = 1;
		y = 0;
		for (int i = 0; i < (31 - lz); i++) {
			if (looking_for_one) {
				if (shift & x) {
					y += 1 << i;
					looking_for_one = 0;
				} 
			} else {
				if (!(x & shift)) {
					y += 1 << i;
					poss = 1;
					break;
				}
			}
			shift = shift << 1;
		}
	}

	if (poss) cout << y << endl;
	else cout << -1 << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while (t--) solve();

	return 0;
}
