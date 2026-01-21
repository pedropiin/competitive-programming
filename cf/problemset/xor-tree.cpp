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
	vector<int> init(n), goal(n);
	for (int i = 0; i < n; i++) cin >> init[i];
	for (int i = 0; i < n; i++) cin >> goal[i];

	vector<int> visited(n, 0);
	queue<vector<int>> q;
	q.push({0, 0, 0, 0});
	visited[0] = 1;
	vector<int> ans;
	while (!q.empty()) {
		int curr = q.front()[0], layer = q.front()[1];
		int change_even = q.front()[2], change_odd = q.front()[3];
		q.pop();

		if (layer % 2 == 0) {
			if (init[curr] != goal[curr]) {
				if (!change_even) {
					change_even = 1;
					ans.push_back(curr);
				}
			} else {
				if (change_even) {
					change_even = 0;
					ans.push_back(curr);
				}
			}
		} else {
			if (init[curr] != goal[curr]) {
				if (!change_odd) {
					change_odd = 1;
					ans.push_back(curr);
				}
			} else {
				if (change_odd) {
					change_odd = 0;
					ans.push_back(curr);
				}
			}
		}
		
		for (int v : adj[curr]) {
			if (!visited[v]) {
				visited[v] = 1;
				q.push({v, layer+1, change_even, change_odd});
			}
		}
	}

	cout << ans.size() << endl;
	for (int a : ans) cout << a+1 << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	while (t--) solve();

	return 0;
}

