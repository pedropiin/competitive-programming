#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string txt; cin >> txt;
	string pat; cin >> pat;
	int n = txt.length();
	int m = pat.length();

	vector<int> lps(m, 0);
	int len = 0;
	int i = 1;
	while (i < m) {
		if (pat[i] == pat[len]) {
			lps[i] = ++len;
			i++;
		} else {
			if (len == 0) {
				lps[i] = 0;
				i++;
			} else {
				while (len > 0 && pat[i] != pat[len]) len = lps[len-1];
				if (pat[i] == pat[len]) len++;
				lps[i] = len;
				i++;
			}
		}
	}

	i = 0;
	int j = 0;
	ll ans = 0;
	while (i < n) {
		if (txt[i] == pat[j]) {
			i++; j++;
			if (j == m) {
				ans++;
				j = lps[j-1];
			}
		} else {
			if (j == 0) i++;
			else j = lps[j-1];
		}
	}

	cout << ans << endl;

	return 0;
}
