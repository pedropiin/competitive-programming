#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void bfs(vector<vector<int>> &adj,  vector<int> &dist) {
	queue<int>q;
	q.push(0);
	dist[0] = 0;
	while (!q.empty()) {
		int v = q.front(); q.pop();
		for (int neighbor : adj[v]) {
			if (dist[neighbor] == -1) {
				q.push(neighbor);
				dist[neighbor] = dist[v]+1;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m, k; cin >> n >> m >> k;
	vector<int> prod_type(n);
	for (int i = 0; i < n; i++) {
		int prod; cin >> prod;
		prod_type[i] = prod-1;
	}
	vector<vector<int>> adj(n, vector<int>());
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		adj[u-1].push_back(v-1); adj[v-1].push_back(u-1);
	}

	vector<int> dist(n, -1);
	bfs(adj, dist);

	vector<int> ans(k, -1);
	for (int i = 0; i < n; i++) {
		ans[prod_type[i]] = max(ans[prod_type[i]], dist[i]);
	}
	
	for (int i = 0; i < k; i++) cout << ans[i] << " ";
	cout << endl;

	return 0;
}
