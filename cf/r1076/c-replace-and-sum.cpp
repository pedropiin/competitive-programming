#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n, q; cin >> n >> q;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];

	int mx = max(a[n-1], b[n-1]);
	a[n-1] = mx;
	for (int i = n-2; i >= 0; i--) {
		mx = max(mx, max(a[i], b[i]));
		a[i] = mx;
	}
	
	vector<ll> prefix(n+1, 0);
	for (int i = 0; i < n; i++) {
		prefix[i+1] = (ll)prefix[i] + (ll)a[i];
	}

	int l, r;
	for (int i = 0; i < q; i++) {
		cin >> l >> r; l--;
		cout << (ll)prefix[r] - (ll)prefix[l] << " "; 	
	}
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while (t--) solve();

	return 0;
}

