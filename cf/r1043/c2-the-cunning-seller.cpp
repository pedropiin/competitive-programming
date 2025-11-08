#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> powers = {1};
vector<ll> calc = {3};

void solve() {
	int n; cin >> n;
	int k; cin >> k;
	
	ll ans = 0; 
	ll sum_pow = 0;
	vector<int> deals(20, 0); // deals[i] contains number of deals done with powers[i]
	for (int i = 19; i >= 0; i--) {
		if ((ll)powers[i] + sum_pow > n) continue;
		while ((ll)powers[i] + sum_pow <= n) {
			sum_pow += powers[i];
			ans += calc[i];
			k--;
			deals[i]++;
			if (sum_pow == n) break;
		}	
		if (sum_pow == n) break;
	}
	if (k < 0) {
		cout << -1 << endl;
		return;
	}

	int largest_deal_idx = 0;
	for (int i = 19; i >= 0; i--) {
		if (deals[i] > 0) {
			largest_deal_idx = i;
			break;
		}
	}	

	if (largest_deal_idx == 0) {
		cout << ans << endl;
		return;
	}
	while (k > 0 && largest_deal_idx >= 1) {
		int ops_largest = deals[largest_deal_idx];
		if (ops_largest * 2 <= k) {
			deals[largest_deal_idx - 1] += ops_largest * 3;
			deals[largest_deal_idx] = 0;
			ans -= powers[largest_deal_idx - 1] * ops_largest;
			k -= ops_largest * 2;
			largest_deal_idx--;
		} else {
			int possible_opt = k / 2;
			deals[largest_deal_idx - 1] += possible_opt * 3;
			deals[largest_deal_idx] -= possible_opt;
			ans -= powers[largest_deal_idx - 1] * possible_opt;
			largest_deal_idx--;
			k = 0;
		}
	}

	if (sum_pow == n) cout << ans << endl;
	else cout << -1 << endl;
}

int main() {
	ios::sync_with_stdio(false);

	for (int i = 1; i <= 21; i++) {
		powers.push_back((ll)powers[i-1] * 3);
	}
	for (int i = 1; i <= 20; i++) {
		calc.push_back(powers[i+1] + i * powers[i-1]);
	}

	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
