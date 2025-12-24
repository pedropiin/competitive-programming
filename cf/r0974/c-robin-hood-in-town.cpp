#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

void solve() {
	int n; cin >> n;
	vector<int> v(n);
	priority_queue<int, vector<int>, greater<int>> min_heap;
	ll s = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		min_heap.push(v[i]);
		s += v[i];
	}

	if (n <= 2) {
		cout << -1 << endl;
		return;
	}

	int unh_sz = (n/2) + 1;
	ll g;
	while (unh_sz--) {
		g = min_heap.top();
		min_heap.pop();
	}

	ll ans = (ll)((ll)g*(ll)2*(ll)n)-s+1;
	cout << ((ans > 0) ? ans : 0) << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while (t--) solve();

	return 0;
}

