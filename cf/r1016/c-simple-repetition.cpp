#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int x, k; cin >> x >> k;

	if (x != 2 && x % 2 == 0) {
		cout << "NO" << endl; return;
	}

	if (k > 1) {
		if (k == 2 && x == 1) {
			cout << "YES" << endl; return;
		} else {
			cout << "NO" << endl; return;
		}
	}
	if (k == 1) {
		if (x == 1) {
			cout << "NO" << endl; return;
		}
		int prime = 1; int sqr = ceil(sqrt(x));
		for (int i = 3; i <= sqr; i++) {
			if (x % i == 0) {
				prime = 0;
				break;
			}
		}
		if (prime) {
			cout << "YES" << endl; return;
		} else { 
			cout << "NO" << endl; return;
		}
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
