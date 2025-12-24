#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n, k; cin >> n >> k;
	int first_live = n-k+1;
	int odds;
	if (first_live % 2 == 0) odds = k/2;
	else odds = k/2 + k%2;

	if (odds%2 == 0) cout << "YES" << endl;
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

