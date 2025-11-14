#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> matrix(n, vector<int>(m));
	int maxv = 0, cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> matrix[i][j];
			if (matrix[i][j] > maxv) {
				maxv = matrix[i][j];
				cnt = 1;
			} else if (matrix[i][j] == maxv) 
				cnt++;
		}
	}

	vector<int> row_cnt(n, 0); vector<int> col_cnt(m, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (matrix[i][j] == maxv) {
				row_cnt[i]++;
				col_cnt[j]++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int intersect = (matrix[i][j] == maxv) ? 1 : 0;
			if (row_cnt[i] + col_cnt[j] - intersect == cnt) {
				cout << maxv - 1 << endl;
				return;
			}
		}
	}
	cout << maxv << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while (t--) solve();

	return 0;
}
