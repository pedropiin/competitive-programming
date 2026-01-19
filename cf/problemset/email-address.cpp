#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	string s; cin >> s;
	int n = s.length();

	string dot = "dot", at = "at";
	unordered_set<int> dot_idxs;
	int normal_at = -1, at_idx = -1;
	for (int i = 1; i < n; i++) {
		if (s[i] == '@') {
			normal_at = i; continue;
		} 
		if (s[i] == 'd' && i+2 < n-1 && s[i+1] == 'o' && s[i+2] == 't') {
			dot_idxs.insert(i);
			i += 2;
			continue;
		}
		if (s[i] == 'a' && i+1 < n && s[i+1] == 't' && normal_at == -1 && at_idx == -1) {
			at_idx = i;
			i += 1;
			continue;
		}
	}

	for (int i = 0; i < n; i++) {
		if (dot_idxs.find(i) != dot_idxs.end()) {
			cout << '.';
			i += 2;
		} else if (i == at_idx && normal_at == -1) {
			cout << '@';
			i += 1;
		} else {
			cout << s[i];
		}
	}
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	while (t--) solve();

	return 0;
}

