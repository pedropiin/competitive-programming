#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/*
 * vector<int> min(n)
 * vector<int> temp_maxes(n);
 * vector<int> temp_itself(n);
 * vector<int> idxs;
 * sort(idxs.begin(), idxs.end(), []() {
 * 		return temp_maxes[a] < temp_maxes[b]	
 * })
 *
 * vector<int> maxes(n);
 * vector<int> itself(n);
 * for (int i = 0; i < n; i++) {
 * 		maxes[i] = temp_maxes[idxs[i]];
 * 		itself[i] = temp_itself[idxs[i]];
 * }
 *
 * vector<int> pref_sum(n+1); pref_sum[0] = 0;
 * for (int i = 0; i < n; i++) pref_sum[i+1] = pref_sum[i] + itself[i];
 *
 * for (int i = 0; i < n; i++) {
 * 		upper_bound_idx = bin_search(maxes, min[i]);
 * 		ans += distance(upper_bound_idx)
 * 		ans += pref_sum[upper_bound_idx+1]
 * }
 */

int bin_search_upper(vector<int> &v, int n, int x) {
	int l = 0, r = n-1;
	while (l <= r) {
		int m = l + (r-l)/2;
		if (v[m] == x) l = m+1;
		else if (v[m] < x) {
			if ((m == n-1) || (m < n-1 && v[m+1] > x)) return m+1;
			else {
				l = m+1;
			}
		} else if (v[m] > x) {
			if ((m == 0) || (m > 0 && v[m-1] <= x)) return m;
			else {
				r = m-1;
			}
		}
	}
	return l;
}

void solve() {
	int n; cin >> n;
	vector<vector<int>> seqs(n);
	vector<int> mins(n), temp_maxes(n), temp_itself(n), idxs(n);
	int l;
	for (int i = 0; i < n; i++) {
		cin >> l;
		seqs[i] = vector<int>(l);
		int mn = INT_MAX, mx = 0, ascent_on_itself = 0;
		for (int j = 0; j < l; j++) {
			cin >> seqs[i][j];
			mn = min(mn, seqs[i][j]);
			mx = max(mx, seqs[i][j]);
			if (seqs[i][j] > mn) ascent_on_itself = 1;
		}
		mins[i] = mn;
		temp_maxes[i] = mx;
		temp_itself[i] = ascent_on_itself;
		idxs[i] = i;
	}

	sort(idxs.begin(), idxs.end(), [&](const int &a, const int &b) {
				return temp_maxes[a] < temp_maxes[b];
			});
	vector<int> maxes(n), itself(n);
	for (int i = 0; i < n; i++) {
		maxes[i] = temp_maxes[idxs[i]];
		itself[i] = temp_itself[idxs[i]];
	}

	vector<int> pref_sum(n+1, 0);
	for (int i = 0; i < n; i++) pref_sum[i+1] = pref_sum[i] + itself[i];

	ll ans = 0;
	for (int i = 0; i < n; i++) {
		if (temp_itself[i]) {
			ans += n;
			continue;
		}
		auto it = upper_bound(maxes.begin(), maxes.end(), mins[i]);
		int idx = distance(maxes.begin(), it);
		ans += (ll)n-idx;
		ans += (ll)pref_sum[idx];
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

