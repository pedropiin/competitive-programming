#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1000000007;

void solve() {
	string s; cin >> s;
	int n = s.length();

	vector<int> pref_sum_str(n+1);
	pref_sum_str[0] = 0;
	for (int i = 0; i < n; i++) {
		pref_sum_str[i+1] = pref_sum_str[i] + (s[i] == '1' ? 1 : -1);
	}

	unordered_map<int, int> idx_map;
	idx_map[pref_sum_str[0]] = 0;
	int diff_sums_cnt = 1;

	vector<vector<int>> sums_freq;
	sums_freq.push_back(vector<int>());
	sums_freq[0].push_back(0);
	int t;
	for (int i = 1; i <= n; i++) {
		t = pref_sum_str[i];
		if (idx_map[t] == 0 && t != pref_sum_str[0]) {
			idx_map[t] = diff_sums_cnt;
			sums_freq.push_back(vector<int>());
			sums_freq[diff_sums_cnt].push_back(i);
			diff_sums_cnt++;
		} else {
			sums_freq[idx_map[t]].push_back(i);
		}
	}

	vector<vector<ll>> pref_sum_idxs(diff_sums_cnt);
	ll ans = 0;
	for (int i = 0; i < diff_sums_cnt; i++) {
		int sz = sums_freq[i].size();
		pref_sum_idxs[i] = vector<ll>(sz + 1);
		pref_sum_idxs[i][0] = (ll)0;
		for (int j = 0; j < sz; j++) {
			pref_sum_idxs[i][j+1] = (ll)pref_sum_idxs[i][j] + (ll)sums_freq[i][j];
		}

		for (int j = 0; j < sz; j++) {
			ll a = (sums_freq[i][j] + 1) % mod;
			ll b = ((ll)((ll)sz - j - 1)*((ll)n+1)) % mod;
			ll c = ((ll)(pref_sum_idxs[i][sz]) - (ll)(pref_sum_idxs[i][j+1])) % mod;
			ans += (ll)(a * (ll)(b-c)) % mod;
			ans = ans % mod;
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

