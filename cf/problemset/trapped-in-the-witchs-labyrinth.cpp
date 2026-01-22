#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n, m; cin >> n >> m;
	int sz = n*m+1;
	vector<string> lab(n);
	for (int i = 0; i < n; i++) cin >> lab[i];

	vector<vector<int>> adj(sz, vector<int>());
	string s;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int dirx, diry;
			int no_dir = 0;
			switch (lab[i][j]) {
				case 'U':
					dirx = i-1;
					diry = j;
					break;
				case 'D':
					dirx = i+1;
					diry = j;
					break;
				case 'L':
					dirx = i;
					diry = j-1;
					break;
				case 'R':
					dirx = i;
					diry = j+1;
					break;
				case '?':
					no_dir = 1;
					break;
			}

			if (no_dir) continue;
			int idx = i*m + j + 1;
			if (dirx < 0 || dirx >= n || diry < 0 || diry >= m) {
				adj[0].push_back(idx);
				adj[idx].push_back(0);
			} else {
				int dir_idx = dirx*m + diry + 1;
				adj[idx].push_back(dir_idx);
				if (lab[dirx][diry] != '?') {
					adj[dir_idx].push_back(idx);
				}
			}
		}
	}

	vector<int> visited(sz, 0);
	vector<int> leaves(sz, 0);
	queue<int> q;
	q.push(0);
	visited[0] = 1;
	leaves[0] = 1;
	while (!q.empty()) {
		int curr = q.front(); 
		q.pop();
		for (int v : adj[curr]) {
			if (!visited[v]) {
				visited[v] = 1;
				leaves[v] = 1;
				q.push(v);
			}
		}
	}

	int ans = 0;
	const vector<pair<int, int>> monkey_vec = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
	for (int i = 1; i < sz; i++) {
		if (visited[i]) continue;

		visited[i] = 1;	
		if (adj[i].size() == 0) {
			int stuck = 0;
			int curry = (i-1)%m;
			int currx = (i-1-curry)/m;
			int dirx, diry;	
			for (pair<int, int> poss : monkey_vec) {
				dirx = currx + poss.first;
				diry = curry + poss.second;
				if (dirx >= 0 && dirx < n && diry >= 0 && diry < m) {
					if (!leaves[dirx*m + diry + 1]) {
						stuck = 1;
						break;
					}
				}
			}
			if (stuck) ans++;
		} else {
			ans++;
		}
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

