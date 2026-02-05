#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n, k; cin >> n >> k;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];

	if (k == 1) {
		cout << v[n-1] - v[0] << endl;
		return;
	}

	vector<pair<int, int>> diffs;
	for (int i = 0; i < n-1; i++) diffs.push_back({v[i+1]-v[i], i});
	sort(diffs.begin(), diffs.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
					return a.first < b.first;
				});

	vector<int> idxs;
	int i = 0;
	while (i++ < k-1) {
		idxs.push_back(diffs.back().second);
		diffs.pop_back();
	}
	sort(idxs.begin(), idxs.end());

	ll ans = 0;
	int l = v[0], r = v[0], p = 0;
	for (int i = 0; i < n; i++) {
		r = v[i];
		if (i == idxs[p]) {
			ans += (ll)(r-l);
			if (i+1 >= n || p+1 >= k-1) break;

			l = v[i+1];
			r = v[i+1];
			p++;
		} else {
			r = v[i];
		}
	}
	if (idxs.back() < n-1) {
		ans += (ll)(v[n-1] - v[idxs.back()+1]);
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

