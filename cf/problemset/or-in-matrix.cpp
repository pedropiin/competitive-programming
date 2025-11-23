#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m; cin >> n >> m;
	vector<vector<int>> b(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> b[i][j];
		}
	}

	vector<int> one_row(n, 0);
	for (int i = 0; i < n; i++) {
		int one_cnt = 0;
		for (int j = 0; j < m; j++) {
			if (b[i][j] == 1) one_cnt++;
		}
		one_row[i] = (one_cnt == m) ? 1 : 0;
	}
	vector<int> one_col(m, 0);
	for (int j = 0; j < m; j++) {
		int one_cnt = 0;
		for (int i = 0; i < n; i++) {
			if (j == 0) {
			}
			if (b[i][j] == 1) one_cnt++;
		}
		one_col[j] = (one_cnt == n) ? 1 : 0;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if ((b[i][j] == 1) && (one_row[i] == 0) && (one_col[j] == 0)) {
				cout << "NO" << endl;
				return 0;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (one_row[i] == 1) {
			int col_cnt = 0;
			for (int j = 0; j < m; j++) {
				if (one_col[j] == 1) col_cnt++;
			}
			if (col_cnt == 0) {
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	for (int j = 0; j < m; j++) {
		if (one_col[j] == 1) {
			int row_cnt = 0;
			for (int i = 0; i < n; i++) {
				if (one_row[i] == 1) row_cnt++;
			}
			if (row_cnt == 0) {
				cout << "NO" << endl;
				return 0;
			}
		}
	}

	cout << "YES" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if ((one_row[i] == 1) && (one_col[j] == 1)) cout << 1 << " ";
			else cout << 0 << " ";
		}
		cout << endl;
	}

	return 0;
}
