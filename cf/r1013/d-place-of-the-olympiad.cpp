#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n, m, k;
	cin >> n >> m >> k;

	int fullest = ceil((double)k/n);
	int ws = m - fullest;
	int ans = ceil((double)fullest/(ws + 1));
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
