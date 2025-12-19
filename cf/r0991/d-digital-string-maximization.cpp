#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	string s; cin >> s;
	int n = s.length();

	int break_idx = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] != '9') {
			break_idx = i;
			break;
		}
	}
	if (break_idx == n-1) {
		cout << s << endl;
		return;
	}

	while (break_idx < n-1) {
		int mx = 0, mx_idx = 0;
		for (int i = 0; i < 9 && break_idx+i < n; i++) {
			int true_val = (s[break_idx+i] - '0') - i;
			true_val = (true_val <= 0) ? 0 : true_val;
			if (true_val > mx) {
				mx = true_val;
				mx_idx = i;
			}
		}
		for (int i = mx_idx; i > 0; i--) 
			s[break_idx+i] = s[break_idx+i-1];
		s[break_idx] = mx + '0';
		break_idx++;
	}

	cout << s << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while (t--) solve();

	return 0;
}
