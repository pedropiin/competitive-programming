#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n, k; cin >> n >> k;
	unordered_map<int, int> freq;
	int t;
	int found = 0;
	for (int i = 0; i < n; i++) {
		cin >> t;
		freq[t]++;
		if (freq[t] >= k) found = 1;
	}
	if (found) {
		cout << 0 << endl; 
		return;
	}

	unordered_map<int, priority_queue<int>> umap;
	unordered_map<int, int>::iterator it;
	for (it = freq.begin(); it != freq.end(); it++) {
		int div = it->first, cnt = 0, curr_freq = it->second;
		for (int i = 0; i < curr_freq; i++) {
			if (umap[div].size() < k) {
				umap[div].push(cnt);
			} else {
				if (cnt < umap[div].top()) {
					umap[div].pop();
					umap[div].push(cnt);
				} else {
					break;
				}
			}
		}
		while (div > 0) {
			div = div >> 1; cnt++;
			for (int i = 0; i < curr_freq; i++) {
				if (umap[div].size() < k) {
					umap[div].push(cnt);
				} else {
					if (cnt < umap[div].top()) {
						umap[div].pop();
						umap[div].push(cnt);
					} else {
						break;
					}
				}
			}
		}
	}

	ll ans = LONG_LONG_MAX;
	unordered_map<int, priority_queue<int>>::iterator it2;
	for (it2 = umap.begin(); it2 != umap.end(); it2++) {
		if (it2->second.size() >= k) {
			ll sm = 0;
			while (it2->second.size() > 0) {
				sm += (ll)it2->second.top();
				it2->second.pop();
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

