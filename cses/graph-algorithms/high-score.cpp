#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll inf = LLONG_MAX;

void solve() {
	int n, m; cin >> n >> m;
	vector<vector<int>> adj(n, vector<int>());
	vector<vector<int>> edges(m, vector<int>(3));
	int u, v, x;
	for (int i = 0; i < m; i++) {
		cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
		edges[i][0]--; edges[i][1]--; 
		edges[i][2] = -edges[i][2];
		adj[edges[i][0]].push_back(edges[i][1]);
	}

	vector<ll> dist(n, inf); dist[0] = 0;
	vector<int> parent(n, -1);
	unordered_set<int> in_cycle;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int u = edges[j][0], v = edges[j][1];
			ll x = (ll)edges[j][2];
			if (dist[u] < inf) {
				if (dist[v] > dist[u] + x) {
					dist[v] = max((ll)(-inf+5), dist[u] + x);
					parent[v] = u;
					if (i == n-1) in_cycle.insert(v);
				}
			}
		}	
	}	

	if (!in_cycle.empty()) {
		vector<int> visited(n, 0);
		while (!in_cycle.empty()) {
			int cycle_start = *(in_cycle.begin());
			in_cycle.erase(cycle_start);
			for (int i = 0; i < n; i++) cycle_start = parent[cycle_start];

			if (visited[cycle_start]) continue;

			visited[cycle_start] = 1;
			queue<int> q;
			q.push(cycle_start);
			while (!q.empty()) {
				int u = q.front();
				q.pop();
				for (int v : adj[u]) {
					if (!visited[v]) {
						visited[v] = 1;
						q.push(v);
					}
				}
			}
			if (visited[n-1]) {
				cout << -1 << endl;
				return;
			}
		}
		cout << -dist[n-1] << endl;
	} else {
		cout << -dist[n-1] << endl;
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

