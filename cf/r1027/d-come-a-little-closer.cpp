#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct point {
	int r;
	int c;
};

ll area(int upmost_row, int leftmost_col, int downmost_row, int rightmost_col) {
	return (ll)(downmost_row - upmost_row + 1) * (ll)(rightmost_col - leftmost_col + 1);
}

void solve() {
	int n; cin >> n;

	vector<struct point> v(n);
	multiset<int> mt_r, mt_c;
	int r, c;
	for (int i = 0; i < n; i++) {
		cin >> r >> c;
		struct point m = {r, c};
		v[i] = m;
		mt_r.insert(v[i].r);
		mt_c.insert(v[i].c);
	}

	if (n == 1) {
		cout << 1 << endl;
		return;
	}

	ll ans = area(*mt_r.begin(), *mt_c.begin(), *mt_r.rbegin(), *mt_c.rbegin());
	for (struct point p : v) {
		mt_r.erase(mt_r.find(p.r));
		mt_c.erase(mt_c.find(p.c));

		int upmost_row = *mt_r.begin();
		int leftmost_col = *mt_c.begin();
		int downmost_row = *mt_r.rbegin();
		int rightmost_col = *mt_c.rbegin();
		ll it_area = area(upmost_row, leftmost_col, downmost_row, rightmost_col);

		if (it_area != n-1) ans = min(ans, it_area);
		else {
			int row_diff = downmost_row - upmost_row + 1;
			int col_diff = rightmost_col - leftmost_col + 1;
			ans = min(ans, (ll)min(row_diff, col_diff) * (ll)(max(row_diff, col_diff) + 1));
		}

		mt_r.insert(p.r);
		mt_c.insert(p.c);
	}

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
