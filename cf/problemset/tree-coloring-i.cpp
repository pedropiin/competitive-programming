#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n; cin >> n;
	vector<vector<int>> adj(n, vector<int>());
	int u, v;
	for (int i = 0; i < n-1; i++) {
		cin >> u >> v; u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> visited(n, 0); 
	queue<pair<int, int>> q; q.push({0, 0});
	unordered_map<int, int> m; m[0] = 1;
	int max_edges = 1, max_nodes = 1;
	int curr_node, curr_dist;
	while (!q.empty()) {
		curr_node = q.front().first;
		curr_dist = q.front().second;
		q.pop();
		visited[curr_node] = 1;
		int visit_cnt = 0;
		for (int v : adj[curr_node]) {
			if (!visited[v]) {
				q.push({v, curr_dist+1});
				m[curr_dist+1]++;
				visit_cnt++;
			}
		}	
		max_edges = max(max_edges, m[curr_dist+1]);
		max_nodes = max(max_nodes, visit_cnt + 1);
	}
	cout << max(max_edges, max_nodes) << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while (t--) solve();

	return 0;
}

