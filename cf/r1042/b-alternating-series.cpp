#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n;
	cin >> n;

	vector<int> ans(n, 0);
	if (n % 2 == 0) ans[n-1] = 2;
	else ans[n-1] = -1;
	for (int i = 0; i < n-1; i++) {
		if (i % 2 == 0) ans[i] = -1;
		else ans[i] = 3;
	}

	for (int val : ans) cout << val << " ";
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
