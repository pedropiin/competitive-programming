#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int x, n; cin >> x >> n;
	if (n % 2 == 0) cout << 0 << endl;
	else cout << x << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while (t--) solve();

	return 0;
}

