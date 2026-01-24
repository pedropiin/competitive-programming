#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	string a, b;
	cin >> a >> b;
	if (b.length() > a.length()) swap(a, b);

	int alen = a.length();
	int blen = b.length();

	vector<int> lps(blen, 0);
	int len = 0, i = 1;
	while (i < blen) {
		if (b[i] == b[len]) {
			len++;
			lps[i] = len;
			i++;
		} else {
			if (len == 0) i++;
			else {
				while (len > 0 && b[i] != b[len]) len = lps[len-1];
			}
		}
	}

	vector<int> bdivs;
	bdivs.push_back(blen);
	i = blen-1;
	while (i > 0 && lps[i] > 0) {
		if (blen % lps[i] == 0) bdivs.push_back(lps[i]);
		i = lps[i-1];
	}

	int furthest = -1;
	for (int i = 0; i < bdivs.size(); i++) {
		int divlen = bdivs[i];
		int t = alen % divlen;
		if (t == 0) {
			string divisor = b.substr(0, divlen);
			for (int i = 0; i < alen; i++) {
				if (a[i] != divisor[i%divlen]) {
					cout << 0 << endl; 
					return;
				}
			}
			furthest = i;
			break;
		} 
	}
	if (furthest == -1) {
		cout << 0 << endl;
		return;
	}

	int ans = 0;
	for (int i = furthest; i < bdivs.size(); i++) {
		if (blen % bdivs[i] == 0 && alen % bdivs[i] == 0) ans++;
	}
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

