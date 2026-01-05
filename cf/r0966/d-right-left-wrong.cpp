#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n; cin >> n;
	vector<int> v(n);
	vector<ll> pref(n+1); pref[0] = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		pref[i+1] = pref[i] + v[i];
	} 
	string s; cin >> s;
	ll ans = 0;
	int l = 0, r = n-1;
	while (l < r) {
		if (s[l] != 'L' && s[r] != 'R') {
			l++; r--; continue;
		} 
		if (s[l] == 'L') {
			if (s[r] == 'R') {
				ans += (ll)pref[r+1] - (ll)pref[l];
				l++; r--; continue;
			} else {
				r--; continue;
			}
		} else {
			if (s[r] == 'R') {
				l++; 		
			} else {
				l++; r--; continue;
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
