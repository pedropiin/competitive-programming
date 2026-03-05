#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void dfs(vector<vector<int>> &adj, vector<int> &visited, queue<int> &solo, queue<pair<int, int>> &pairs, int x, queue<int> &seq) {
	seq.push(x);
	for (int v : adj[x]) {
		if (!visited[v]) {
			visited[v] = 1;
			dfs(adj, visited, solo, pairs, v, seq);
		}
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

	vector<int> visited(n, 0);
	queue<int> solo, seq;
	queue<pair<int, int>> pairs;

	vector<vector<int>> ans;
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			visited[i] = 1;
			dfs(adj, visited, solo, pairs, i, seq);
		}
		if (seq.size() > 3) {
			cout << -1 << endl;
			return;
		} 
		if (seq.size() == 3) {
			ans.push_back({});
			while (!seq.empty()) {
				ans[ans.size()-1].push_back(seq.front());
				seq.pop();
			}
		} else if (seq.size() == 2) {
			pairs.push(make_pair(seq.front(), seq.back()));
			seq.pop(); seq.pop();
		} else if (seq.size() == 1) {
			solo.push(seq.front());
			seq.pop();
		}
	}

	if (pairs.size() > 0) {
		if (solo.size() < pairs.size()) {
			cout << -1 << endl;
			return;
		}

		while (!pairs.empty()) {
			ans.push_back({});
			ans[ans.size()-1].push_back(pairs.front().first);
			ans[ans.size()-1].push_back(pairs.front().second);
			pairs.pop();
			ans[ans.size()-1].push_back(solo.front());
			solo.pop();
		}
	}
	if (solo.size() % 3 != 0) {
		cout << -1 << endl;
		return;
	}
	while (!solo.empty()) {
		ans.push_back({});
		for (int _ = 0; _ < 3; _++) {
			ans[ans.size()-1].push_back(solo.front());
			solo.pop();
		}
	}

	for (vector<int> vec : ans) {
		for (int elem : vec) cout << elem+1 << " ";
		cout << endl;
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

