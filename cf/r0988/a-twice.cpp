#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n; cin >> n;

	unordered_set<int> s;
	int t;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> t;
		if (s.find(t) != s.end()) {
			ans++;
			s.erase(t);
		} else {
			s.insert(t);
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
