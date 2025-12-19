#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n, m; cin >> n >> m;
	vector<string> v;
	string s;
	int summ = 0;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> s;
		v.push_back(s);
		summ += s.length();
		if (summ > m) continue;
		ans++;
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
