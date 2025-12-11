#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	string s; cin >> s;
	int n = s.length();
	int idx;
	for (int i = n-1; i >= 0; i--) {
		if (s[i] != '0') {
			idx = i; break;
		}
	}
	int non_zero = 0;
	for (int i = 0; i < idx; i++) {
		if (s[i] != '0') non_zero++;
	}
	
	cout << n - (idx+1) + non_zero << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while (t--) solve();

	return 0;
}
