#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> powers = {1};
vector<ll> calc = {3};

void solve() {
	int n; cin >> n;
	
	ll ans = 0; 
	ll sum_pow = 0;
	for (int i = 19; i >= 0; i--) {
		if ((ll)powers[i] + sum_pow > n) continue;
		while ((ll)powers[i] + sum_pow <= n) {
			sum_pow += powers[i];
			ans += calc[i];
			if (sum_pow == n) break;
		}
		if (sum_pow == n) break;
	}

	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);

	for (int i = 1; i <= 19; i++) {
		powers.push_back((ll)powers[i-1] * 3);
	}
	for (int i = 1; i < 19; i++) {
		calc.push_back(powers[i+1] + i * powers[i-1]);
	}

	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
