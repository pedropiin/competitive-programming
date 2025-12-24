#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n; cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	
	int mx = 0, mx_idx = -1;
	if (abs(v[0] - v[1]) > mx) {
		mx = abs(v[0] - v[1]);
		mx_idx = 0;
	}
	for (int i = 0; i < n-2; i++) {
		int t1 = abs(v[i] - v[i+1]) + abs(v[i+1] - v[i+2]);
		int t2 = abs(v[i] - v[i+2]);
		if (abs(t1 - t2) > mx) {
			mx = abs(t1-t2);
			mx_idx = i+1;
		}
	}
	if (abs(v[n-2] - v[n-1]) > mx) {
		mx = abs(v[n-2] - v[n-1]);
		mx_idx = n-1;
	}

	ll ans = 0;
	for (int i = 0; i < n-1; i++) {
		if (i == 0 && mx_idx == 0) {
			continue;
		}
		if (i+1 == mx_idx) {
			if (mx_idx < n-1) {
				ans += abs(v[i] - v[i+2]);
				i++;
			}
		} else {
			ans += abs(v[i] - v[i+1]);
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

