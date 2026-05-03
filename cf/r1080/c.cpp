#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n; cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];

	int ans = 0, flag = 0;
	vector<int> idx;
	for (int i = 0; i < n-1; i++) {
		if (flag == 0) {
			if (v[i+1] == v[i] || v[i+1] == 7-v[i]) {
				flag = 1;
			}
		} else {
			ans++;
			flag = 0;
		}
	}
	if (flag == 1) ans++;
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

