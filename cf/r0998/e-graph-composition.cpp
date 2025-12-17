#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n, m1, m2; cin >> n >> m1 >> m2;

	int u, v;
	vector<unordered_set<int>> f(n, unordered_set<int>());
	for (int i = 0; i < m1; i++) {
		cin >> u >> v; u--; v--;
		f[u].insert(v);
		f[v].insert(u);
	}
	vector<unordered_set<int>> g(n, unordered_set<int>());
	for (int i = 0; i < m2; i++) {
		cin >> u >> v; u--; v--;
		g[u].insert(v);
		g[v].insert(u);
	}

	ll ans = 0;
	unordered_set<int>::iterator it;
	for (int i = 0; i < n; i++) {
		vector<int> removal;
		for (it = f[i].begin(); it != f[i].end(); it++) {
			if (g[i].find(*it) == g[i].end()) {
				removal.push_back(*it);
				ans++;
			}
		}
		for (int r : removal) {
			f[i].erase(r);
			f[r].erase(i);
		}
	}

	for (int i = 0; i < n; i++) {
		vector<int> insertions;
		for (it = g[i].begin(); it != g[i].end(); it++) {
			if (f[i].find(*it) == f[i].end()) {
				insertions.push_back(*it);
				ans++;
			}
		}
		for (int in : insertions) {
			f[i].insert(in);
			f[in].insert(i);
		}
	}

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
