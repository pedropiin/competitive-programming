#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int bin_search(int x, vector<int> &v, int n) {
	int l = 0, r = n-1;
	while (l < r) {
		int m = l + (r-l)/2;
		if (v[m] <= x) l = m+1;
		else r = m;
	}
	if (v[l] <= x) return n;
	return l;
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];

	sort(a.begin(), a.end());
	for (int elem : b) {
		int idx = bin_search(elem, a, n);
		if (a[idx] == elem) cout << n << " ";
		else cout << idx << " ";
	}
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	while (t--) solve();

	return 0;
}

