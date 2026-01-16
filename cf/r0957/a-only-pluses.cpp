#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int a, b, c; cin >> a >> b >> c;
	int ans = 0;
	for (int i = 0; i <= 5; i++) {
		for (int j = 0; i+j <= 5; j++) {
			for (int k = 0; i+j+k <= 5; k++) {
				ans = max(ans, (a+i) * (b+j) * (c+k));
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

