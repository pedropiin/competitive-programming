#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	string a, b;
	cin >> a >> b;

	cout << fixed << setprecision(14) << endl;

	int og_pos = 0, curr_pos = 0;
	int n = 0;
	for (int i = 0; i < a.length(); i++) {
		if (a[i] == '+') og_pos++;
		else og_pos--;

		if (b[i] == '+') curr_pos++;
		else if (b[i] == '-') curr_pos--;
		else n++;
	}

	int s = abs(og_pos - curr_pos);
	int delta = n - s;
	if (s > n || delta % 2 == 1) {
		cout << (double)0.0 << endl;
		return;
	}

	double tot = (1 << n);
	if (delta == 0) {
		cout << (double)1/tot << endl; return;
	}

	vector<vector<int>> comb(n+1, vector<int>(n+1, 0));
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (j > i) comb[i][j] = 0;
			else if (j == 0 || i == j) comb[i][j] = 1;
			else comb[i][j] = comb[i-1][j] + comb[i-1][j-1];
		}
	}

	double ans = (1/tot) * comb[n][delta/2];
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	while (t--) solve();

	return 0;
}

