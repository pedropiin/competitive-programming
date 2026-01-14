#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n, m; cin >> n >> m;
	vector<pair<int, int>> actors;
	vector<vector<int>> stage(n, vector<int>(m, 0));
	int t;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) {
			cin >> stage[i][j];
			if (stage[i][j] == 1) {
				actors.push_back({i, j});
			}
		}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		t = 0;
		for (int j = 0; j < m; j++) {
			if (t && !stage[i][j]) ans++;
			if (!t && stage[i][j]) t = 1;
		}
	}
	for (int i = 0; i < n; i++) {
		t = 0;
		for (int j = m-1; j>= 0; j--) {
			if (t && !stage[i][j]) ans++;
			if (!t && stage[i][j]) t = 1;
		}
	}
	for (int j = 0; j < m; j++) {
		t = 0;
		for (int i = 0; i < n; i++) {
			if (t && !stage[i][j]) ans++; 
			if (!t && stage[i][j]) t = 1;
		}
	}
	for (int j = 0; j < m; j++) {
		t = 0;
		for (int i = n-1; i >= 0; i--) {
			if (t && !stage[i][j]) ans++; 
			if (!t && stage[i][j]) t = 1;
		}
	}

	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t = 1;	
	while (t--) solve();

	return 0;
}

