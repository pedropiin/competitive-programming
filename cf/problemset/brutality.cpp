#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n, k; cin >> n >> k;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	string s; cin >> s;

	int i = 0;
	ll ans = 0;
	while (i < n) {
		int window_size = 1;
		int j = i+1;
		while (j < n && s[i] == s[j]) {
			window_size++;
			j++;
		}

		if (window_size <= k) {
			ll sm = 0;
			for (int idx = i; idx < i+window_size; idx++) sm += (ll)v[idx];
			ans += sm;
		} else {
			priority_queue<ll> pq_window;
			for (int idx = i; idx < j; idx++) pq_window.push((ll)v[idx]);
			for (int _ = 0; _ < k; _++) {
				ans += (ll)pq_window.top();
				pq_window.pop();
			}
		}
		i = j;
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

