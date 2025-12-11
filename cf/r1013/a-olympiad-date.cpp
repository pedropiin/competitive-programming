#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n; cin >> n;
	int digits[6] = {3, 1, 2, 1, 0, 1};

	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];

	for (int i = 0; i < n; i++) {
		if (v[i]>= 0 && v[i] <= 5) digits[v[i]]--;
		int done = 1;
		for (int j = 0; j < 6; j++) {
			if (digits[j] > 0) {
				done = 0;
				break;
			}
		}
		if (done) {
			cout << i+1 << endl;
			return;
		}
	}
	cout << 0 << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while (t--) solve();

	return 0;
}
