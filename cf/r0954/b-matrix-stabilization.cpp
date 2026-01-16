#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n, m; cin >> n >> m;
	vector<vector<int>> mtx(n, vector<int>(m));
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) cin >> mtx[i][j];

	while (1) {
		int found = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (i > 0 && mtx[i-1][j] >= mtx[i][j]) continue;
				if (i < n-1 && mtx[i+1][j] >= mtx[i][j]) continue;
				if (j > 0 && mtx[i][j-1] >= mtx[i][j]) continue;
				if (j < m-1 && mtx[i][j+1] >= mtx[i][j]) continue;

				int a = -1, b = -1, c = -1, d = -1;
				if (i > 0) a = mtx[i-1][j];
				if (i < n-1) b = mtx[i+1][j];
				if (j > 0) c = mtx[i][j-1];
				if (j < m-1) d = mtx[i][j+1];
				mtx[i][j] = max(max(max(a, b), c), d);
				found = 1;
			}
		}
		if (!found) break;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cout << mtx[i][j] << " ";
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

