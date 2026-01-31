#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int bin_search(vector<int> &v, int x, int n) {
	int l = 0, r = n-1;
	int ans = n;
	while (l < r) {
		int m = l + (r-l)/2;
		if (v[m] <= x) l = m+1;
		else r = m;
	}
	if (v[l] <= x) return n;
	return l;
}

void solve() {
	int n; cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	int q; cin >> q;
	int t;
	while (q--) {
		cin >> t;
		cout << bin_search(v, t, n) << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	while (t--) solve();

	return 0;
}

