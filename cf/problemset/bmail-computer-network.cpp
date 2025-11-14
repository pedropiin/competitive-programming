#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define INF 1e9

void bfs(vector<vector<int>> &adj, vector<int> &visited, vector<int> &pred) {
	queue<int> q;
	q.push(0);
	while (!q.empty()) {
		int v = q.front(); q.pop();
		for (int neighbor : adj[v]) {
			if (visited[neighbor] == 0) {
				q.push(neighbor);
				pred[neighbor] = v;
			}
		}
		visited[v] = 1;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<vector<int>> adj(n, vector<int>());
	int temp;
	for (int i = 0; i < n-1; i++) {
		cin >> temp;
		adj[i+1].push_back(temp-1);
		adj[temp-1].push_back(i+1);
	} 
	vector<int> visited(n, 0); vector<int> pred(n, -1);
	bfs(adj, visited, pred);	

	vector<int> ans;
	int parent = n-1;
	while (parent != 0) {
		ans.push_back(parent);
		parent = pred[parent];
	}

	cout << 1 << " ";
	for (int i = ans.size()-1; i >= 0; i--)	cout << ans[i] + 1 << " ";
	cout << endl;

	return 0;
}
