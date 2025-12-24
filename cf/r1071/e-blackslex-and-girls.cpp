#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
void solve() {
	int n, x, y; cin >> n >> x >> y;
	string s; cin >> s;
	vector<int> p(n); ll psum = 0;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		psum += p[i];
	}
	if (psum > x + y) {
		cout << "NO" << endl;
		return;
	} 
 
	if (s == string(n, '0')) {
		if (x < y+n) {
			cout << "NO" << endl;
			return;
		}
 
		ll xneed = 0;
		for (int i = 0; i < n; i++) xneed += p[i]/2 + 1;
		if (xneed > x) cout << "NO" << endl;
		else cout << "YES" << endl;
		return;
	} else if (s == string(n, '1')) {
		if (y < x+n) {
			cout << "NO" << endl;
			return;
		}
 
		ll yneed = 0;
		for (int i = 0; i < n; i++) yneed += p[i]/2 + 1;
		if (yneed > y) cout << "NO" << endl;
		else cout << "YES" << endl;
		return;
	}
 
	ll xneed = 0;
	ll yneed = 0;
	for (int i = 0; i < n; i++) {
		(s[i] == '0') ? (xneed += p[i]/2 + 1) : (yneed += p[i]/2 + 1);
	}
 
	if (xneed > x || yneed > y) cout << "NO" << endl;
	else cout << "YES" << endl;
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 
	int t; cin >> t;
	while (t--) solve();
 
	return 0;
}
