#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(int c) {
	int n; cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];

	for (int i = 1; i < n/2; i++) {
		if (v[i] == v[i-1] || v[n-1-i] == v[n-i]) swap(v[i], v[n-1-i]);
	}	
	int ans = 0;
	for (int i = 0; i < n-1; i++) {
		if (v[i] == v[i+1]) ans++;
	}

	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	int cnt = 1;
	while (t--) solve(cnt++);

	return 0;
}

