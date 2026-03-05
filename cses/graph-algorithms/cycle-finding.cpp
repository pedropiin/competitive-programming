#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll inf = LLONG_MAX;

void solve() {
	int n, m; cin >> n >> m;
	vector<vector<int>> edges(m, vector<int>(3));
	for (int i = 0; i < m; i++) {
		cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
		edges[i][0]--; edges[i][1]--;
	}

	vector<ll> dist(n, 0); 
	vector<int> parent(n, -1);
	int flag;
	for (int i = 0; i < n; i++) {
		flag = -1;
		for (int j = 0; j < m; j++) {
			int u = edges[j][0], v = edges[j][1];
			ll x = (ll)edges[j][2];
			if (dist[v] > dist[u] + x) {
				dist[v] = max((ll)(-inf+1), dist[u]+x);
				parent[v] = u;
				flag = v;
			}
		}
	}

	if (flag == -1) cout << "NO" << endl;
	else {
		cout << "YES" << endl;

		int start = flag;
		for (int i = 0; i < n; i++) start = parent[start];

		vector<int> cycle;
		cycle.push_back(start+1);
		int next = parent[start];
		while (next != start) {
			cycle.push_back(next+1);
			next = parent[next];
		}
		cycle.push_back(start+1);

		for (int i = cycle.size()-1; i >= 0; i--) cout << cycle[i] << " ";
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

