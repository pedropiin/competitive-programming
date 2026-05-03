#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1000000007;

void calc_subtree_cost(vector<ll> &subtree_cost, vector<int> &visited, int u, vector<pair<int, int>> &child, vector<int> &parent) {
	int left = child[u].first, right = child[u].second;
	if (left == -1) {
		// leaf
		subtree_cost[u] = 0;
	} else {
		if (!visited[left]) {
			visited[left] = 1;
			calc_subtree_cost(subtree_cost, visited, left, child, parent);
		}
		if (!visited[right]) {
			visited[right] = 1;
			calc_subtree_cost(subtree_cost, visited, right, child, parent);
		}
		subtree_cost[u] = (((subtree_cost[left] + subtree_cost[right]) % mod ) + 4 ) % mod;
	}
}

void solve() {
	int n; cin >> n;

	vector<int> parent(n, -1);
	vector<pair<int, int>> child(n, {-1, -1});

	int u, v;
	for (int i = 0; i < n; i++) {
		cin >> u >> v;
		if (u == 0) continue;
	
		u--; v--;
		child[i] = {u, v};
		parent[u] = i;
		parent[v] = i;
	}

	vector<ll> subtree_cost(n, 0);
	vector<int> visited(n, 0);
	visited[0] = 1;
	calc_subtree_cost(subtree_cost, visited, 0, child, parent);

	vector<ll> idiot_cost(n, 0);
	idiot_cost[0] = (subtree_cost[0] + 1) % mod;
	visited[0] = 1;
	if (child[0].first == -1) {
		cout << idiot_cost[0] << endl;
		return;
	}
	queue<int> q; q.push(child[0].first); q.push(child[0].second);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		idiot_cost[u] = (((subtree_cost[u] + idiot_cost[parent[u]]) % mod) + 1) % mod;
		if (child[u].first != -1) {
			q.push(child[u].first);
			q.push(child[u].second);
		}
	}

	for (int i = 0; i < n; i++) {
		cout << idiot_cost[i] << " ";
	}
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while (t--) solve();

	return 0;
}

