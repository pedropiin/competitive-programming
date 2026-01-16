#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int x1, x2, x3; cin >> x1 >> x2 >> x3;
	int minn = INT_MAX;
	int l = min(min(x1, x2), x3), r = max(max(x1, x2), x3);
	for (int a = l; a <= r; a++) {
		int t = abs(a-x1) + abs(a-x2) + abs(a-x3);
		minn = min(minn, t);
	}

	cout << minn << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while (t--) solve();

	return 0;
}

