#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int check_pattern(string &s, int l) {
	if (s[l] == '1' && s[l+1] == '1' && s[l+2] == '0' && s[l+3] == '0') return 1;
	return 0;
}

void solve() {
	string s; cin >> s;
	int n = s.length();

	ll count = 0;
	for (int i = 0; i < n-3; i++) {
		count += check_pattern(s, i);
	}

	int q; cin >> q;
	int idx; char v;
	while (q--) {
		cin >> idx; cin >> v; idx--;
		int l = max(0, idx-3);
		int r = min(idx+3, n-1);
		
		int bef = 0;
		for (int i = l; i <= r; i++) bef += check_pattern(s, i);
		s[idx] = v;
		int aft = 0;
		for (int i = l; i <= r; i++) aft += check_pattern(s, i);

		count += (aft - bef);
		cout << ((count > 0) ? "YES" : "NO") << endl;
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
