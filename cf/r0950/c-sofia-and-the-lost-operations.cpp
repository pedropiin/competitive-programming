#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n; cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	int m; cin >> m;
	vector<int> d(m);
	for (int i = 0; i < m; i++) {
		cin >> d[i];
	}

	if (b.size() == 1) {
		cout << ((b[0] == d[m-1]) ? "YES" : "NO") << endl; 
		return;
	}

	multiset<int> diffs;
	multiset<int> adjusted;
	for (int i = 0; i < n; i++) {
		if (a[i] != b[i]) diffs.insert(b[i]);
		else adjusted.insert(b[i]);
	}
	multiset<int>::iterator it;
	int i = 0;
	for (i = 0; i < m; i++) {
		if (diffs.empty()) break;

		it = diffs.find(d[i]);
		if (it != diffs.end()) {
			diffs.erase(it);
			adjusted.insert(d[i]);
		}	
	}

	if (!diffs.empty()) {
		cout << "NO" << endl;
		return;
	} else {
		for (int t = m-1; t >= i; t--) {
			if (adjusted.find(d[t]) != adjusted.end()) break;
			else {
				cout << "NO" << endl; return;
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

