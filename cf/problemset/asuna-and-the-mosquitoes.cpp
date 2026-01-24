#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int cnt = 1;

void solve() {
	int n; cin >> n;
	vector<ll> odds, evens;
	int mx = 0, t;
	ll s = 0;
	for (int i = 0; i < n; i++) {
		cin >> t;
		if (t % 2 == 0) evens.push_back(t);
		else odds.push_back(t);
		mx = max(mx, t);
		s += (ll)t;
	}

	if (odds.size() == 0 || evens.size() == 0) {
		cout << mx << endl;
		return;
	}

	cout << s - (ll)odds.size() + 1 << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while (t--) {
		solve();
		cnt++;
	}

	return 0;
}

