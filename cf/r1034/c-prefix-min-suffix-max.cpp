#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n; cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];

	int pmin = 1e9;
	string p = "";
	for (int i = 0; i < n; i++) {
		if (v[i] < pmin) {
			pmin = v[i];
			p += "1";
		} else {
			p += "0";
		}
	}
	int smax = 0;
	string s(n, '0'); 
	for (int i = n-1; i >= 0; i--) {
		if (v[i] > smax) {
			smax = v[i];
			s[i] = '1';
		} else {
			s[i] = '0';
		}
	}
	for (int i = 0; i < n; i++) {
		if (p[i] == '1' || s[i] == '1') cout << 1;
		else cout << 0;
	}
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while (t--) solve();

	return 0;
}
