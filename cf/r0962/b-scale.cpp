#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n, k; cin >> n >> k;
	vector<string> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	for (int i = 0; i < n; i += k) {
		for (int j = 0; j < n; j += k) cout << v[i][j]; 
		cout << endl;
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while (t--) solve();

	return 0;
}

