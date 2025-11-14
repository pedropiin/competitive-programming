#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n, s;
	cin >> n >> s;
	int low = 105, high = 0;
	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		high = max(high, temp);
		low = min(low, temp);
	}

	if (s >= high) cout << abs(s - low) << endl;
	else if (s <= low) cout << abs(high - s) << endl;
	else cout << min(abs(s - low) + abs(high - low), abs(high - s) + abs(high - low)) << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while (t--) solve();

	return 0;
}
