#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int a, b, c, d; cin >> a >> b >> c >> d;

	if (a == b && b == c && c == d && d == a) cout << "YES" << endl;
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
