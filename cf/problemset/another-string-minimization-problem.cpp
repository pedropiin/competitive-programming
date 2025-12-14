#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n, m; cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	string s(m, 'B');
	for (int i = 0; i < n; i++) {
		int t1 = a[i];
		int t2 = m + 1 - a[i];
		if (t1 <= t2) 
			(s[t1-1] == 'B') ? s[t1-1] = 'A' : s[t2-1] = 'A';
		else 
			(s[t2-1] == 'B') ? s[t2-1] = 'A' : s[t1-1] = 'A';
	}	

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
