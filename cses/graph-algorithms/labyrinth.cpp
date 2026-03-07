#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

char get_dir(pair<int, int> &prev, pair<int, int> &curr) {
	if (prev.first == curr.first) {
		if (prev.second < curr.second) return 'R';
		else return 'L';
	} else {
		if (prev.first < curr.first) return 'D';
		else return 'U';
	}
}

void solve() {
	int n, m; cin >> n >> m;
	vector<string> adj(n);
	pair<int, int> start, end;
	for (int i = 0; i < n; i++) {
		cin >> adj[i];
		for (int j = 0; j < m; j++) {
			if (adj[i][j] == 'A') start = {i, j};
			else if (adj[i][j] == 'B') end = {i, j};
		}
	}

	vector<vector<int>> visited(n, vector<int>(m, 0));
	visited[start.first][start.second] = 1;
	vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>> (m, {-1, -1}));
	queue<pair<int, int>> q;
	q.push(start);
	const vector<pair<int, int>> monkey = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
	while (!q.empty()) {
		pair<int, int> u = q.front();
		q.pop();
		for (auto p : monkey) {
			pair<int, int> v = {u.first + p.first, u.second + p.second};
			if (v.first < 0 || v.first >= n || v.second < 0 || v.second >= m) continue;
			if (!visited[v.first][v.second]) {
				visited[v.first][v.second] = 1;
				parent[v.first][v.second] = u;
				if (adj[v.first][v.second] == '#') continue;
				q.push({v.first, v.second});
			}
		}
	}

	if (visited[end.first][end.second]) {
		vector<char> path;
		pair<int, int> curr = end;
		while (curr.first != start.first || curr.second != start.second) {
			pair<int, int> prev = parent[curr.first][curr.second];
			path.push_back(get_dir(prev, curr));
			curr = prev;
		}

		cout << "YES" << endl;
		cout << path.size() << endl;
		for (int i = path.size()-1; i >= 0; i--) cout << path[i];
		cout << endl;
	} else {
		cout << "NO" << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	while (t--) solve();

	return 0;
}

