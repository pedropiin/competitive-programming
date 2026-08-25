#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n; cin >> n;
	vector<ll> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];

	sort(v.begin(), v.end());

	int l = 0, r = n-1;
	ll sum_l = v[l], sum_r = v[r];
	while (l+1 < r) {
		if (sum_l <= sum_r) {
			sum_l += v[++l];
		} else {
			sum_r += v[--r];
		}
	}

	if (sum_l >= sum_r || ((n-1) - r) > 0) cout << sum_l + sum_r << endl;
	else cout << 2*sum_r << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	solve();

	return 0;
}

