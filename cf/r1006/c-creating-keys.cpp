#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n, x; cin >> n >> x;

	if (n == 1) {
		cout << x << endl;
		return;
	}

	vector<int> ans = {0};
	int ans_or = 0;

	for (int i = 1; i <= x; i++) {
		if (ans.size() >= n)	break;

		if (i == ans.back() + 1 && ((i & x) == i)) {
			ans.push_back(i);
			ans_or = ans_or | i;
		} else break;
	}

	if (ans.size() == n) {
		if (ans_or != x) ans[n - 1] = x; 
	} else {
		while (ans.size() < n) ans.push_back(x);
	}


	for (int elem : ans) 
		cout << elem << " ";
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
