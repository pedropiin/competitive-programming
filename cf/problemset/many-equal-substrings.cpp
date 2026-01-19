#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n, k; cin >> n >> k;
	string s; cin >> s;

	vector<int> lps(n, 0);
	int len = 0, i = 1;
	while (i < n) {
		if (s[len] == s[i]) {
			len++;
			lps[i] = len;
			i++;
		} else {
			if (len == 0) {
				lps[i] = 0;
				i++;
			} else {
				while (s[len] != s[i] && len > 0) {
					len = lps[len-1];
				}
			}
		}
	}

	string prefix = s.substr(0, n-lps[n-1]);
	for (int i = 0; i < k-1; i++) cout << prefix;
	cout << s << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	while (t--) solve();

	return 0;
}

