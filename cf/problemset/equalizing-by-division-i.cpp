#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n, k; cin >> n >> k;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	unordered_map<int, vector<int>> umap;
	for (int i = 0; i < n; i++) {
		int div = v[i];
		umap[div].push_back(0);
		int cnt = 0;
		while (div > 0) {
			div = div >> 1;
			cnt++;
			umap[div].push_back(cnt);
		}
	}

	unordered_map<int, vector<int>>::iterator it;
	int ans = INT_MAX;
	for (it = umap.begin(); it != umap.end(); it++) {
		if (it->second.size() >= k) {
			sort(it->second.begin(), it->second.end());
			int sm = 0;
			for (int i = 0; i < k; i++) {
				sm += it->second[i];
			}
			ans = min(ans, sm);
		}
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	while (t--) solve();

	return 0;
}

