#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n; cin >> n;

	if (n % 4 == 0) cout << 0 << endl;
	else if (n % 6 == 0) cout << 0 << endl;
	else if (n % 2 == 0) {
		int k = n/2;
		int t = (k-1)/2;
		if (t >= 1) cout << 0 << endl;
		else cout << 2 << endl;
	} else {
		int k = n/2;
		if (k < 2) cout << 3 << endl;
		else cout << 1 << endl;
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

