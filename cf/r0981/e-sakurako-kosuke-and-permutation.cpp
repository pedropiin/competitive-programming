#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n; cin >> n;
	vector<int> v(n);
	int t;
	for (int i = 0; i < n; i++) {
		cin >> t; t--;
		v[i] = t;
	}

	vector<int> visited(n, 0);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (visited[i]) continue;
		int cicle_sz = 1;
		t = v[i];
		visited[i] = 1;
		while (!visited[t] && t != i) {
			cicle_sz++;
			visited[t] = 1;
			t = v[t];
		}
		ans += (cicle_sz-1) / 2;
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while (t--) solve();

	return 0;
}

