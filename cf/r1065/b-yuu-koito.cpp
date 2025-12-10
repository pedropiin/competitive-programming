#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n; cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];

	if (v[0] == -1) {
		if (v[n-1] == -1) {
			v[0] = 0; v[n-1] = 0;
		} else v[0] = v[n-1];
	}
	if (v[n-1] == -1) v[n-1] = v[0];
	
	cout << abs(v[n-1] - v[0]) << endl;
	for (int i = 0; i < n; i++) {
		if (v[i] == -1) v[i] = 0;
		cout << v[i] << " ";
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
