#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n, m; cin >> n >> m;
	vector<vector<int>> adj(n, vector<int>());
	int u, v;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> parent(n, -1); 
	vector<int> visited(n, 0); visited[0] = 1;
	queue<int> q; q.push(0);
	while (!q.empty()) {
		u = q.front();
		q.pop();
		for (int v : adj[u]) {
			if (!visited[v]) {
				visited[v] = 1;
				q.push(v);
				parent[v] = u;
			}
		}
	}
	if (!visited[n-1]) {
		cout << "IMPOSSIBLE" << endl;
		return;
	} 
	vector<int> path; path.push_back(n);
	int p = parent[n-1];
	while (p != 0) {
		path.push_back(p+1);
		p = parent[p];
	}
	path.push_back(1);
	cout << path.size() << endl;
	for (int i = path.size()-1; i >= 0; i--) {
		cout << path[i] << " ";
	}
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	while (t--) solve();

	return 0;
}

