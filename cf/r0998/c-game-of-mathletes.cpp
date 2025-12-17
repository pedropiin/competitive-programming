#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n, k; cin >> n >> k;
	vector<int> v(n);
	map<int, int> m;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		m[v[i]]++;
	}

	int ans = 0;
	for (int num : v) {
		if (m[num] <= 0) continue;
		m[num]--;
		if (m[k-num] > 0) {
			m[k-num]--;
			ans++;
		} 
	}
	
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while (t--) solve();

	return 0;
}
