#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n; cin >> n;
	string s; cin >> s;

	int ans = INT_MAX;
	if (n % 2 == 0) {
		vector<vector<int>> freq(2, vector<int>(26, 0));

		for (int i = 0; i < n; i++) freq[i%2][s[i]-'a']++;
	
		int max_even = 0, max_odd = 0;
		for (int i = 0; i < 26; i++) {
			max_even = max(max_even, freq[0][i]);
			max_odd = max(max_odd, freq[1][i]);
		}

		int even_ops = n/2 - max_even;
		int odd_ops = n/2 - max_odd;
		ans = min(ans, even_ops + odd_ops);
	} else {
		vector<vector<int>> pref(2, vector<int>(26, 0));
		vector<vector<int>> suff(2, vector<int>(26, 0));

		for (int i = 0; i < n; i++) suff[i%2][s[i]-'a']++;

		for (int i = 0; i < n; i++) {
			suff[i%2][s[i]-'a']--;
			int max_even = 0, max_odd = 0;
			for (int j = 0; j < 26; j++) {
				max_even = max(max_even, pref[0][j] + suff[1][j]);
				max_odd = max(max_odd, pref[1][j] + suff[0][j]);
			}
			int even_ops = (n-1)/2 - max_even;
			int odd_ops = (n-1)/2 - max_odd;
			ans = min(ans, 1 + even_ops + odd_ops);
			pref[i%2][s[i]-'a']++;
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

