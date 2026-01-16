#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n, m, k; cin >> n >> m >> k;	
	vector<int> ans;
	for (int i = n; i > m; i--) ans.push_back(i);
	for (int i = 1; i <= m; i++) ans.push_back(i);

	for (int i = 0; i < n; i++) cout << ans[i] << " ";
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

