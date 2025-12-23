#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n; cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	for (int i = 0; i < n-1; i++) {
		if (abs(v[i]-v[i+1]) != 5 && abs(v[i]-v[i+1]) != 7) {
			cout << "NO" << endl;
			return;
		}
	}

	cout << "YES" << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while (t--) solve();

	return 0;
}
