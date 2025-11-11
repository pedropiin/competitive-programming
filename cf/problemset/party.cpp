#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
vector<int> color(2010, 0);

void dfs(int v, vector<int> &adj) {
	if (adj[v] == -1) color[v] = 1;
	else {
		int parent = adj[v]-1;
		if (color[parent] != 0) color[v] = color[parent] + 1;
		else {
			dfs(parent, adj);
			color[v] = color[parent] + 1;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	vector<int> adj(n);
	for (int i = 0; i < n; i++) cin >> adj[i];
	
	int ans = 1;
	for (int i = 0; i < n; i++) {
		if (color[i] == 0) dfs(i, adj);
		ans = max(ans, color[i]);
	}
	cout << ans << endl;

	return 0;
}
