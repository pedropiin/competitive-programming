#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n; cin >> n;
	string s; cin >> s;

	int hifen = 0, under = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '-') hifen++;
		else under++;
	}

	ll ans = 0;
	for (int i = 1; i < hifen; i++) {
		ans = max(ans, (ll)(i * (ll)under * (ll)(hifen-i)));
	}
	cout << ans << endl;
	//int rhs = (hifen/2) + (hifen % 2);
	//int ans = (hifen/2) * under * rhs;
	//cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while (t--) solve();

	return 0;
}
