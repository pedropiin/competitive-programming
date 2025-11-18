#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n; cin >> n;

	for (int i = 1; i <= n; i += 2) cout << i << " ";
	int t = (n % 2 == 0) ? n : n-1;
	for (int i = t; i > 0; i -= 2) cout << i << " ";
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}
