#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n; cin >> n;
	string s; cin >> s;
	int r = sqrt(n); double r2 = (double)sqrt((double)n);
	if (r2 > r) {
		cout << "NO" << endl;
		return;
	}

	vector<vector<char>> v(r, vector<char>(r));
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < r; j++) {
			v[i][j] = s[i*r +j];
			if (i == 0 || i == r-1 || j == 0 || j == r-1) {
				if (s[i*r+j] == '0') {
					cout << "NO" << endl;
					return;
				}
			} else {
				if (s[i*r+j] == '1') {
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

