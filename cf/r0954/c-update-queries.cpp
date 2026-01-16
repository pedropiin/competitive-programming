#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n, m; cin >> n >> m;
	string s; cin >> s;
	vector<int> idxs(m);
	for (int i = 0; i < m; i++) cin >> idxs[i];
	string c; cin >> c;

	sort(idxs.begin(), idxs.end());
	vector<int> freq_alpha(26, 0);
	for (int i = 0; i < m; i++) freq_alpha[c[i]-'a']++;

	string new_c(m, '.');
	for (int i = 0; i < m-1; i++) {
		if (idxs[i] == idxs[i+1]) {
			for (int j = 25; j >= 0; j--) {
				if (freq_alpha[j] > 0) {
					new_c[i] = j+'a';
					freq_alpha[j]--;
					break;
				}
			}
		} else {
			for (int j = 0; j < 26; j++) {
				if (freq_alpha[j] > 0) {
					new_c[i] = j+'a';
					freq_alpha[j]--;
					break;
				}
			}
		}
	}
	for (int j = 0; j < 26; j++) {
		if (freq_alpha[j] > 0) {
			new_c[m-1] = j+'a';
			break;
		}
	}

	for (int i = 0; i < m; i++) s[idxs[i]-1] = new_c[i];

	cout << s << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while (t--) solve();

	return 0;
}

