#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n, x;
	cin >> n >> x;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	
	int first_closed = 0, last_closed = 0;
	for (int i = 0; i < n; i++) {
		if (v[i] == 1) {
			first_closed = i;
			break;
		}
	}
	for (int i = n-1; i >= 0; i--) {
		if (v[i] == 1) {
			last_closed = i;
			break;
		}
	}

	if ((last_closed - first_closed) < x) cout << "YES" << endl;
	else cout << "NO" << endl;
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
