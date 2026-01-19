#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n, x; cin >> n >> x;
	vector<int> a(n), asorted(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		asorted[i] = a[i];
	} 

	sort(asorted.begin(), asorted.end());
	unordered_map<int, unordered_set<int>> valid_pos;
	int curr;
	for (int i = 0; i < n; i++) {
		curr = asorted[i];
		valid_pos[curr].insert(i);
	}

	for (int i = 0; i < n; i++) {
		curr = a[i];
		if (valid_pos[curr].find(i) == valid_pos[curr].end()) {
			if (i + x > n-1 && i - x < 0) {
				cout << "NO" << endl;
				return;
			} else {
				int flag = 0;
				for (int pos : valid_pos[curr]) {
					if ((pos >= 0 && pos <= n-x-1) || (pos >= x && pos <= n-1)) {
						flag = 1; break;
					}
				}
				if (!flag) {
					cout << "NO" << endl;
					return;
				}
			}
		}
	}
	cout << "YES" << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while (t--) solve();

	return 0;
}

