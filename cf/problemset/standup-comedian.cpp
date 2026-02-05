#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int a1, a2, a3, a4; cin >> a1 >> a2 >> a3 >> a4;

	if (a1 == 0) {
		cout << 1 << endl;
		return;
	}

	int ans = a1, alice = a1, bob = a1, mn;
	mn = min(a2, a3);
	ans += 2*mn;
	a2 -= mn; a3 -= mn;
	if (a2 >= a3) {
		mn = min(a2, bob);
		ans += mn; a2 -= mn;
		alice += mn; bob -= mn; 
		if (a2 > 0) {
			ans += 1;
		} else {
			if (a4 > 0) {
				ans += min(bob, a4);
				a4 -= min(bob, a4);
				ans += (a4 > 0);
			}
		}
	} else {
		mn = min(a3, alice);
		ans += mn; a3 -= mn;
		alice -= mn; bob += mn; 
		if (a3 > 0) {
			ans += 1;
		} else {
			if (a4 > 0) {
				ans += min(alice, a4);
				a4 -= min(alice, a4);
				ans += (a4 > 0);
			}
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

