#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n; cin >> n;
	vector<int> v(n);
	int flag = 1;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		if (v[i] == i+1) continue;

		int t = i+1;
		int found = 0;
		if (v[i] > t) {
			while (t < v[i]) {
				t <<= 1;
				if (v[i] == t) {
					found = 1;
					break;
				}
			}
			if (!found) flag = 0;
		} else {
			while (t > 0) {
				t >>= 1;
				if (v[i] == t) {
					found = 1;
					break;
				}
			}
			if (!found) flag = 0;
		}
	}

	cout << (flag == 1 ? "YES" : "NO") << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while (t--) solve();

	return 0;
}

