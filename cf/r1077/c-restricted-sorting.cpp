#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n; cin >> n;
	vector<int> v(n);
	int mn = INT_MAX, mx = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		mn = min(mn, v[i]);
		mx = max(mx, v[i]);
	}

	vector<int>vsorted(v);
	sort(v.begin(), v.end());
	unordered_map<int, unordered_set<int>> sort_idxs;
	for (int i = 0; i < n; i++) {
		sort_idxs[vsorted[i]].insert(i);
	}

	set<int> diffs;
	int sorted = 1;
	for (int i = 0; i < n; i++) {
		int elem = v[i];
		if (sort_idxs[elem].find(i) == sort_idxs[elem].end()) {
			sorted = 0;
			diffs.insert(max(abs(elem-mn), abs(elem-mx)));
		}
	}
	if (sorted) cout << -1 << endl;
	else cout << (*(diffs.begin())) << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while (t--) solve();

	return 0;
}

