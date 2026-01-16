#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n; cin >> n;
	string s; cin >> s;

	if (n == 2) {
		cout << ((s[0]-'0')*10 + (s[1]-'0')) << endl; return;
	}

	ll ans = LONG_LONG_MAX;
	for (int i = 0; i < n-1; i++) {
		int zero_flag = 0;
		int one_flag = 1;
		ll temp = 0;
		for (int j = 0; j < i; j++) {
			if (s[j] == '0') {
				zero_flag = 1; break;
			}
			if (s[j] != '1') temp += (s[j]-'0');
		}
		for (int j = i+2; j < n; j++) {
			if (s[j] == '0') {
				zero_flag = 1; break;
			}
			if (s[j] != '1') temp += (s[j]-'0');
		}

		if (zero_flag) {
			ans = 0; break;
		}
		int duo = (s[i]-'0')*10 + (s[i+1]-'0');
		if (temp == 0) {
			ans = min(ans, (ll)duo);
			continue;
		} 
		if (duo > 1) temp += duo;
		ans = min(ans, temp);
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

