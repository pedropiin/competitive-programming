#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void dfs(vector<vector<int>> &adj, vector<int> &ans, vector<int> &visited, set<int> &q, int u, int n) {
	for (int v : adj[u]) {
		if (!visited[v]) {
			visited[v] = 1;
			q.insert(v);
		}
	}
	if (!q.empty()) {
		set<int>::iterator next_it = q.begin();
		int next = *next_it;
		ans.push_back(next+1);
		q.erase(next_it);
		dfs(adj, ans, visited, q, next, n);
	}
}

void solve() {
	int n, m; cin >> n >> m;
	vector<vector<int>> adj(n, vector<int>());
	int u, v;
	for (int i = 0; i < m; i++) {
		cin >> u >> v; u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> ans;
	ans.push_back(1);
	vector<int> visited(n, 0);
	visited[0] = 1;
	set<int> q;
	dfs(adj, ans, visited, q, 0, n);

	for (int elem : ans) cout << elem << " ";
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

