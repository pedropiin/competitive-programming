#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n, k; cin >> n >> k;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];

	ll max_sum = a[0], curr_sum = a[0];
	int l = 0, r = 0, max_l = 0, max_r = 0;
	for (int i = 1; i < n; i++) {
		if (a[i] > curr_sum + a[i]) {
			l = i;
			curr_sum = (ll)a[i];
		} else curr_sum += (ll)a[i];
		if (curr_sum > max_sum) {
			max_sum = curr_sum;
			max_l = l;
			max_r = i;
		}	
	}

	if (k % 2 == 0) {
		cout << max_sum << endl;
		return;
	}

	vector<ll> forward(n);
	forward[0] = (ll)a[0];
	curr_sum = (ll)a[0];
	for (int i = 1; i < n; i++) {
		curr_sum = max((ll)a[i], (ll)curr_sum + (ll)a[i]);
		forward[i] = (ll)curr_sum;
	}
	vector<ll> backward(n);
	backward[n-1] = a[n-1];
	curr_sum = a[n-1];
	for (int i = n-2; i >= 0; i--) {
		curr_sum = max((ll)a[i], (ll)curr_sum + (ll)a[i]);
		backward[i] = (ll)curr_sum;
	}

	ll ans = a[0];
	for (int i = 0; i < n; i++) {
		curr_sum = (ll)forward[i] + (ll)backward[i] - (ll)a[i] + (ll)b[i];
		ans = max(ans, curr_sum);
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

