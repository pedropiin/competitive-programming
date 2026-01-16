#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n, k; cin >> n >> k;
	vector<int> v(k);
	for (int i = 0; i < k; i++) cin >> v[i];
	sort(v.begin(), v.end());
	
	int ans = 0;
	for (int i = 0; i < k-1; i++) {
		if (v[i] == 1) ans += 1;
		else ans += (v[i]-1) + v[i];
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

