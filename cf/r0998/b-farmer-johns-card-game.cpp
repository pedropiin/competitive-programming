#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n, m; cin >> n >> m;
	vector<vector<int>> v(n, vector<int>(m));

	int t;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) 
			cin >> v[i][j];
		sort(v[i].begin(), v[i].end());
	}

	vector<int> order;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (v[j][0] == i) order.push_back(j);
		}
	}

	if (order.size() != n) {
		cout << -1 << endl;
		return;
	}

	for (int i = 0; i < n; i++) {
		int turn = order[i];
		for (int j = 0; j < m; j++) {
			if (v[turn][j] != j*n + i) {
				cout << -1 << endl;
				return;
			}
		}
	}

	for (int turn : order) cout << turn+1 << " ";
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
