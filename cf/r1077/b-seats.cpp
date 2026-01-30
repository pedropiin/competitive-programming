#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n; cin >> n;
	string s; cin >> s;

	vector<int> ones; ones.push_back(-1);
	for (int i = 0; i < n; i++) {
		if (s[i] == '1') ones.push_back(i);
	}
	ones.push_back(n);

	if (ones.size() == 2) {
		cout << (n/3) + ((n%3 != 0) ? 1 : 0) << endl;
		return;
	} else {
		int ans = 0;
		int sz = ones.size();
		ans += ones[1]/3 + ((ones[1] % 3 == 2) ? 1 : 0);
		for (int i = 1; i < sz-2; i++) {
			ans += (ones[i+1]-ones[i]-1)/3;
		}
		ans += ((n-ones[sz-2]-1)/3) + (((n-ones[sz-2]-1) % 3 == 2) ? 1 : 0);
		cout << ans + (sz-2) << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while (t--) solve();

	return 0;
}

