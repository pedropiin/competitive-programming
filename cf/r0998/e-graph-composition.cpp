#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void dfs(vector<vector<int>> &adj, vector<int> &visited, vector<int> &component, int node, int component_cnt) {
	visited[node] = 1;
	component[node] = component_cnt;
	for (int neighbor : adj[node]) {
		if (!visited[neighbor]) 
			dfs(adj, visited, component, neighbor, component_cnt);
	}
}

void solve() {
	int n, m1, m2; cin >> n >> m1 >> m2;
	vector<vector<int>> f(n, vector<int>());
	vector<vector<int>> g(n, vector<int>());
	int u, v;
	for (int i = 0; i < m1; i++) {
		cin >> u >> v; u--; v--;
		f[u].push_back(v);
		f[v].push_back(u);
	}
	for (int i = 0; i < m2; i++) {
		cin >> u >> v; u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	vector<int> visited(n, 0);

	vector<int> g_component(n,  0);
	int g_component_cnt = 0;
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			g_component_cnt++;
			dfs(g, visited, g_component, i, g_component_cnt);
		}
	}
	fill(visited.begin(), visited.end(), 0);



	int ans = 0;
	vector<int> valid_edges;
	for (int i = 0; i < n; i++) {
		valid_edges.clear();
		for (int v : f[i]) {
			if (g_component[i] != g_component[v]) ans++;
			else valid_edges.push_back(v);
		}
		f[i].clear();
		for (int v : valid_edges) f[i].push_back(v);
	}
	ans /= 2;

	vector<int> f_component(n, 0);
	int f_component_cnt = 0;
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			f_component_cnt++;
			dfs(f, visited, f_component, i, f_component_cnt);
		}
	}

	ans += abs(f_component_cnt - g_component_cnt);
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
