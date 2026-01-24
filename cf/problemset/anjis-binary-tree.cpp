#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct node {
	int l, r, parent;
};

int mn = INT_MAX;

void dfs(vector<node> &adj, vector<unordered_set<int>> &directed, int u, int cnt) {
	int flag = 0;
	if (adj[u].l != -1) {
		flag = 1;
		int temp_cnt = cnt;
		if (directed[u].find(adj[u].l) == directed[u].end()) temp_cnt++;
		dfs(adj, directed, adj[u].l, temp_cnt);
	}
	if (adj[u].r != -1) {
		flag = 1;
		int temp_cnt = cnt;
		if (directed[u].find(adj[u].r) == directed[u].end()) temp_cnt++;
		dfs(adj, directed, adj[u].r, temp_cnt);
	}
	if (!flag) {
		mn = min(mn, cnt);
	}
}

void solve() {
	mn = INT_MAX;
	int n; cin >> n;
	string s; cin >> s;
	vector<node> adj(n, {-1, -1, -1});
	int l, r;
	for (int i = 0; i < n; i++) {
		cin >> l >> r; l--; r--;
		adj[i].l = l;
		adj[i].r = r;
		if (l != -1) adj[l].parent = i;
		if (r != -1) adj[r].parent = i;
	}
	vector<unordered_set<int>> directed(n, unordered_set<int>());
	for (int i = 0; i < n; i++) {
		switch (s[i]) {
			case 'L':
				if (adj[i].l != -1) {
					directed[i].insert(adj[i].l);
				}
				break;
			case 'R':
				if (adj[i].r != -1) {
					directed[i].insert(adj[i].r);
				}
				break;
			case 'U':
				if (adj[i].parent != -1) {
					directed[i].insert(adj[i].parent);
				}
				break;
		}
	}

	dfs(adj, directed, 0, 0);	

	cout << ((mn == INT_MAX) ? 0 : mn) << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while (t--) solve();

	return 0;
}

