#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n; cin >> n;
	vector<pair<int, int>> points(n);
	vector<vector<int>> mtx(1005, vector<int>(1005, 0));
	map<pair<int, int>, int> m;
	int x, y;
	for (int i = 0; i < n; i++) {
		cin >> x >> y; x--; y--;
		points[i] = {x, y};
		mtx[x][y] = 1;
		m[{x, y}] = i;
	}

	vector<vector<int>> adj(n, vector<int>());
	for (int i = 0; i < n; i++) {
		pair<int, int> p = points[i];
		for (int j = 0; j < 1005; j++) {
			if (mtx[j][p.second] == 1 && j != p.first) {
				adj[i].push_back(m[{j, p.second}]);
			}
		}
		for (int j = 0; j < 1005; j++) {
			if (mtx[p.first][j] == 1 && j != p.second)  {
				adj[i].push_back(m[{p.first, j}]);
			}
		}
	}

	vector<int> visited(n, 0);
	queue<int> q;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (visited[i]) continue;

		q.push(i);
		visited[i] = 1;
		while (!q.empty()) {
			int curr = q.front();
			q.pop();
			for (int v : adj[curr]) {
				if (!visited[v]) {
					visited[v] = 1;
					q.push(v);
				}
			}
		}
		ans++;
	}

	cout << ans-1 << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	while (t--) solve();

	return 0;
}

