#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int max_points = 1000000;

void solve() {
	string s; cin >> s;
	int len = s.length();

	if (len < 3) {
		cout << -1 << endl; return;
	}

	ll ans = -1;
	for (int j = 1; j < min(len-1, 8); j++) {
		for (int k = j+1; k < min(len, j+8); k++) {

			ll n1 = 0, n2 = 0, n3 = 0;
			for (int i = 0; i < j; i++) n1 = n1*10 + (s[i]-'0');
			if (n1 > max_points || (n1 > 0 && s[0] == '0') || (n1 == 0 && j > 1)) continue;
			for (int i = j; i < k; i++) n2 = n2*10 + (s[i]-'0');
			if (n2 > max_points || (n2 > 0 && s[j] == '0') || (n2 == 0 && k-j > 1)) continue;
			for (int i = k; i < min(len, k+8); i++) n3 = n3*10 + (s[i]-'0');
			if (n3 > max_points || (n3 > 0 && s[k] == '0') || (n3 == 0 && min(len, k+8)-k > 1)) continue;

			ans = max(ans, (ll)(n1+n2+n3));
		}
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	while (t--) solve();

	return 0;
}

