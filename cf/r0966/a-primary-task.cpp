#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int t; cin >> t;
	while (t--) {
		string a; cin >> a;
		if (a.length() < 3) {
			cout << "NO" << endl; continue;
		}
		if (a[0] != '1' || a[1] != '0') {
			cout << "NO" << endl; continue;
		}

		int val = 0;
		int lead_zero = 0, first_nz = 0;
		for (int i = 2; i < a.length(); i++) {
			if (a[i] == '0' && !first_nz) {
				lead_zero = 1; break;
			} else if (a[i] != '0') first_nz = 1;
			val += a[i] - '0';
			val *= 10;	
		}
		val /= 10;
		
		if (val <= 1 || lead_zero) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	while (t--) solve();

	return 0;
}
