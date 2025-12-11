#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


void solve() {
	int n; cin >> n;
	
	if (n % 2 == 0) {
		cout << -1 << endl;
		return;
	}

	for (int i = 1; i <= n; i += 2) cout << i << " ";
	for (int i = 2; i < n; i += 2) cout << i << " ";
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while (t--) solve();

	return 0;
}
