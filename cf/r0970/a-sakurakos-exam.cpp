#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int a, b; cin >> a >> b;
	if (a == 0) {
		cout << ((b % 2 == 0) ? "YES" : "NO") << endl;
		return;
	} 
	if (b == 0) {
		cout << ((a % 2 == 0) ? "YES" : "NO") << endl;
		return;
	}

	if (a % 2 == 0) {
		if (b % 2 == 0) {
			cout << "YES" << endl;
			return;
		} else {
			if (a >= 2) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	} else {
		cout << "NO" << endl;
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

