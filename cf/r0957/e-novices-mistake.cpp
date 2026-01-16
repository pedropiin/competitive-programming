#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int num_digits(int n) {
	int ans = 0;
	while (n > 0) {
		ans++;
		n/=10;
	}
	return ans;
}

void solve() {
	int n; cin >> n;
	string nstr = to_string(n);
	int nlen = nstr.length();

	int minb, maxb;
	vector<pair<int,int>> ans;
	for (int a = 1; a <= 10000; a++) {
		minb = max(1, nlen*a-6);
		maxb = max(1, nlen*a-1);
		for (int b = minb; b <= maxb; b++) {
			int x = n*a-b; if (x<= 0) continue;
			int xlen = num_digits(x);
			ll y = 0;
			int ylen = nlen*a-b;
			if (xlen != ylen) continue;
			for (int i = 0; i < ylen; i++) {
				y = y*10 + (nstr[i%nlen]-'0');
			}
			if (x == y) ans.push_back({a, b});
		}
	}

	cout << ans.size() << endl;
	for (auto p : ans) cout << p.first << " " << p.second << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while (t--) solve();

	return 0;
}

