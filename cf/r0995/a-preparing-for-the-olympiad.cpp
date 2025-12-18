#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n; cin >> n;
	vector<int> a(n); 
	for (int i = 0; i < n; i++) cin >> a[i];
	vector<int> b(n);
	int t; cin >> t;
	for (int i = 0; i < n-1; i++) cin >> b[i];
	b[n-1] = 0;
	
	int m = 0, s = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > b[i]) {
			m += a[i];
			s += b[i];
		}
	}

	cout << m - s << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while (t--) solve();

	return 0;
}
