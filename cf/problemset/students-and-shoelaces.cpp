#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n, m; cin >> n >> m;
	vector<set<int>> v(n, set<int>());

	int a, b;	
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a-1].insert(b-1);
		v[b-1].insert(a-1);
	}
	
	int done = 0;
	int ans = 0;
	while (!done) {
		vector<int> removable;
		for (int i = 0; i < n; i++) {
			if (v[i].size() == 1) {
				removable.push_back(i);
			}
		}
		if (removable.size() == 0) break;
		for (int i = 0; i < removable.size(); i++) {
			int r = removable[i];
			int neighbor = *v[r].begin();
			v[r].clear();
			v[neighbor].erase(r);
		}
		ans++;
	}

	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
