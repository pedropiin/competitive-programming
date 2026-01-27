#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int cnt = 1;

void solve() {
	int n, k; cin >> n >> k;
	vector<int> a(n), h(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> h[i];

	vector<int> divs(n, 1);
	for (int i = n-2; i >= 0; i--) {
		if (h[i+1] <= h[i] && h[i] % h[i+1] == 0) divs[i] = 1;
		else divs[i] = 0;
	}

	int l = 0, r = 0, mx_sz = 0;
	ll curr_sum = 0;
	while (l < n && r < n) {
		if (divs[r] == 1 || (r > 0 && divs[r-1] == 1)) {
			if (r > 0 && divs[r-1] == 0) {
				l = r;
				curr_sum = 0;
			}
			curr_sum += (ll)a[r];
			if (curr_sum <= k) {
				mx_sz = max(mx_sz, r-l+1);
				r++;
			} else {
				curr_sum -= (ll)a[l];
				l++;
				r++;
			}
		} else {
			if (a[r] <= k) mx_sz = max(mx_sz, 1);
			r++;
		}
	}
	cout << mx_sz << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while (t--) {
		solve();
		cnt++;
	}

	return 0;
}

