#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n; cin >> n;
	vector<int> v;
	int t; int true_n = 0;
	cin >> t; v.push_back(t); true_n++;
	for (int i = 1; i < n; i++) {
		cin >> t;
		if (t != v[true_n-1]) {
			v.push_back(t);
			true_n++;
		}
	} 

	vector<int> rm(true_n, 0);
	int ans = 1;
	for (int i = 1; i < true_n; i++) {
		if (rm[i-1]) {
			if (v[i] == v[i-1]) rm[i] = 1;
			else ans++;
		} else {
			if (v[i] > v[i-1]+1) ans++;
			else rm[i] = 1;
		}
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
