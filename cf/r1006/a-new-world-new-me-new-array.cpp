#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n, k, p; cin >> n >> k >> p;

	k = abs(k);
	int t = k / p;
	int m = k % p;
	if (m == 0) 
		cout << ((t > n) ? -1 : t) << endl;
	else 
		cout << (((t+1) > n) ? -1 : (t+1)) << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while (t--) solve();

	return 0;
}
