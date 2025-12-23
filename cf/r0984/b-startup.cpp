#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n, k; cin >> n >> k;
	map<int, ll> m;
	int b, c;
	for (int i = 0; i < k; i++) {
		cin >> b >> c;
		m[b] += c;
	}

	priority_queue<ll> pq;
	for (auto it : m) {
		pq.push(it.second);
	}

	ll ans = 0;
	while (n-- && pq.size() > 0) {
		ans += pq.top();
		pq.pop();
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
