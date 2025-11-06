#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int k, x;
	cin >> k >> x;

	for (int i = 0; i < k; i++) {
		if (x % 2 == 0 && x % 3 == 1) x = x / 3;
		else x = 2 * x;
	}
	cout << x << endl;
}

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
