#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n;
	cin >> n;
	int zero_cnt = 0, neg_cnt = 0;
	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (temp == 0) zero_cnt++;
		else if (temp == -1) neg_cnt++;
	}
	int ans = zero_cnt;
	if (neg_cnt > 0 && neg_cnt % 2 != 0) {
		cout << ans + 2 << endl;
	} else {
		cout << ans << endl;
	}
}

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
