#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n, x; cin >> n >> x;

	for (int i = 0; i < x; i++) cout << i << " ";
	for (int i = n-1; i >= x; i--) cout << i << " ";
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
