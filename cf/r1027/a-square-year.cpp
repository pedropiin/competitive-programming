#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> powers(101, 0);

void solve() {
	string s;
	cin >> s;
	int val = stoi(s);

	int l = 0, r = 100;
	while (l <= r) {
		int m = l + (r-l)/2;
		if (powers[m] == val) {
			int div = m/2;
			if (m % 2 == 0) cout << div << " " << div << endl;
			else cout << div << " " << div + 1 << endl;
			return;
		} else if (powers[m] > val) {
			r = m-1;
		} else {
			l = m+1;
		}
	}
	cout << -1 << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int i = 1; i <= 100; i++) {
		powers[i] = (i * i);
	}

	int t; cin >> t;
	while(t--) solve();

	return 0;
}
