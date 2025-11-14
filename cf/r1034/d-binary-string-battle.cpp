#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n, k; cin >> n >> k;
	string s; cin >> s;

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '1') cnt++;
	}
	if (cnt <= k) {
		cout << "Alice" << endl;
		return;
	}
	if (n >= (2 * k)) {
		cout << "Bob" << endl;
		return;
	}
	cout << "Alice" << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while (t--) solve();

	return 0;
}
