#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n, k; cin >> n >> k;
	string s; cin >> s;
	int m = n/2;

	int good_cnt[] = {0, 0};
	for (int i = 0; i < m; i++) {
		if (s[i] == s[n-i-1]) good_cnt[s[i]-'0']++;
	}
	
	int total = good_cnt[0] + good_cnt[1];
	if (k == total) {
		cout << "YES" << endl;
		return;
	} else if (k < total) {
		int t_par = total%2;
		int k_par = k%2;
		if (t_par != k_par)  {
			cout << "NO" << endl;
			return;
		}
		int diff = abs(good_cnt[0] - good_cnt[1]);
		if (diff > k) cout << "NO" << endl;
		else cout << "YES" << endl;
		return;
	} else {
		int t_par = total%2;
		int k_par = k%2;
		if (t_par != k_par) {
			cout << "NO" << endl;
			return;
		}
		int inc = (n - (total * 2)) / 2;
		if ((total + inc) >= k) cout << "YES" << endl;
		else cout << "NO" << endl;
		return;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}
