#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int is_prime(int n) {
	if (n == 2) return 1;
	if (n == 1 || !(n&1)) return 0;

	int sqr = ceil((double)sqrt(n));
	for (int i = 3; i <= sqr; i += 2) {
		if (n%i == 0) return 0;
	}
	return 1;
}

void solve() {
	int n; ll e; cin >> n >> e;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];

	unordered_set<int> primes;
	unordered_map<int, int> visited_ones;
	unordered_map<int, int> visited_primes;
	for (int i = 0; i < n; i++) {
		if (is_prime(v[i])) primes.insert(v[i]);
		if (v[i] == 1) visited_ones[i] = 0;
	}

	ll ans = 0;
	for (int i = 0; i < n; i++) {
		if (primes.find(v[i]) == primes.end()) continue;
		
		ll idx = i + e;
		int cnt = 1;
		while (idx < n && v[idx] == 1) {
			cnt++;
			idx += e;
		}
		visited_primes[i] = cnt;
		ans += cnt-1;
	}
	for (int i = 0; i < n; i++) {
		if (v[i] != 1 || visited_ones[i]) continue;

		ll idx = i + e;
		int found_prime = 0;
		ll pre = 1, pos = 1;
		visited_ones[i] = 1;
		while (idx < n) {
			if (primes.find(v[idx]) != primes.end()) {
				found_prime = 1;
				pos = (ll)visited_primes[idx];
				break;
			} else if (v[idx] == 1) {
				visited_ones[idx] = 1;
				idx += e;
				pre++;
			} else {
				break;
			}
		}
		if (found_prime) ans += (ll)(pre*pos);
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

