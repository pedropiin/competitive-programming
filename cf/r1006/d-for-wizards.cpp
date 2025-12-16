#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int bin_search(vector<int>& v, int x) {
	int l = 0, r = v.size()-1;
	while (l <= r) {
		int m = l + (r-l)/2;
		if (v[m] <= x) l = m+1;
		else r = m-1;
	}
	return l;
}

void solve() {
	int n; cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];

	vector<vector<int>> bigger(n, vector<int>());
	vector<vector<int>> inv(n, vector<int>());

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (v[i] > v[j]) inv[i].push_back(j);
			else if (v[i] < v[j]) bigger[i].push_back(j);
		}
	}

	int ans = 0, ans_idx_l = 0, ans_idx_r = 0;
	for (int i = 0; i < n; i++) {
		if (inv[i].size() <= 0) continue;

		int last_inv_idx = inv[i].back();
		int last_big_considered = bin_search(bigger[i], last_inv_idx);
		int total_balance = inv[i].size() - last_big_considered;
		if (total_balance > ans) {
			ans = total_balance;
			ans_idx_l = i;
			ans_idx_r = last_inv_idx;
		}

		for (int j = 0; j < bigger[i].size(); j++) {
			int first_inv_not_considered = bin_search(inv[i], bigger[i][j]);
			int balance = (first_inv_not_considered - j);
			if (balance > ans) {
				ans = balance;
				ans_idx_l = i;
				ans_idx_r = (first_inv_not_considered > 0) ? inv[i][first_inv_not_considered-1] : 0;
			}
		}
	}

	cout << ans_idx_l+1 << " " << ans_idx_r+1 << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while (t--) solve();

	return 0;
}
