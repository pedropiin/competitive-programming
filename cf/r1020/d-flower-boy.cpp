#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int cnt = 1;

void solve() {
	int n, m; cin >> n >> m;
	vector<int> a(n); vector<int> b(m);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];

	if (n == 1) {
		if (a[0] >= b[0]) cout << 0 << endl;
		else cout << b[0] << endl;
		return;
	} 

	vector<int> prefix(m, -1); vector<int> suffix(m, -1);
	int j = 0;
	for (int i = 0; i < n; i++) {
		if ((j < m) && a[i] >= b[j]) {
			prefix[j] = i;
			j++;
		}
	}
	if (j == m) {
		cout << 0 << endl; return;
	}

	j = m-1;
	for (int i = n-1; i >= 0; i--) {
		if ((j >= 0) && a[i] >= b[j]) {
			suffix[j] = i;
			j--;
		}
	}

	const int inf = 2e9;
	int ans = inf;

	for (int i = 0; i < m; i++) {
		if (m == 1) {
			if ((suffix[0] == -1) && (prefix[0] == -1)) ans = b[0];
			else ans = 0;
			break;
		}
		if (i == 0) {
			if (suffix[i+1] >= 0) ans = min(ans, b[i]);	
			continue;
		} else if (i == m-1) {
			if (prefix[i-1] >= 0) ans = min(ans, b[i]);
			continue;
		} else {
			if ((prefix[i-1] != -1) && (suffix[i+1] != -1) && (prefix[i-1] < suffix[i+1])) ans = min(ans, b[i]);
			continue;
		}
	}
	if (ans == inf) cout << -1 << endl;
	else cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while (t--) {
		solve();
		cnt++;
	}

	return 0;
}
