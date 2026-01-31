#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int check(ll n) {
	ll temp = n;
	while (temp > 0) {
		if (temp % 10 == 7) return 1;
		temp = temp/10;
	}
	return 0;
}

void solve() {
	ll n; cin >> n;

	ll temp = n;
	int num_digits = 0;
	while (temp > 0) {
		if (temp % 10 == 7) {
			cout << 0 << endl; return;
		}
		temp = temp/10;
		num_digits++;
	}

	int ans = 9;
	for (int i = 1; i <= num_digits; i++) {
		ll temp = n;
		ll sum_factor = 0;
		for (int j = 0; j < i; j++) {
			sum_factor = (ll)(sum_factor * (ll)10) + 9;
		}
		for (int j = 1; j <= 9; j++) {
			temp += sum_factor;
			if (check(temp)) {
				ans = min(ans, j);
				break;
			}
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

