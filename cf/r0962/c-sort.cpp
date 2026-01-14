#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n, q; cin >> n >> q;
	string a, b; cin >> a >> b;

	vector<vector<int>> apref(26, vector<int>(n+1, 0));
	vector<vector<int>> bpref(26, vector<int>(n+1, 0));

	for (int i = 0; i < n; i++) {
		int acurr = a[i] - 'a';
		int bcurr = b[i] - 'a';
		for (int j = 0; j < 26; j++) {
			apref[j][i+1] = apref[j][i] + (acurr == j);
			bpref[j][i+1] = bpref[j][i] + (bcurr == j);
		}
	}

	int l, r, ans;
	while (q--) {
		cin >> l >> r; l--; 
		ans = 0;
		for (int i = 0; i < 26; i++) {
			ans += abs((apref[i][r] - apref[i][l]) - (bpref[i][r] - bpref[i][l]));
		}
		cout << ans/2 + ans%2 << endl;
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

