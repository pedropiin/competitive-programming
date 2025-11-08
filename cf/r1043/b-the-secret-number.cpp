#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	ll n; cin >> n;

	vector<ll> ans;
	ll t = 10;
	while (true) {
		ll div = t + 1;
		if (n % div == 0) ans.push_back(n / div);
		if (div > n) break;
		t *= 10;
	}

	if (ans.size() == 0) {
		cout << 0 << endl;
		return;
	}
	cout << ans.size() << endl;
	for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i] << " ";
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}

	cin.tie(0);
}
