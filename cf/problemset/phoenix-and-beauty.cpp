#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n, k; cin >> n >> k;
	vector<int> v(n);
	set<int> cnt;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		cnt.insert(v[i]);
	}

	if (k >= n) {
		cout << n << endl;
		for (int elem : v) cout << elem << " ";
		cout << endl;
		return;
	} 
	int delta = k - cnt.size();
	if (delta < 0) {
		cout << -1 << endl;
		return;
	}
	
	vector<int> cp;
	for (auto elem : cnt) cp.push_back(elem);
	for (int i = 0; i < delta; i++) cp.push_back(1);

	cout << n*k << endl;
	for (int i = 0; i < n; i++) {
		for (int elem : cp) cout << elem << " ";
	}
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while (t--) solve();

	return 0;
}

