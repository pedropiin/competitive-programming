#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n, s, x; cin >> n >> s >> x;
	vector<int> a(n); 
	int sm = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sm += a[i];
	}
	
	if (sm <= s && (sm-s) % x == 0) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
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

